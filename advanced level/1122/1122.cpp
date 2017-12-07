#include<stdio.h>
#include<vector>
using namespace std;

#define N 201

int n,e;
int graph[N][N];
vector<int> path;

bool judgePath(vector<int>& a){
	int l = a.size();
	if(l!=n+1) return false;
	if(l<=1) return true;
	//for(int i=0;i<l;i++) printf("%d ",a[i]);
	//printf("\n");
	bool flag[N];
	for(int i=0;i<N;i++) flag[i] = false;
	bool isCycle = true;
	if(a[0]!=a[l-1]) return false;
	flag[a[0]] = true;
	for(int i=1;i<l;i++){
		if(i<l-1 && flag[a[i]]) return false;
		int v1,v2;
		v1 = a[i-1];v2=a[i];
		if(graph[v1][v2]==0) return false;
		flag[v2] = true;
	}
	
	return true;
}

int main(){
	scanf("%d %d",&n,&e);
	for(int i=0;i<e;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x;
		scanf("%d",&x);
		path.clear();
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			path.push_back(y);
		}
		bool isH = judgePath(path);
		if(isH){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	
}
