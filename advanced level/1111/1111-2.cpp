#include<stdio.h>
#include<string>
using namespace std;
#define N 505

int n,m;
int map_time[N][N];
int map_len[N][N];
string path_time,path_len;
int min_distance,min_time;

string getString(int p[N],int source,int target){
	if(source==target){
		char st[100];
		sprintf(st,"%d",target);
		return string(st);
	}
	char s[100];
	sprintf(s,"%d",target);
	return getString(p,source,p[target]) + " -> " + string(s);
}

//flag 0 len flag 1 time
void dij(int source,int target,int maps[N][N],int flag){
	bool isV[N];
	int dest[N];
	int info[N];
	int parent[N];
	for(int i=0;i<n;i++){
		isV[i] = false;
		dest[i] = -1;
		info[i] = 0;
		parent[i]=-1;
	}
	int min = -1;
	dest[source] = 0;
	while(true){
		//printf("min=%d\n",min);
		min = -1;
		for(int i=0;i<n;i++){
			if(!isV[i]&&dest[i]!=-1){
				if(min==-1||dest[i]<dest[min]){
					min = i;
				}
			}}
			if(min==-1) break;
			isV[min] = true;
			for(int i=0;i<n;i++){
				if(maps[min][i]!=-1){
					if(dest[i]==-1||dest[min]+maps[min][i]<=dest[i]){
						if(dest[min]+maps[min][i]==dest[i]){
							if(flag==0){
								//short
								if(info[min]+map_time[min][i]<info[i]){
									info[i]=info[min]+map_time[min][i];
									parent[i]=min;
								}
							}else{
								//fast
								if(info[min]+1<info[i]){
									info[i]=info[min]+1;
									parent[i]=min;
								}
							}
						}else{
							dest[i] = dest[min]+maps[min][i];
							parent[i]=min;
							if(flag==0) info[i]=info[min]+map_time[min][i];
							else info[i]=info[min]+1;
						}
					}
				}
			}
		
	}
	if(flag==0){
		path_len = getString(parent,source,target);
		min_distance = dest[target];
		//printf("Distance = %d: %s\n",dest[target],st.c_str());
	}else{
		path_time = getString(parent,source,target);
		min_time = dest[target];
		//printf("Time = %d: %s\n",dest[target],st.c_str());
	}
}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		map_time[i][j]=map_len[i][j] = -1;
	}
	for(int i=0;i<m;i++){
		int x,y,flag,l,t;
		scanf("%d %d %d %d %d",&x,&y,&flag,&l,&t);
		map_time[x][y]=t;map_len[x][y]=l;
		if(flag==0){
			map_time[y][x]=t;map_len[y][x]=l;
		}
	}
	int x,y;
	scanf("%d %d",&x,&y);
	dij(x,y,map_len,0);
	dij(x,y,map_time,1);
	if(path_time==path_len){
		printf("Distance = %d; Time = %d: %s\n",min_distance,min_time,path_time.c_str());
	}else{
		printf("Distance = %d: %s\n",min_distance,path_len.c_str());
		printf("Time = %d: %s\n",min_time,path_time.c_str());
	}
	
} 
