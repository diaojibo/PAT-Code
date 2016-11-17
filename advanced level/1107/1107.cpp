#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1001
bool map[N][N];
vector<int> interest[N];
int n,m;
int c=0;
bool flag[N];
void dfs(int p){
	flag[p] = true;
	c++;
	for(int i=0;i<n;i++){
		if(map[p][i]&&!flag[i]){
			dfs(i);
		}
	}
}
bool mycmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d: ",&x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			interest[y].push_back(i);
		}
		flag[i] = false;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++) map[i][j] = false; 
	for(int i=0;i<N;i++){
		int l = interest[i].size();
		int source;
		if(l>0) source = interest[i][0];
		for(int j=1;j<l;j++){
			int t = interest[i][j];
			map[source][t] = map[t][source] = true;
		}
	}
	int num=0;
	vector<int> ans;
	for(int i=0;i<n;i++){
		if(!flag[i]){
			c=0;
			dfs(i);
			ans.push_back(c);
			num++;
		}
	}
	sort(ans.begin(),ans.end(),mycmp);
	printf("%d\n",num);
	for(int i=0;i<num-1;i++){
		printf("%d ",ans[i]);
	}
	if(num>0) printf("%d",ans[num-1]);
	//cin>>n;
}