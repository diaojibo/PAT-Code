#include<stdio.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>

using namespace std;
#define N 505
int map[N][N];
int dest[N];
int bikes[N];
stack<int> a,besta;
vector<int> pres[N];
int cmax,n,target,m;
bool isVisited[N];
struct answer{
	int sent,take;
};

void dij(int target){
	for(int i=0;i<=n;i++){
		dest[i] = -1;
		isVisited[i] = false;
	}
	bikes[0] = 0;
	dest[0] = 0;
	int min = -1,lent = 0;
	while(true){
		min = -1;
		for(int i=0;i<=n;i++){
			if(!isVisited[i]&&dest[i]!=-1){
				if(min==-1||dest[i]<dest[min]){
					min = i;
				}
			}
		}
		if(min==-1) break;
		isVisited[min] = true;
		for(int i=0;i<=n;i++){
			if(map[min][i]!=-1){
				if(dest[i]==-1||dest[min]+map[min][i]<=dest[i]){
					if(dest[min]+map[min][i]==dest[i]){
						pres[i].push_back(min);
					}else{
						dest[i] = dest[min]+map[min][i];
						pres[i].clear();
						pres[i].push_back(min);
					}
				}
			}
		}
	}
}
int bmin = -9999;
string fst = "";
bool mycmp(answer x,answer y){
	if(x.sent!=y.sent) return x.sent<y.sent;
	else return x.take<y.take;
}
answer getbikes(stack<int> x){
	int q,l = x.size();
	answer v;
	v.take = 0;v.sent = 0;
	while(x.size()>0){
		q = x.top();
		q = bikes[q];
		if(q>cmax/2){
			v.take += q - (cmax/2);
		}
		if(q<cmax/2){
			if(v.take>0){
				if(q+v.take<=cmax/2){
					v.sent += cmax/2 - q - v.take;
					v.take = 0;
				}else{
					v.take = v.take - (cmax/2-q);
				}
			}else v.sent+=cmax/2 - q;
		}
		//cout<<x.top()<<" "<<v.sent<<" "<<v.take<<endl;
		x.pop();
	}
	return v;
}
bool iffind = false;
answer bestans;
void dfsp(int source,int target){
	if(source==target){
		answer now = getbikes(a);
		if(!iffind||mycmp(now,bestans)){
			besta = a;
			bestans = now;
			iffind = true;
		}
		return;
	}
	a.push(target);
	int l = pres[target].size();
	for(int i=0;i<l;i++){
		dfsp(source,pres[target][i]);
	}
	a.pop();
}

string getstring(stack<int> x){
	int l = x.size();
	stringstream ss;
	while(x.size()>0){
		ss<<"->"<<x.top();
		x.pop();
	}
	return ss.str();
}

int main(){
	cin>>cmax>>n>>target>>m;
	for(int i=1;i<=n;i++){
		cin>>bikes[i];
	}
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++) map[i][j] = -1;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		map[x][y] = map[y][x] = z;
	}
	int ans;
	dij(target);
	dfsp(0,target);
	fst = getstring(besta);
	cout<<bestans.sent<<" 0"+fst+" "<<bestans.take;
	
}
