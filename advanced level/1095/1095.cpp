#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
struct rec1{
	bool state;
	int time;
	string pn;
};
int n,m,k;
map<string,int> rin,rout;
map<string,int> rtime;
vector<rec1> a,vi,vo;
vector<string> fv;
char temp[10],temp2[5];
int longest=-1;
int gpi=0,gpo=0;//global variable for in and out
int vil,vol;
int lefts[24*60*60+1];
bool mycmp(rec1 x,rec1 y){
	return x.time<y.time;
}
bool mycmp2(string x,string y){
	return x<y;
}

int go_out(int ptime){
	if(gpo>=vol) return 0;
	int people = 0;
	while(gpo<vol){
		if(vo[gpo].time!=ptime) return people;
		people++;gpo++;
	}
	return people;
}
int go_in(int ptime){
	if(gpi>=vil) return 0;
	int people = 0;
	while(gpi<vil){
		if(vi[gpi].time!=ptime) return people;
		people++;gpi++;
	}
	return people;
}


int main(){
	scanf("%d %d",&n,&k);
	
	for(int i=0;i<n;i++){
		int hh,mm,ss;
		scanf("%s %d:%d:%d %s",&temp,&hh,&mm,&ss,&temp2);
		int t = hh*60*60+mm*60+ss;
		rec1 r;
		string st;
		st = string(temp);
		rin[st] = -1;rout[st]=-1;rtime[st] = 0;
		if(temp2[0]=='i'){
			r.state = true;
			r.time = t;
			r.pn = st;
			a.push_back(r);
		}else{
			r.state = false;
			r.time = t;
			r.pn = st;
			a.push_back(r);
		}
	}
	sort(a.begin(),a.end(),mycmp);
	for(int i=0;i<n;i++){
		string xs = a[i].pn;
		rec1 tr;
		if(a[i].state){
			rin[xs]=a[i].time;
		}else{
			if(rin[xs]!=-1){
				tr.state = true;tr.time = rin[xs];tr.pn=xs;
				vi.push_back(tr);
				tr.state = false;tr.time = a[i].time;
				vo.push_back(tr);
				rtime[xs] += (a[i].time-rin[xs]);
				if(rtime[xs]>=longest){
					if(rtime[xs]==longest){
						fv.push_back(xs);
					}else{
						longest = rtime[xs];
						fv.clear();
						fv.push_back(xs);
					}
				}
				rin[xs] = -1;
			}
		}
	}
	sort(vi.begin(),vi.end(),mycmp);
	sort(vo.begin(),vo.end(),mycmp);
	vil = vi.size();vol=vo.size();//global variable
//	for(int i=0;i<vil;i++){
//		//cout<<vi[i].pn<<" "<<vi[i].time<<" "<<vo[i].time<<endl;
//		int ii = vi[i].time,oo = vo[i].time;
//		printf("%s %02d:%02d:%02d %02d:%02d:%02d\n",vi[i].pn.c_str(),ii/60/60,(ii/60)%60,ii%60,oo/60/60,(oo/60)%60,oo%60);
//	}
	int maxt = 24*60*60;
	int now = 0;
	for(int i=0;i<maxt;i++){
		int leave = go_out(i);
		int increase = go_in(i);
		now = now + increase - leave;
		//if(now==7) cout<<"show: "<<i<<endl;
		lefts[i] = now;
		//if(i==23*60*60+59*60) cout<<"show: "<<now<<endl;
	}
	for(int i=0;i<k;i++){
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		printf("%d\n",lefts[hh*60*60+mm*60+ss]);
	}
	sort(fv.begin(),fv.end(),mycmp2);
	int l = fv.size();
	for(int i=0;i<l;i++){
		printf("%s ",fv[i].c_str());
	}
	int ss = longest%60;
	longest = longest / 60;
	int mm = longest % 60;
	int hh = longest / 60;
	printf("%02d:%02d:%02d",hh,mm,ss);
}
