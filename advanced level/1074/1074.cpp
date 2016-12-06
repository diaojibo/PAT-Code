#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100005

struct node{
	int add;
	int nextd;
	int data;
};

int order[N],a[N];
int flag[N];
node e[N],oe[N];
int head,n,k;

void mreverse(int x,int y){
	int l=x,r=y;
	//cout<<l<<" "<<r<<endl;
	while(l<=r){
		int temp;
		temp = order[l];
		order[l] = order[r];
		order[r] = temp;
		l++;r--;
	}
}

int main(){
	scanf("%d %d %d",&head,&n,&k);
	for(int i=0;i<n;i++) flag[i] = -1;
	for(int i=0;i<n;i++){
		int x,d,y;
		scanf("%d %d %d",&x,&d,&y);
		flag[x] = i;
		e[i].add = x;
		e[i].data = d;
		e[i].nextd = y;
	}
	if(head==-1||n==0){
		printf("-1");
	}
	int pd = head;
	int num = 0;
	while(pd!=-1){
		//cout<<pd<<" "<<flag[pd]<<endl;
		int o = flag[pd];
		num++;
		oe[num] = e[o];
		pd = e[o].nextd;
	}
	if(num<n) n = num;
	for(int i=1;i<=n;i++) order[i] = i;
	int st=1;
	while(st+k-1<=n){
		mreverse(st,st+k-1);
		st = st+k;
	}
	//cout<<endl;
	for(int i=1;i<=n-1;i++){
		int ro = order[i];
		printf("%05d %d %05d\n",oe[ro].add,oe[ro].data,oe[order[i+1]].add);
	}
	printf("%05d %d %d",oe[order[n]].add,oe[order[n]].data,-1);
}
