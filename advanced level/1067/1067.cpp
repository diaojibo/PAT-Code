#include<iostream>
#include<stdio.h>
using namespace std;

#define N 100000
int a[N],pos[N];
int n,m;
int tol = 0;
void mswap(int x,int y){
	int t;
	tol++;
	pos[a[x]] = y;
	pos[a[y]] = x;
	t = a[x];
	a[x] = a[y];
	a[y] = t;
}
bool judge(){
	for(int i=0;i<n;i++){
		if(a[i]!=i) return false; 
	}
	return true;
}
int main(){
	scanf("%d",&n);
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	while(!judge()){
		//for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
		if(a[0]==0){
			int j = 0;
			while(a[j]==j) j++;
			mswap(pos[0],pos[j]);
		}
		mswap(pos[0],pos[pos[0]]);
	}
	printf("%d",tol);
}
