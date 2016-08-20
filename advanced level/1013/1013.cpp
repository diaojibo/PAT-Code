#include<iostream>
#include<queue>
using namespace std;
#define N 1001

bool map[N][N];
bool temp[N];
bool isVisited[N];
int n,m,k,ans;

int dfs(int p){
	//cout<<"p:"<<p<<endl;
	for(int i=0;i<n;i++){
		if(!isVisited[i]&&map[p][i]){
			isVisited[i] = true;
			dfs(i);
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)  map[i][j] = false;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		map[x][y] = map[y][x] = true;
	}
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		x--;
		for(int j=0;j<n;j++){
			temp[j] = map[x][j];
			map[x][j] = map[j][x] = false;
			
		}
		for(int j=0;j<n;j++) isVisited[j] = false;
		ans = 0;isVisited[x] = true;
		for(int j=0;j<n;j++){
			if(!isVisited[j]) {
				isVisited[j] = true;
				dfs(j);
				ans++;
			}
		}
		cout<<ans-1<<endl;
		for(int j=0;j<n;j++){
			map[x][j] = map[j][x] = temp[j];
			
		}
	} 
}
