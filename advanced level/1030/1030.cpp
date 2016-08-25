#include<iostream>
#include<stack>
using namespace std;
#define N 502
int map[N][N],cost[N][N];
int n,m,source,target;
bool isVisited[N];
int dest[N];
int parent[N],dcost[N];
void dij(int source,int target){
	for(int i=0;i<n;i++){
		isVisited[i] = false;
		dest[i] = -1;
		dcost[i]=-1;
		parent[i] = -1;
	}
	dest[source] = 0;
	dcost[source]=0;
	int min;
	while(true){
		min = -1;
		for(int i=0;i<n;i++){
			if(!isVisited[i]&&dest[i]!=-1){
				if(min==-1||dest[i]<dest[min]){
					min = i;
				}
			}
		}
		if(min==-1) break;
		isVisited[min] = true;
		for(int i=0;i<n;i++){
			if(map[min][i]!=-1){
				if(dest[i]==-1||dest[min]+map[min][i]<=dest[i]){
					if(dest[min]+map[min][i]==dest[i]){
						if(dcost[i]==-1||dcost[min]+cost[min][i]<dcost[i]){
							dcost[i]=dcost[min]+cost[min][i];
							parent[i] = min;
						}
					}else{
						dest[i] = dest[min] + map[min][i];
						dcost[i] = dcost[min] + cost[min][i];
						parent[i] = min;
					}
				}
			}
		}
		
	}
}
int main(){
	cin>>n>>m>>source>>target;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) map[i][j]=cost[i][j]=-1;
	}
	for(int i=0;i<m;i++){
		int x,y,z,k;
		cin>>x>>y>>z>>k;
		map[x][y]=map[y][x] = z;
		cost[x][y]=cost[y][x]=k;
	}
	dij(source,target);
	int p = target;
	stack<int> st;
	st.push(p);
	while(parent[p]!=-1){
		st.push(parent[p]);
		p = parent[p];
	}
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<dest[target]<<" "<<dcost[target];
}
