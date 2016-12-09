#include<vector>
#include<stdio.h>
using namespace std;
#define N 1001
int m,n;
int a[N];
int ln[N],rn[N];

void build(int p,int x){
	if(a[x]<=a[p]){
		if(ln[p]==-1){
			ln[p] = x;
		}else build(ln[p],x);
	}else{
		if(rn[p]==-1){
			rn[p] = x;
		}else build(rn[p],x);
	}
}
int maxlevel = -1;
int c1=0,c2=0;
void dfs(int p,int level){
	if(maxlevel==-1||level>maxlevel){
		maxlevel = level;
	}
	if(level==maxlevel){
		c1++;
	}
	if(level==maxlevel-1){
		c2++;
	}
	if(ln[p]!=-1) dfs(ln[p],level+1);
	if(rn[p]!=-1) dfs(rn[p],level+1);
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		ln[i] = rn[i] = -1;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[i] = x;
		if(i==0) continue;
		else build(0,i);
	}
	dfs(0,1);
	c1=0;c2=0;
	dfs(0,1);
	printf("%d + %d = %d",c1,c2,c1+c2);
}
