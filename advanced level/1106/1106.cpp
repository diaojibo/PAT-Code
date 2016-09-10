#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100001
int n,m,sl=0,minlevel = -1,mins=0;
double p,r;
int target[N*2];
int nex[N*2];
bool flag[N];
int s[N];
void dfs(int p,int level){
	flag[p] = true;
	if(s[p]==-1){
		if(minlevel==-1||level<=minlevel){
			if(minlevel==level){
				mins++;
			}else{
				mins = 1;
				minlevel = level;
			}
		}
		return;
	}
	int np = s[p];
	while(np!=-1){
		int now = target[np];
		if(!flag[now]){
			dfs(now,level+1);
		}
		np = nex[np];
	}
}

int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++) s[i] = -1,flag[i]=false;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			if(y==0) continue;
			nex[sl] = s[i];target[sl]=y;
			s[i] = sl;sl++;
		}
	}
	dfs(0,0);
	double final_r=1;
	for(int i=0;i<minlevel;i++){
		final_r = (1+r/100)*final_r;
	}
	printf("%.4f %d",p*final_r+0.0000000001,mins);
	cin>>n;
}