#include<vector>
#include<iostream>
#include<stdio.h>
#define N 10001
using namespace std;

struct edges{
	int target;
	int next;
};
int n,m;
edges e[N*2];
int link[N];
bool isVisited[N];

void dfsp(int p){
	int x;
	x = link[p];
	while(x!=-1){
		int t = e[x].target;
		if(!isVisited[t]){
			isVisited[t] = true;
			dfsp(t);
		}
		x = e[x].next;
	}
}
int maxlevel,thislevel;
vector<int> roots;
void dfs(int p,int level){
	//cout<<p<<" "<<level<<" "<<maxlevel<<endl;
	if(level>thislevel){
		thislevel = level;
	}
	int x;
	x = link[p];
	while(x!=-1){
		int t = e[x].target;
		if(!isVisited[t]){
			isVisited[t] = true;
			dfs(t,level+1);
		}
		x = e[x].next;
	}
}

void initv(){
	for(int i=1;i<=n;i++){
		isVisited[i] = false;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		link[i] = -1;
		isVisited[i] = false;
	}
	int el;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[el].next = link[x];
		link[x] = el;
		e[el].target = y;
		el++;
		e[el].next = link[y];
		link[y] = el;
		e[el].target = x;
		el++;
	}
	int cp = 0;
	for(int i=1;i<=n;i++){
		if(!isVisited[i]){
			cp++;
			isVisited[i] = true;
			dfsp(i);
		}
	}
	if(cp>1){
		printf("Error: %d components",cp);
	}else{
		maxlevel = -1;
		for(int i=1;i<=n;i++){
			initv();
			thislevel = -1;
			isVisited[i] = true;
			dfs(i,1);
			//cout<<thislevel<<" "<<maxlevel<<endl;
			if(thislevel>=maxlevel){
				if(thislevel==maxlevel) roots.push_back(i);
				else{
					roots.clear();
					roots.push_back(i);
					maxlevel = thislevel;
				}
			}
		}
		int l = roots.size();
		for(int i=0;i<l;i++){
			cout<<roots[i]<<endl;
		}
	}
}
