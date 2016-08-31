#include<stack>
#include<stdio.h>
#include<iostream>
using namespace std;
#define N 1001
int n,m,k;
int a[N];
bool ins[N],outs[N];
bool judge(int a[]){
	for(int i=0;i<n;i++) ins[i] = false,outs[i]=false;
	int pp=0;
	int pushn = 1;
	bool ispossible = false;
	stack<int> s;
	while(pp<n){
		int x = a[pp];
		//cout<<x<<" ttt"<<endl;
		if(outs[x]) return false;
		if(!ins[x]){
			if(pushn>x) return false;
			while(pushn<=x){
				s.push(pushn);
				if(s.size()>m) return false;
				ins[pushn] = true;
				pushn++;
			}
			s.pop();
			ins[x] = false;
		}else{
			int q = s.top();
			if(q!=x) return false;
			s.pop();
			ins[x] = false;
		}
		pp++;
	}
	return true;
}



int main(){
	scanf("%d %d %d",&m,&n,&k);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		if(judge(a)){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
