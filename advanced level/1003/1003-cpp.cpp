#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

#define N 501


int n,m,c1,c2;
int map[N][N];
int dest[N];
int hands[N];
vector<int> parents[N];
int isVisited[N];
int pathcount = 0,maxt = 0;

void dij(int source,int target){
	
	for(int i=0;i<n;i++){
		dest[i] = -1;
		isVisited[i] = false;
	}
	dest[source] = 0;
	for(int i=0;i<n;i++){
		int min = -1;
		for(int j=0;j<n;j++){
			if(dest[j] == -1 || isVisited[j]) continue;
			if(min==-1 || dest[j]<dest[min]){
				min = j;
			}
		}
		if(min==-1) break;
		isVisited[min] = true;
		for(int j=0;j<n;j++){
			if(map[min][j]!=-1){
				if(dest[j]==-1 || dest[min]+map[min][j] <= dest[j]){
					if(dest[min]+map[min][j]==dest[j]){
						parents[j].push_back(min);
					}
					else{
						parents[j].clear();
						parents[j].push_back(min);
					}
					dest[j] = dest[min]+map[min][j];
				}
			}
		}
	}
}


void dfs(int target,int source,int teams){
	int teamv = teams + hands[target];
	if(target == source){
		pathcount++;
		if(teamv>maxt) maxt = teamv;
		return; 
	}
	int len = parents[target].size();
	for(int i=0;i<len;i++){
		dfs(parents[target][i],source,teamv);
	}
}

int main(){
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&hands[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) 
		  map[i][j] = -1;
	}
	    
	int x,y,z;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&z);
		map[x][y] = map[y][x] = z;
		
		
	}
	dij(c1,c2);
	dfs(c2,c1,0);
	
	printf("%d %d",pathcount,maxt);
	
	return 0;
} 
