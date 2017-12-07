#include<stdio.h>
#include<vector>
using namespace std;

#define N 100000

bool isCome[N];
int couple[N];
int n,m;

int main(){
	scanf("%d",&n);
	for(int i=0;i<N;i++){
		isCome[i] = false;
		couple[i] = -1;
	}
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		couple[x] = y;
		couple[y] = x;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		isCome[t] = true;
	}
	
	vector<int> ans;
	for(int i=0;i<N;i++){
		if(isCome[i]&&(couple[i]==-1||!isCome[couple[i]])) ans.push_back(i);
	}
	int l = ans.size();
	printf("%d\n",l);
	for(int i=0;i<l-1;i++) printf("%05d ",ans[i]);
	if(l>0) printf("%05d\n",ans[l-1]);
	
}
