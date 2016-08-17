#include<vector>
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;
#define N 32
#define M 22
#define K 2002
#define Q 2002
#define tl 540

struct window{
	int people[M];
	int cap;
	int deal;
};

int n,m,k,q;
int p_time[K];
window windows[N];
int queries[Q];
string ans[K];

string its(int stime){
	int h,tm;
	char temph[10],tempm[10];
	h = stime / 60+8;
	if(h<10) sprintf(temph,"0%d",h);
	else sprintf(temph,"%d",h);
	tm = stime % 60;
	if(tm<10) sprintf(tempm,"0%d",tm);
	else sprintf(tempm,"%d",tm);
	return string(temph)+":"+string(tempm);
}

void go_out(int now){
	for(int i=0;i<n;i++){
		int num = windows[i].cap;
		if(num>0){
			windows[i].deal--;
			if(windows[i].deal==0){
				int x = windows[i].people[0];
				ans[x] = its(now);
				//cout<<"out "<<x<<" "<<ans[x]<<endl;
				for(int z=1;z<num;z++) windows[i].people[z-1] = windows[i].people[z];
				windows[i].cap--;
				if(num>1) windows[i].deal = p_time[windows[i].people[0]];
			}
		}
	}
}

void enter_in(int& p){
	bool ifsucc = true;
	while(p<=k-1){
		ifsucc = false;
		int min=-1;
		for(int i=0;i<n;i++){
			if(windows[i].cap<m){
				if(min==-1||windows[i].cap<windows[min].cap){
					min = i;
				}
			}
		}
		//cout<<"p="<<p<<" "<<min<<endl;
		if(min!=-1){
			int num = windows[min].cap;
			if(num==0) windows[min].deal = p_time[p];
			windows[min].cap++;
			windows[min].people[num] = p;
			p++;
		}else break;
	}
}
void final_serve(){
	for(int i=0;i<n;i++){
		if(windows[i].cap>0){
			int x = windows[i].people[0];
			ans[x] = its(539+windows[i].deal);
		}
	}
}
int main(){
	cin>>n>>m>>k>>q;
	for(int i=0;i<k;i++) {
	   cin>>p_time[i];
	   ans[i] = "Sorry";
	}
	for(int i=0;i<q;i++) cin>>queries[i];
	for(int i=0;i<n;i++){
		windows[i].cap = 0;
	}
	int p = 0;
	enter_in(p);
	//for(int i=0;i<n;i++) cout<<"deal "<<windows[i].deal<<endl;
	for(int i=1;i<=tl-1;i++){
		go_out(i);
		enter_in(p);
	}
	final_serve();
	for(int i=0;i<q;i++){
		cout<<ans[queries[i]-1]<<endl;
	}
}
