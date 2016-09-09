#include<stdio.h>
#include<iostream>
using namespace std;
long long a[5],b[5],c[5];
char tempx[30],tempy[30];
int main(){
	scanf("%s %s",&tempx,&tempy);
	int pp=0;
	for(int i=0;i<5;i++) a[i] = b[i] = 0;
	while(tempx[pp]!='.'&&tempx[pp]!=0){
		a[2]=a[2]*10+int(tempx[pp]-'0');
		pp++;
	}
	if(tempx[pp]!=0) pp++;
	while(tempx[pp]!='.'&&tempx[pp]!=0){
		a[1]=a[1]*10+int(tempx[pp]-'0');
		pp++;
	}
	if(tempx[pp]!=0) pp++;
	while(tempx[pp]!='.'&&tempx[pp]!=0){
		a[0]=a[0]*10+int(tempx[pp]-'0');
		pp++;
	}
	pp=0;
	while(tempy[pp]!='.'&&tempy[pp]!=0){
		b[2]=b[2]*10+int(tempy[pp]-'0');
		pp++;
	}
	if(tempy[pp]!=0) pp++;
	while(tempy[pp]!='.'&&tempy[pp]!=0){
		b[1]=b[1]*10+int(tempy[pp]-'0');
		pp++;
	}
	if(tempy[pp]!=0) pp++;
	while(tempy[pp]!='.'&&tempy[pp]!=0){
		b[0]=b[0]*10+int(tempy[pp]-'0');
		pp++;
	}
	for(int i=0;i<3;i++){
		c[i] = a[i]+b[i];
	}
	if(c[0]>=29){
		c[1] += c[0]/29;
		c[0] = c[0]%29;
	}
	if(c[1]>=17){
		c[2] += c[1]/17;
		c[1] = c[1]%17;
	}
	printf("%ld.%ld.%ld",c[2],c[1],c[0]);
} 
