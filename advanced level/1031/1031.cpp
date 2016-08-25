#include<stdio.h>
#include<iostream>
using namespace std;
char s[100][100];
char temp[100];
int main(){
	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++) s[i][j] = ' ';
	cin>>temp;
	int p=0;
	while(temp[p]!=0) p++;
	int bestn = 0;
	for(int i=3;i<=p;i++){
		int n13 = p+2-i;
		if(n13%2!=0) continue;
		int n1 = n13 / 2;
		if(n1>i) continue;
		if(n1>bestn) bestn = n1;
	}
	//cout<<bestn;
	int n3 = p+2-2*bestn;
	int next = 0;
	for(int i=0;i<bestn;i++){
		s[i][0]=temp[next];
		next++;
	}
	for(int i=1;i<n3;i++){
		s[bestn-1][i] = temp[next];
		//cout<<temp[next];
		next++;
	}
	for(int i=bestn-2;i>=0;i--){
		s[i][n3-1] = temp[next];
		next++;
	}
	for(int i=0;i<bestn-1;i++){
		cout<<s[i][0];
		for(int j=0;j<n3-2;j++){
			cout<<" ";
		}
		cout<<s[i][n3-1]<<endl;
	}
	for(int i=0;i<n3;i++) cout<<s[bestn-1][i];
} 
