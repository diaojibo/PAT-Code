#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<iomanip>
using namespace std;
#define N 10001
#define K 101
int n,k;
int waiting[N];

struct wins{
	bool status;
	int lt;
	int person;
};
struct per{
	int at;
	int pt;
};
wins w[K];
vector<per> pp;
void go_out(){
	for(int i=0;i<k;i++){
		if(w[i].status){
			w[i].lt--;
			if(w[i].lt==0){
				w[i].status = false;
			}
		}
	}
}

void go_in(int& np,int time){
	bool flag = false;
	while(np<n){
		if(time<pp[np].at) break;
		if(pp[np].at>17*60*60){
		np = n;
		return;
	    }
		flag = false;
		for(int i=0;i<k;i++){
			if(!w[i].status){
				w[i].status = true;
				w[i].person = np;
				w[i].lt = pp[np].pt*60;
				waiting[np] = time - pp[np].at;
				//cout<<pp[np].at<<" w "<<i<<endl;
				flag = true;
				break;
			}
		}
		if(!flag) break;
		np++;
	}
}

bool mycom(per x,per y){
	return x.at<y.at;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x,y,z;
		per tp;
		pp.push_back(tp);
		scanf("%d:%d:%d %d",&x,&y,&z,&pp[i].pt);
		pp[i].at = (x*60*60+y*60+z);
		//cout<<x<<" "<<y<<" "<<z<<endl;
		waiting[i]=-100;
	}
	sort(pp.begin(),pp.end(),mycom);
	int p=0;
	int init_time = 8*60*60;
	for(int i=0;i<k;i++) w[i].status = false;
	int t = 0;
	while(true){
		go_out();
		go_in(p,t+init_time);
		if(p>=n) break;
		t++;
	}
	double avg = 0;
	int tol=0;
	for(int i=0;i<n;i++){
		if(waiting[i]>=0){
			tol++;
			avg+=waiting[i];
		}
	}
	if(tol>0){
		printf("%.1f",avg/60/tol+0.000001);
	}else cout<<"0.0";
}
