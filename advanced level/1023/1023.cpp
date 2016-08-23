#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
int numbers[10],newnum[10];
int newn[100],oldnum[100];

void mydouble(char x[],int& l){
	for(int i=0;i<l;i++){
		oldnum[l-i-1] = int(x[i]-'0')*2;
	}
	for(int i=0;i<l;i++){
		if(oldnum[i]>=10) oldnum[i+1]+=oldnum[i]/10,oldnum[i]=oldnum[i]%10;
	}
	if(oldnum[l]>0) l++;
	for(int i=0;i<l;i++) newnum[oldnum[i]]++;
}


int main(){
	char t[100];
	cin>>t;
	for(int i=0;i<=9;i++) numbers[i] = 0,newnum[i]=0;
	int l = 0;
	while(t[l]!=0){
		int x = int(t[l] - '0');
		numbers[x]++;
		l++;
	}
	mydouble(t,l);
	bool ans = true;
	for(int i=0;i<=9;i++) if(numbers[i]!=newnum[i]) ans = false;
	if(ans) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=l-1;i>=0;i--) cout<<oldnum[i];
	
} 
