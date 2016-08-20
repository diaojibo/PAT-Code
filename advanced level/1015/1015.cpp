#include<string>
#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;

#define N 100001

bool form[N];
int x,y;

int change(int x,int radix){
	int num[100];
	int lens = 0;
	while(x>0){
		lens++;
		num[lens-1] = x % radix;
		x = x/radix;
	}
	int sum=0;
	for(int i=0;i<lens;i++){
		sum = sum*radix;
		sum+=num[i];
	}
	return sum;
}

int main(){
	form[0] = form[1] = false;
	for(int i=2;i<N;i++){
		form[i] = true;
		for(int j=2;j<i;j++){
			if(j*j>i) break;
			if(i%j==0){
				form[i] = false;
				break;
			}
		}
		//if(i<100) cout<<i<<" "<<form[i]<<endl;
	}
	cin>>x;
	char temp[100];
	while(x>=0){
		cin>>y;
		int rx = change(x,y);
		//cout<<rx<<endl;
		if(form[x]&&form[rx]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		cin>>x;
	}
}

