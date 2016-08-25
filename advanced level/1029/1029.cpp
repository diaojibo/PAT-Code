#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

vector<long long> a;

long long n1,n2;
long long x;

bool mycmp(long x,long y){
	return x<y;
}

int main(){
	scanf("%ld",&n1);
	for(int i=0;i<n1;i++){
		scanf("%ld",&x);
		a.push_back(x);
	}
	scanf("%ld",&n2);
	for(int i=0;i<n2;i++){
		scanf("%ld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),mycmp);
	long n = n1+n2,index;
	if(n%2==0){
		index = n/2-1;
		printf("%ld",a[index]);
	}else{
		index = n/2;
		printf("%ld",a[index]);
	}
}
 
