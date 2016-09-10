#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
int main(){
	scanf("%d",&n);
	double ans=0;
	for(int i=0;i<n;i++){
		double x;
		scanf("%lf",&x);
		ans += x*(i+1)*(n-i);
	}
	printf("%.2lf",ans+0.0000001);
	//cin>>n;
}