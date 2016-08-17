#include<iostream>
#include<stdio.h>
using namespace std;

#define N 3005
float a[N],b[N],c[N];
int n,x,y,t;
int main(){
	cin>>n;
	for(int i=0;i<N;i++) a[i]=b[i]=c[i] = 0;
	for(int i=0;i<n;i++){
		cin>>t;
		cin>>a[t];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		cin>>b[t];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			c[i+j] = c[i+j]+a[i] * b[j];
		}
	}
	int num=0;
	for(int i=0;i<N;i++) if(c[i]!=0) num++;
	cout<<num;
	for(int i=N-1;i>=0;i--){
		if(c[i]!=0) printf(" %d %.1f",i,c[i]);
	}
	if(num==0) cout<<endl;
	return 0;
}
