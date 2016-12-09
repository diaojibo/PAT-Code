#include<stdio.h>
#include<queue> 
using namespace std;

bool map[100][1300][135];
bool isVisited[100][1300][135];
int m,n,t,l;
int volume = 0;
int v = 0;
queue<int> xx,yy,zz;
void dfs(int x,int y,int z){
	isVisited[x][y][z] = true;
	//printf("%d %d %d\n",x,y,z);
	v++;
	//if(v>t) return;
	if(x>0&&!isVisited[x-1][y][z]&&map[x-1][y][z]) dfs(x-1,y,z);
	if(y>0&&!isVisited[x][y-1][z]&&map[x][y-1][z]) dfs(x,y-1,z);
	if(z>0&&!isVisited[x][y][z-1]&&map[x][y][z-1]) dfs(x,y,z-1);
	if(x<l-1&&!isVisited[x+1][y][z]&&map[x+1][y][z]) dfs(x+1,y,z);
	if(y<m-1&&!isVisited[x][y+1][z]&&map[x][y+1][z]) dfs(x,y+1,z);
	if(z<n-1&&!isVisited[x][y][z+1]&&map[x][y][z+1]) dfs(x,y,z+1);
}
void bfs(int x1,int y1,int z1){
	xx.push(x1);
	yy.push(y1);
	zz.push(z1);
	while(!xx.empty()){
		int x,y,z;
		x=xx.front();y=yy.front();
		z=zz.front();
		v++;
		xx.pop();yy.pop();zz.pop();
		isVisited[x][y][z]=true;
		if(x>0&&!isVisited[x-1][y][z]&&map[x-1][y][z]){
			isVisited[x-1][y][z]=true;
			xx.push(x-1);yy.push(y);zz.push(z);
		}
	    if(y>0&&!isVisited[x][y-1][z]&&map[x][y-1][z]){
	    	isVisited[x][y-1][z]=true;
			xx.push(x);yy.push(y-1);zz.push(z);
		}
	    if(z>0&&!isVisited[x][y][z-1]&&map[x][y][z-1]){
	    	isVisited[x][y][z-1]=true;
			xx.push(x);yy.push(y);zz.push(z-1);
		}
	    if(x<l-1&&!isVisited[x+1][y][z]&&map[x+1][y][z]){
	    	isVisited[x+1][y][z]=true;
			xx.push(x+1);yy.push(y);zz.push(z);
		}
	    if(y<m-1&&!isVisited[x][y+1][z]&&map[x][y+1][z]){
	    	isVisited[x][y+1][z]=true;
			xx.push(x);yy.push(y+1);zz.push(z);
		}
	    if(z<n-1&&!isVisited[x][y][z+1]&&map[x][y][z+1]){
	    	isVisited[x][y][z+1]=true;
			xx.push(x);yy.push(y);zz.push(z+1);
		}
		
	}
}

int main(){
	scanf("%d %d %d %d",&m,&n,&l,&t);
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				int x;
				scanf("%d",&x);
				if(x==1) map[i][j][k]=true;
				else map[i][j][k]=false;
				isVisited[i][j][k] = false;
			}
		}
	}
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				if(!isVisited[i][j][k]&&map[i][j][k]){
					v=0;
					bfs(i,j,k);
					//printf("%d x=%d y=%d z=%d\n",v,i,j,k);
					if(v>=t) volume += v;
				}
			}
		}
	}
	printf("%d",volume);
}
