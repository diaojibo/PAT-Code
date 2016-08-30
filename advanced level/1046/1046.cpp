#include<iostream>
#include<stdio.h>
using namespace std;
#define N 100001
int n,m;
int a[N];
int sum[N],psum[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sum[0] = psum[0] = 0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		psum[i] = psum[i-1]+a[n-i+1];
	}
	//for(int i=0;i<=n;i++) cout<<psum[i]<<" ";
	//cout<<endl;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		int bi,sm;
		if(x>y) bi=x,sm=y;
		else bi=y,sm=x;
		//cout<<bi<<" "<<sm<<endl;
		int ans;
		ans = sum[bi-1]-sum[sm-1];
		if(sum[sm-1]+psum[n-bi+1]<ans) ans = sum[sm-1]+psum[n-bi+1];
		printf("%d\n",ans); 
	}
}
