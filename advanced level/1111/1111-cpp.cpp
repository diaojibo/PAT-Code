#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<string>
using namespace std;
#define N 502

int map_len[N][N],map_time[N][N];
int n,m;
int dest_len[N],dest_time[N];
int parents[N];
string path_len,path_time;
char temps[100];


string getstring(int p[N],int target,int source){
	if(target==source){
		sprintf(temps,"%d",source);
		return string(temps);
	}
	string st;
	sprintf(temps,"%d",target);
	st = getstring(p,p[target],source) + " -> " + string(temps);
	return st;
}

//flag 0 for len(bestinfo=fastest) 1 for time(bestinfo=minlevel) 
void dij(int source,int target,int map[N][N],int dest[N],int flag){
	bool isV[N];
	int best_info[N];
	for(int i=0;i<n;i++){
		dest[i] = -1;
		isV[i] = false;
		best_info[i] = -1;//init
	}
	dest[source] = 0;
	best_info[source] = 0;
	int min;

	while(true){
		min = -1;
		for(int i=0;i<n;i++){
			if(!isV[i] && dest[i]!=-1){
				if(min==-1||dest[i]<dest[min]){
					min = i;
				}
			}
		}
		if(min==-1) break;
		isV[min] = true;
		for(int i=0;i<n;i++){
			if(map[min][i]>0){
				if(dest[i]==-1||dest[min]+map[min][i]<=dest[i]){
					if(dest[i] == dest[min]+map[min][i]){
						if(flag==0){
							if(best_info[min]+map_time[min][i]<best_info[i]){
								best_info[i] = best_info[min]+map_time[min][i];
								parents[i] = min;
							}
						}else{
							if(best_info[min]+1<best_info[i]){
								best_info[i] = best_info[min] + 1;
								parents[i] = min;
							}
						}
					}else{
						dest[i] = dest[min]+map[min][i];
						parents[i] = min;
					    if(flag==0){
							best_info[i] = best_info[min]+map_time[min][i];
					    }else{
							best_info[i] = best_info[min] + 1;
					         }
					}
				}
			}
		}
	}

	if(flag==0){
		path_len = getstring(parents,target,source);
	}else{
		path_time = getstring(parents,target,source);
	}

}


int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			map_len[i][j] = -1;
			map_time[i][j] = -1;
		}
	for(int i=0;i<m;i++){
		int x,y,flag,length,time;
		scanf("%d %d %d %d %d",&x,&y,&flag,&length,&time);
		map_len[x][y] = length;
		map_time[x][y] = time;
		if(flag!=1){
			map_len[y][x] = length;
			map_time[y][x] = time;
		}
	}
	int source,target;
	scanf("%d %d",&source,&target);
	dij(source,target,map_len,dest_len,0);
	dij(source,target,map_time,dest_time,1);
	if(path_len==path_time){
		printf("Distance = %d; Time = %d: %s",dest_len[target],dest_time[target],path_len.c_str());
	}else{
		printf("Distance = %d: %s\n",dest_len[target],path_len.c_str());
		printf("Time = %d: %s\n",dest_time[target],path_time.c_str());
	}
	cin>>n;
}