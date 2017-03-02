#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
#define N 205

int n,k;
int m[N][N];
int flag[27*26*26];
char temp[10],tx[10],ty[10];
int happy[N];
vector<string> names;

int cn = 0;


int myhash(char x[]){
	//printf("%s",x);
	return int(x[0]-'A')*26*26+int(x[1]-'A')*26+int(x[2]-'A');
	
}

bool isVisited[N];
int dest[N],tol[N],maxh[N];
vector<int> prevs[N];

void dij(int source){
	for(int i=0;i<n;i++){
		isVisited[i] = false;
		dest[i] = -1;
	}
	int min = -1;
	dest[source] = 0;
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
			if(m[min][i]!=-1){
				if(dest[i]==-1||dest[min]+m[min][i]<=dest[i]){
					if(dest[min]+m[min][i]==dest[i]){
						prevs[i].push_back(min);
					}else{
						dest[i] = dest[min] + m[min][i];
						prevs[i].clear();
						prevs[i].push_back(min);
					}

				}
			}
		}
	}
}
int ans = 0;
int mh = -1;
int ad = -1;
int record[N];
int r[N],rn=0;
int ansn=0;
void dfs(int p,int h,int d){
	//printf("dfs %d %d %d ad=%d\n",p,h,d,ad);
	r[rn]=p;rn++;
//	for(int i=0;i<rn;i++) printf("%d ",r[i]);
//	printf("\n");
//	for(int i=0;i<ansn;i++) printf("%d ",record[i]);
//	printf("\n");
	if(p==0){
		if(mh==-1||h>mh){
			mh = h;
			ad = d;
			for(int i=0;i<rn;i++) record[i] = r[i];
		    ansn = rn;
		}else{
			if(h==mh&&d<ad){
				ad = d;
				for(int i=0;i<rn;i++) record[i] = r[i];
		        ansn = rn;
			}
		}
		ans++;
		rn--;
		return;
	}
	int l = prevs[p].size();
	for(int i=0;i<l;i++){
		dfs(prevs[p][i],h+happy[prevs[p][i]],d+1);
	}
	rn--;
}



int main(){
	scanf("%d %d %s",&n,&k,&temp);
	names.push_back(string(temp));
	for(int i=0;i<26*26*26;i++) flag[i] = -1;
	flag[myhash(temp)] = 0;
	for(int i=1;i<n;i++){
		int x;
		scanf("%s %d",&temp,&x);
		names.push_back(string(temp));
		flag[myhash(temp)] = i;
		happy[i] = x;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) m[i][j] = -1;
	}
	for(int i=0;i<k;i++){
		int x;
		scanf("%s %s %d",&tx,&ty,&x);
		//printf("%s %s right\n",tx,ty);
		int hx = flag[myhash(tx)];
		int hy = flag[myhash(ty)];
		m[hx][hy] = x;
		m[hy][hx] = x;
	}
	dij(0);
	temp[0]='R';temp[1]='O';temp[2]='M';temp[3]=0;
	int target = flag[myhash(temp)];
	dfs(target,happy[target],1);
	ad--;
	printf("%d %d %d %d\n",ans,dest[target],mh,mh/ad);
	for(int i=ansn-1;i>0;i--){
		printf("%s->",names[record[i]].c_str());
	}
	printf("ROM");
}
