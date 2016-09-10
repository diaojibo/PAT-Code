#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1001
int n,m;
int minx,miny,mind=-1;
vector<int> a;
bool mycmp(int x,int y){
	return x>y;
}
int map[N][N];
int al=0;
void ndown(int x,int y);
void nright(int x,int y);
void nup(int x,int y){
	if(map[x][y]!=-1) return;
	if(al>=n) return;
	while(x>=0&&map[x][y]==-1){
		map[x][y]=a[al];
		al++;
		x--;
	}
	x++;
	nright(x,y+1);
}
void nright(int x,int y){
	if(al>=n) return;
	if(map[x][y]!=-1) return;
	while(y<miny&&map[x][y]==-1){
		//printf("%d %d\n",x,y);
		map[x][y]=a[al];
		al++;
		y++;
	}
	y--;
	ndown(x+1,y);
}
void nleft(int x,int y){
	if(map[x][y]!=-1) return;
	if(al>=n) return;
	while(y>=0&&map[x][y]==-1){
		map[x][y]=a[al];
		al++;
		y--;
	}
	y++;
	nup(x-1,y);
}
void ndown(int x,int y){
	if(map[x][y]!=-1) return;
	if(al>=n) return;
	while(x<minx&&map[x][y]==-1){
		map[x][y]=a[al];
		al++;
		x++;
	}
	x--;
	nleft(x,y-1);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),mycmp);
	int p=1;
	while(p*p<=n){
		if(n%p==0){
			int x = n/p;
			if(mind==-1||x-p<mind){
				minx = x;miny =p;
				mind = x-p;
			}
		}
		p++;
	}
	for(int i=0;i<minx;i++)
		for(int j=0;j<miny;j++) map[i][j]=-1;
	nright(0,0);
	for(int i=0;i<minx;i++){
		for(int j=0;j<miny-1;j++){
			printf("%d ",map[i][j]);
		}
		printf("%d\n",map[i][miny-1]);
	}
	cin>>n;
}