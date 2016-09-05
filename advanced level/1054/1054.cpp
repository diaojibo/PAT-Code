#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

long a[800*600+1];
map<int,int> mm;
int n,m;
int main(){
	scanf("%d %d",&m,&n);
	int answer=-1;
	int dc = -1;
	for(int i=0;i<n*m;i++){
		scanf("%ld",&a[i]);
		mm[a[i]]++;
		if(mm[a[i]]>answer){
			answer = mm[a[i]];
			dc = a[i];
		}
	}
	printf("%d",dc);
}
