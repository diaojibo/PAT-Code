#include<vector>
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
vector<int> a;
long n,m;
int main(){
	scanf("%ld",&n);
	a.push_back(2);
	int k = 1;
	for(int i=3;i<=10000;i++){
		bool isprime = false;
		for(int j=0;j<k;j++){
			if(i%a[j]==0){
				isprime = true;
				break;
			}
			if(a[j]*a[j]>i) break;
		}
		if(!isprime){
			k++;
			a.push_back(i);
		}
	}
	if(n!=1) printf("%ld=",n);
	else printf("1=1");
	for(int i=0;i<k;i++){
		if(n%a[i]==0){
			int t = 0;
			while(n%a[i]==0){
				t++;
				n = n/a[i];
			}
			if(n!=1){
				if(t>1) printf("%d^%d*",a[i],t);
				else printf("%d*",a[i]);
			}else{
				if(t>1) printf("%d^%d",a[i],t);
				else printf("%d",a[i]);
				break;
			}
		}
	}
}
