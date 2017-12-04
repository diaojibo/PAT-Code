#include<iostream>
#include<stdio.h>

using namespace std;

#define N 10005

struct user{
	char name[100];
	int id;
};

int flag[N];
int n,m,pn=0;
int ranklist[N];
int prime[N];
bool tprime[N];
bool isChecked[N];


int main(){
	scanf("%d",&n);
	for(int i=0;i<N;i++) ranklist[i] = -1;
	for(int i=0;i<n;i++){
		int tid;
		scanf("%d",&tid);
		ranklist[tid] = i+1;
	}
	for(int i=0;i<n;i++) tprime[i] = false;
	for(int i=0;i<n;i++) isChecked[i] = false;
	prime[0] = 2;
	tprime[2] = true;
	for(int i=3;i<N;i++){
		bool isPrime = true;
		for(int j=0;j<=pn;j++){
			if(i%prime[j]==0){
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			pn++;
			prime[pn] = i;
			tprime[i] = true;
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		int rank = ranklist[t];
		if(rank==-1){
			printf("%04d: Are you kidding?\n",t);
			continue;
		}
		if(isChecked[t]){
			printf("%04d: Checked\n",t);
			continue;
		}
		if(rank==1){
			printf("%04d: Mystery Award\n",t);
			isChecked[t] = true;
		}else if(tprime[rank]){
			printf("%04d: Minion\n",t);
			isChecked[t] = true;
		}else{
			printf("%04d: Chocolate\n",t);
			isChecked[t] = true;
		}
	}

}

