#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
#define N 102

vector<int> p[N];
int n,m,k;
int people[N];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,nn;
		scanf("%d %d",&x,&nn);
		for(int j=0;j<nn;j++){
			int t;
			scanf("%d",&t);
			p[x].push_back(t);
		}
	}
	int root = 1;
	for(int i=0;i<n;i++) people[i] = 0;
	queue<int> q,qlevel;
	q.push(root);qlevel.push(1);
	int answer=0,maxlevel=0;
	while(!q.empty()){
		int x = q.front();
		//int nl = qlevel.front();
		int ll = qlevel.front();
		people[ll]++;
		if(people[ll]>answer){
			answer = people[ll];
			maxlevel = ll;
		}
		int l = p[x].size();
		for(int i=0;i<l;i++){
			q.push(p[x][i]);
			qlevel.push(ll+1);
		}
		q.pop();qlevel.pop();
	}
	printf("%d %d",answer,maxlevel);
}
