#include<vector>
#include<stdio.h>
using namespace std;
#define N 100001


vector<int> m[N];
int n;
double r,p;
int maxr=1;
int maxn=1;
bool isf = false;

void dfs(int p,int d){
	if(d>maxr){
		maxr = d;
		maxn=1;
		isf = true;
	} else if(d==maxr&&isf){
		maxn++;
	}
	int l = m[p].size();
	for(int i=0;i<l;i++){
		dfs(m[p][i],d+1);
	}
}



int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	int root = -1;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==-1){
			root = i;
		}else{
			m[x].push_back(i);
		}
	}
	dfs(root,1);
	double ans = p;
	for(int i=1;i<maxr;i++){
		ans = ans * (1+r/100);
	}
	printf("%.2lf %d",ans,maxn);
}
