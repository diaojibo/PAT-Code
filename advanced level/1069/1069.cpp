#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

vector<int> a,b;
int n;
string s;
bool mcompare(int a,int b){
	return a>b;
}
bool mcompare2(int a,int b){
	return a<b;
}

void work(int k){
	a.clear();
	int k1,k2,k3,k4;
	k1 = k/1000;
	k2 = k%1000/100;
	k3 = k%100/10;
	k4 = k%10;
	if(k1==k2&&k2==k3&&k3==k4){
		printf("%04d - %04d = %04d\n",k,k,0);
		return;
	}
	a.push_back(k1);a.push_back(k2);
	a.push_back(k3);a.push_back(k4);
	b = a;
	sort(a.begin(),a.end(),mcompare);
	sort(b.begin(),b.end(),mcompare2);
	int aa = a[0]*1000+a[1]*100+a[2]*10+a[3];
	int bb = b[0]*1000+b[1]*100+b[2]*10+b[3];
	printf("%04d - %04d = %04d\n",aa,bb,aa-bb);
	if(aa-bb!=6174) work(aa-bb);
}

int main(){
	cin>>n;
	work(n);		
}
