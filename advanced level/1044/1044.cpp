#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100001
int a[N];
long long f[N];
int m,n;
bool isfind = false;
int ansx,ansy;
int mina = -1;
struct rec{
	int x;
	int y;
};

vector<rec> answer;

int find(int p,int x,int y){
	//cout<<x<<" y: "<<y<<endl;
	if(x>y) return x;
	if(x==y) return x;
	int mm;
	mm = (x+y)/2;
	int diff = f[mm]-f[p];
	if(diff==m) return mm;
	if(diff>m){
		return find(p,x,mm-1);
	}else{
		return find(p,mm+1,y);
	}
}

int main(){
	scanf("%d %d",&n,&m);
	f[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i] = f[i-1]+a[i];
	}

	for(int i=0;i<n;i++){
		int pf = find(i,i+1,n);
		//cout<<i+1<<" "<<pf<<endl;
		//cout<<pf<<endl;
		if(f[pf]-f[i]==m){
			isfind = true;
			printf("%d-%d\n",i+1,pf);
		}
	}
	if(!isfind){
		for(int i=0;i<n;i++){
		int pf = find(i,i+1,n);
		int diff = f[pf]-f[i];
		int diff2,t;
		t = pf;
		if(pf>0) diff2 = f[pf-1]-f[i];
		if(diff2>m) diff = diff2,t=pf-1;
		if(diff<m){
			if(pf<n) diff2 = f[pf+1]-f[i];
			if(diff2>m) diff = diff2,t=pf+1;
		} 
		if(diff>m){
			if(mina==-1 || diff-m<=mina){
				if(diff-m==mina){
					rec q;
					q.x = i+1;q.y = t;
					answer.push_back(q);
				}else{
					rec q;
					q.x = i+1;q.y = t;
					answer.clear();
					answer.push_back(q);
				}
				mina = diff - m;
			}
		}
	    }
	    int l = answer.size();
	    for(int i=0;i<l;i++){
	    	printf("%d-%d\n",answer[i].x,answer[i].y);
		}
	}
}
