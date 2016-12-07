#include<stdio.h>
#include<iostream>
using namespace std;

char a[1000];
char sentences[101][260];
int len_s[101];
int n;
bool all_same(int p){
	if(len_s[0]-p<0) return false;
	for(int i=1;i<n;i++){
		int l=len_s[i];
		int l2 = len_s[i-1];
		//cout<<l<<endl;
		if(l-p<0) return false;
		if(sentences[i][l-p]!=sentences[i-1][l2-p]) return false;
	}
	return true;
}

int main(){
	cin>>n;
	cin.get();
	for(int i=0;i<n-1;i++){
		cin.getline(sentences[i],257);
	}
	cin.getline(sentences[n-1],257);
	int j;
	for(int i=0;i<n;i++){
		j=0;
		while(sentences[i][j]!=0){
			j++;
		}
		len_s[i] = j-1;
	}
	int p=0;
	while(true){
		if(all_same(p)) p++;
		else break;
	}
	int ll = len_s[0];
	if(p==0){
		printf("nai");
	}else{
	    for(int i=1;i<=p;i++){
		    printf("%c",sentences[0][ll-p+i]);
	    }
    }
} 
