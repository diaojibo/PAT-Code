#include<stdio.h>
#include<vector>
using namespace std;
#define N 100005

int amount[N];
bool is_r[N];
int n;
double total = 0;
vector< vector<int> > map;
double p,r;
double rate[N];
void dfs(int now,int level){
	if(is_r[now]){
		total+=amount[now]*p*rate[level];
		return;
	}else{
		int l = map[now].size();
		for(int i=0;i<l;i++){
			dfs(map[now][i],level+1);
		}
	}
}

int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	rate[1] = 1+r/100;
	rate[0] = 1;
	for(int i=2;i<=n;i++) rate[i] = rate[i-1]*(1+r/100);
	for(int i=0;i<n;i++){
		vector<int> temp;
		is_r[i] = false;
		temp.clear();
		int x;
		scanf("%d",&x);
		if(x==0){
			is_r[i] = true;
			scanf("%d",&amount[i]);
			map.push_back(temp);
			continue;
		}
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			temp.push_back(y);
		}
		map.push_back(temp);
	}
	dfs(0,0);
	printf("%.1lf",total+0.00000001);
}
