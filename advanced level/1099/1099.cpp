#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define N 101
vector<int> a;
int ln[N],rn[N];
int v[N];
int n,m;
queue<int> q;
vector<int> ans;
int an=0;
bool mycompare(int x,int y){
	return x<y;
}
void dfs(int p){
	if(ln[p]!=-1){
		dfs(ln[p]);
	}
	an++;v[p]=a[an-1];
	if(rn[p]!=-1){
		dfs(rn[p]);
	}
}
void bfs(){
	int root = 0;
	q.push(root);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans.push_back(v[x]);
		if(ln[x]!=-1) q.push(ln[x]);
		if(rn[x]!=-1) q.push(rn[x]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ln[i] = x;
		rn[i] = y;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),mycompare);
	dfs(0);
	bfs();
	for(int i=0;i<n-1;i++){
		printf("%d ",ans[i]);
	}
	if(n>0) printf("%d",ans[n-1]);
} 
