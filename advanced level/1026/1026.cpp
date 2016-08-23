#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct per{
	int at;
	bool vip;
	int pt;
	bool over;
	int wt;
	int st;
};

struct table{
	int left;
	bool vip;
	int num;
};
vector<per> a,p;
queue<int> vipt,ordt;
table tab[200];
int n,m,k;
per temp;
int avip = 0,avat=0;
void go_out(){
	//avat = 0;avip=0;
	while(!vipt.empty()) vipt.pop();
	while(!ordt.empty()) ordt.pop();
	for(int i=1;i<=k;i++){
		if(tab[i].left>0) tab[i].left--;
		if(tab[i].left==0){
			if(tab[i].vip) vipt.push(i);
			else ordt.push(i);
		}
	}
}

void vip_go_in(int time){
	int ll = p.size();
	bool isc = false;
	if(vipt.empty()) return;
	while(!vipt.empty()){
		isc = false;
		for(int i=0;i<ll;i++){
			if(p[i].over) continue;
			if(p[i].at>time) break;
			if(p[i].vip){
				p[i].over = true;p[i].st=time;
				int q = vipt.front();
				vipt.pop();
				tab[q].left = p[i].pt;
				if(tab[q].left>60*60*2) tab[q].left = 60*60*2;
				tab[q].num++;
				//cout<<q<<" "<<i<<endl;
				isc = true;
				break;
			}
		}
		if(!isc) break;
	}
	if(vipt.empty()) return;
	queue<int> nq;
	while(!ordt.empty()&&!vipt.empty()){
		if(ordt.front()<vipt.front()){
			nq.push(ordt.front());
			ordt.pop();
		}else{
			nq.push(vipt.front());
			vipt.pop();
		}
	}
	while(!ordt.empty()) nq.push(ordt.front()),ordt.pop();
	while(!vipt.empty()) nq.push(vipt.front()),vipt.pop();
	ordt = nq;
	return;
}
bool mycmpi(int x,int y){
	return x<y;
}
void go_in(int time){
	int ll = p.size();
	if(ordt.size()==0) return;
	for(int i=0;i<ll;i++){
		if(p[i].over) continue;
		if(p[i].at>time) break;
		int q = ordt.front();ordt.pop();
		tab[q].left = p[i].pt;tab[q].num++;
		if(tab[q].left>60*60*2) tab[q].left = 60*60*2;
		p[i].over = true;p[i].st=time;
		//cout<<q<<" "<<i<<endl;
		if(ordt.size()==0) break;
	}
}

bool mycmp(per x,per y){
	return x.at<y.at;
}
bool mycmp2(per x,per y){
	if(!x.over) return false;
	if(!y.over) return true;
	if(x.st!=y.st) return x.st<y.st;
	return x.at<y.at;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int hh,mm,ss,pt,flag;
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&pt,&flag);
		temp.at = hh*60*60+mm*60+ss;
		temp.pt = pt*60;
		if(flag==1) temp.vip = true;
		else temp.vip = false;
		temp.over = false;
		p.push_back(temp);
	}
	cin>>k>>m;
	for(int i=1;i<=k;i++) tab[i].vip=false,tab[i].left=0,tab[i].num=0;
	for(int i=0;i<m;i++){
		int xx;
		cin>>xx;
		tab[xx].vip = true;
	}
	
	int end_time = 21*60*60;
	int begin_time = 8*60*60;
	sort(p.begin(),p.end(),mycmp);
	for(int i=begin_time;i<end_time;i++){
		go_out();
		vip_go_in(i);
		go_in(i);
	}
	sort(p.begin(),p.end(),mycmp2);
	int l = p.size();
	for(int i=0;i<l;i++){
		if(p[i].over){
			int hh,mm,ss;
			int xx,yy,zz;
			ss = p[i].at%60;mm=(p[i].at/60)%60;
			hh = p[i].at/60/60;
			zz = p[i].st%60;yy=(p[i].st/60)%60;
			xx = p[i].st/60/60;
			float w = p[i].st-p[i].at;
			float ww = w/60+0.00001;
			printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",hh,mm,ss,xx,yy,zz,ww,p[i].vip);
		}
	}
	bool first = true;
	for(int i=1;i<=k;i++){
		if(first) first = false,cout<<tab[i].num;
		else cout<<" "<<tab[i].num;
	}
} 
