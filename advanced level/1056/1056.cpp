#include<stdio.h>
#include<iostream>
using namespace std;
#define N 1001
int ranks[N],w[N],order[N],temp[N];
int nover[N];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
		ranks[i] = -1;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&order[i]);
	}
	int overs = 0;
	int turn = 1;
	int num = 0;
	while(num<n-1){
		int cnum=0;
		int pp = 0,nmax = -1;
		while(pp<n){
			int x = order[pp];
			//cout<<x<<" -turn "<<turn<<endl;
			if(ranks[x]==-turn){
				cnum++;
				if(nmax==-1||w[x]>w[nmax]) nmax = x; 
			}
			if(cnum==m){
				num+=cnum-1;
				cnum=0;
				ranks[nmax]--;
				nmax=-1;
			}
			pp++;
		}
		if(cnum!=0){
			num+=cnum-1;
			cnum=0;
			ranks[nmax]--;
			nmax=-1;
		}
		nover[turn] = num;
		turn++;
	}
	nover[turn] = n;
	//for(int i=0;i<n;i++) cout<<nover[i]<<" ";
	//cout<<endl;
	for(int i=0;i<n-1;i++){
		int r = -ranks[i];
		printf("%d ",n-nover[r]+1);
	}
	int r = -ranks[n-1];
	printf("%d",n-nover[r]+1);
}
