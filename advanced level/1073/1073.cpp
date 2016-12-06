#include<iostream>
#include<stdio.h>
using namespace std;

char temp[100000];
char num[100000]; 
int nn=0;
int digt = 0;
char ans[100000];
int main(){
	scanf("%s",&temp);
	int no = 1;
	int eo = 1;
	if(temp[0]=='-') no = -1;
	int j=1;
	//while(temp[j]='0') j++;
	while(temp[j]!='E'){
		if(temp[j]=='.'){
			digt = j-1;
			j++;
			continue;
		}
		nn++;
		num[nn] = temp[j];
		j++;
	}
	j++;
	if(temp[j]=='-') eo = -1;
	j++;
	int e=0;
	while(temp[j]!=0){
		e = e*10+int(temp[j]-'0');
		j++;
	}
	int jj;
	if(no<0) ans[0] = '-',jj=1;
	else jj=0;
	if(eo<0){
		ans[jj] = '0';
		ans[jj+1] = '.';
		jj=jj+1;
		int ei = e;
		for(int i=1;i<=ei-1;i++){
			jj++;
			ans[jj] = '0';
		}
		for(int i=1;i<=nn;i++) ans[jj+i] = num[i];
		ans[jj+nn+1] = 0;
		//
		//for(int i=0;i<=jj+nn;i++) printf("%c",ans[i]);
		//printf("sss %c\n",ans);
	}else{
		if(e>=nn-1){
			for(int i=1;i<=nn;i++) ans[jj+i-1]=num[i];
			jj = jj+nn-1;
			for(int i=1;i<=e-nn+1;i++){
				jj++;
				ans[jj] = '0';
			}
			ans[jj+1] = 0;
		}else{
			for(int i=1;i<=e+1;i++){
				jj++;
				ans[jj-1] = num[i];
			}
			jj++;ans[jj-1] = '.';
			for(int i=e+2;i<=nn;i++){
				jj++;
				ans[jj-1] = num[i];
			}
			ans[jj] = 0;
		}
	}
	printf("%s",ans);
}
