#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int n,m,k,s;
int v[N];
vector<int> trees[N];
int gst[N],glen=0;

bool isVisited[N];
bool mycmp(int x,int y){
	return v[x]>v[y];
}
void dfs(int p,long vv){
	isVisited[p] = true;
	gst[glen]=p;glen++;
	long vn = vv+v[p];
	int l = trees[p].size();
	if(vn==s){
		if(l!=0) {
			glen--;
			return;
		}
		for(int i=0;i<glen-1;i++) printf("%d ",v[gst[i]]);
		if(glen>0) printf("%d\n",v[gst[glen-1]]);
		glen--;
		return;
	}
	sort(trees[p].begin(),trees[p].end(),mycmp);
	for(int i=0;i<l;i++){
		if(!isVisited[trees[p][i]]) dfs(trees[p][i],vn);
	}
	glen--;
}
int main(){
	scanf("%d %d %ld",&n,&m,&s);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=0;i<m;i++){
		int x,xn;
		scanf("%d %d",&x,&xn);
		for(int j=0;j<xn;j++){
			int xx;
			scanf("%d",&xx);
			trees[x].push_back(xx);
		}
		
	}
	int root = 0;
	for(int i=0;i<n;i++) isVisited[i] = false;
	dfs(0,0);
}
