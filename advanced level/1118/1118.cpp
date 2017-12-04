#include<stdio.h>
#include<iostream>

using namespace std;

#define N 10001

int n,m;
int father[N];
bool flag[N];

int getfather(int p){
	if(father[p]!=p){
		father[p] = getfather(father[p]);
    }
    return father[p];
}

int main(){
	scanf("%d",&n);
	int maxi = 0;
	for(int i=0;i<N;i++) father[i] = i;
	for(int i=0;i<N;i++) flag[i] = false;
	for(int i=0;i<n;i++){
		int k,temp=0;
		scanf("%d",&k);
		if(k>0) scanf("%d",&temp);
		if(temp>maxi) maxi = temp;
		for(int j=1;j<k;j++){
			int b;
			scanf("%d",&b);
			if(b>maxi) maxi = b;
			father[getfather(b)] = temp;
		}
	}
	int q;
	scanf("%d",&q);
	int trees=0;
	for(int i=1;i<=maxi;i++){
		int root = getfather(i);
		flag[root] = true;
	}
	for(int i=1;i<=maxi;i++){
		if(flag[i]) trees++;
	}
	
	printf("%d %d\n",trees,maxi);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(getfather(x)==getfather(y)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
} 
