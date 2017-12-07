#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
#define N 20005
struct edge{
	int x,y;
};

int n,m;
int target[N],link[N];
int source[N],v[N];
set<int> vset;
vector<edge> e;
int lc=0;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		v[i] = -1;
	}
	for(int i=0;i<m;i++){
		int x,y;
		edge temp;
		scanf("%d %d",&x,&y);
		temp.x = x;temp.y = y;
		e.push_back(temp);
		link[lc] = v[x];
		source[lc]=x;target[lc]=y;
		v[x]=lc;
		lc++;
		source[lc]=y;target[lc]=x;
		link[lc]=v[y];v[y]=lc;
	}
	int nv;
	scanf("%d",&nv);
	bool isVc;
	for(int i=0;i<nv;i++){
		int x;
		vset.clear();
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			vset.insert(y);
		}
		isVc = true;
		for(int k=0;k<m;k++){
			if(vset.find(e[k].x)!=vset.end()) continue;
			if(vset.find(e[k].y)!=vset.end()) continue;
			isVc = false;
			break;
		}
		if(!isVc){
			printf("No\n");
		}else{
			printf("Yes\n");
		}
	}
}
