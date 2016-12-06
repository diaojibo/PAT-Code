#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
#define N 1100
#define K 10002
char readx[100],readb[100];
int a[N+11];
int target[2*K];
int link[2*K],path[2*K];
int n,m,k,d;
int nl=0;
int dist[12][N];
bool flag[N];

int getint(char x[]){
	int j=0;
	bool isg = false;
	if(x[0]=='G') j++,isg=true;
	int g=0;
	while(x[j]!=0){
		g=g*10+int(x[j]-'0');
		j++;
	}
	if(!isg) return g;
	else return g+n;
}
void addpath(int x,int y,int p){
	nl++;
	target[nl] = y;
	link[nl] = a[x];
	path[nl] = p;
	a[x] = nl;
}
void dij(int p){
	int nn=n+m;
	for(int i=1;i<=nn;i++){
		dist[p][i] = -1;
		flag[i] = false;
	}
	int min=-1;
	dist[p][p+n] = 0;
	while(true){
		min = -1;
		for(int i=1;i<=nn;i++){
			if(flag[i]||dist[p][i]==-1) continue;
			if(min==-1||dist[p][i]<dist[p][min]){
				min = i;
			}
		}
		if(min==-1) break;
		flag[min] = true;
		int np = a[min];
		while(np!=-1){
			int pp = path[np];
			int now = target[np];
			if(dist[p][now]==-1||dist[p][min]+pp<dist[p][now]){
				dist[p][now] = dist[p][min] + pp;
			}
			np = link[np];
		}
	}
}
bool is_service(int p){
	for(int i=1;i<=n;i++){
		if(dist[p][i]>d||dist[p][i]==-1) return false;
	}
	return true;
}
int min_dist(int p){
	int q=-1;
	for(int i=1;i<=n;i++){
		if(q==-1||dist[p][i]<q) q=dist[p][i];
	}
	return q;
}
int all_dist(int p){
	int ssum=0;
	for(int i=1;i<=n;i++){
		ssum += dist[p][i];
	}
	return ssum;
}
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&d);
	for(int i=1;i<=n+m;i++) a[i]=-1;
	for(int i=0;i<k;i++){
		int x;
		scanf("%s %s %d",&readx,&readb,&x);
		int xx,yy;
		xx=getint(readx);yy=getint(readb);
		addpath(xx,yy,x);
		addpath(yy,xx,x);
	}
	for(int i=1;i<=m;i++){
		dij(i);
	}

	bool isfind = false;
	double mind=-1;
	double ad = -1;
	int best = -1;
	for(int i=1;i<=m;i++){
		if(is_service(i)){
			if(!isfind){
				mind = min_dist(i);
				ad = all_dist(i);
				best = i;
				isfind =true;
			}else{
				int xmind = min_dist(i);
				int xad = all_dist(i);
				if(xmind>mind){
					best=i;
					mind = xmind;
					ad = xad;
				}else if(xmind==mind&&xad<ad){
					best = i;
					ad = xad;
				}
			}
		}
	}
	if(isfind){
		printf("G%d\n",best);
		printf("%.1f %.1f",mind,ad/n);
	}else{
		printf("No Solution");
	}
} 
