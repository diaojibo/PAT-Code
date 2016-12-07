#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
#define N 1002
bool m[N][N];
int n,mm,k,p;
queue<int> a,level;
bool flag[N];
int forward(int p){
	int ans=0;
	for(int i=1;i<=n;i++) flag[i] = false;
	flag[p] = true;
	a.push(p);
	level.push(0);
	while(!a.empty()){
		int nlev = level.front();
		level.pop();
		int now = a.front();a.pop();
		if(nlev==mm) continue;
		for(int i=1;i<=n;i++){
			if(!flag[i]&&m[now][i]){
				flag[i] = true;
				ans++;
				a.push(i);
				level.push(nlev+1);
			}
		}
	}
	return ans;
}

int main(){
	scanf("%d %d",&n,&mm);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++) m[i][j] = false;
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			scanf("%d",&y);
			m[y][i] = true;
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		int ans = forward(x);
		printf("%d\n",ans);
	}
} 
