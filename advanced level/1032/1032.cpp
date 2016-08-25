#include<iostream>
#include<stdio.h>
using namespace std;
#define N 100001
bool flag[N];
int index[N];
int a1,a2,n;
int main(){
	scanf("%d %d %d",&a1,&a2,&n);
	for(int i=0;i<n;i++){
		int x,y;
		char t;
		scanf("%d %c %d",&x,&t,&y);
		index[x] = y;
	}
	for(int i=0;i<N;i++) flag[i]=false;
	int p = a1;
	while(p!=-1){
		flag[p]=true;
		p = index[p];
	}
	p = a2;
	bool isfind = false;
	int answer=-1;
	while(p!=-1){
		if(flag[p]){
			answer = p;
			break;
		}
		p = index[p];
	}
	if(answer!=-1) printf("%05d",answer);
	else cout<<-1;
}
