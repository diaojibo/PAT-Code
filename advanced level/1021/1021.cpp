#include<vector>
#include<iostream>
#define N 10001
using namespace std;

struct edges{
	int x;
	int y;
};
bool isVisited[N],ise[N];
bool istree(int p){
	if(isVisied[p]) return false;
	isVisited[p] = true;
	bool test = true;
	for(int i=0;i<n-1;i++){
		int next;
		if(ise[i]) continue;
		if(edges[i].x==p||edges[i].y==p){
			if(edges[i].x==p) next = edges[i].y;
			else next = edges[i].x;
			ise[i] = true;
			test =  istree(next);
			if(!test) return false;
		}
	}
	return true;
}
void initv(){
	for(int i=0;i<=n;i++) isVisited[i] = false,ise[i] = false;
}
edges map[N+1];
int n,x,y;
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		map[i].x = x;
		map[i].y = y;
	}
	for(int i=0;i<N;i++) isVisited[i] = false;
	for(int i=1;i<=n;i++){
		initv();
		bool t = istree(i);
		if(!istree) break;
	}
	
}
