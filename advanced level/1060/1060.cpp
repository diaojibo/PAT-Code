#include<stdio.h>
#include<iostream>
using namespace std;
int digitx=0,digity=0;
int numx=0,numy=0;
int ex[201],ey[201];
char tempx[1000],tempy[1000];
int x,y,n;
int lx=0,ly=0;
bool judge(){
	if(lx!=ly) return false;
	if(numx-digitx!=numy-digity) return false; 
	for(int i=0;i<n;i++) if(ex[i]!=ey[i]) return false;
	return true;
}

int main(){
	scanf("%d %s %s",&n,&tempx,&tempy);
	int pp=0;
	int xn=n,yn=n;
	bool allzero = true;
	while(tempx[pp]!='.'&&tempx[pp]!=0&&pp<201){
		x = int(tempx[pp]-'0');
		pp++;
		if(x!=0) allzero = false;
		else if(allzero) continue;
		numx++;
		if(lx+1<=n) ex[lx]=x,lx++;
	}
	bool initzero;
	if(allzero) lx=0,numx=0;
	if(tempx[pp]!=0) pp++;
	if(allzero) initzero = true;
	else initzero = false;
	while(tempx[pp]!='.'&&tempx[pp]!=0&pp<201){
		x = int(tempx[pp]-'0');
		pp++;
		if(x!=0) initzero = false;
		if(x==0&&initzero){
			digitx++;
			continue;
		}
		if(lx+1<=n) ex[lx]=x,lx++;
	}
	if(allzero&&initzero){
		numx=digitx=0;
		xn--;
	}
	pp=0;
	allzero = true;
	while(tempy[pp]!='.'&&tempy[pp]!=0&pp<201){
		x = int(tempy[pp]-'0');
		pp++;
		if(x!=0) allzero = false;
		else if(allzero) continue;
		numy++;
		if(ly+1<=n) ey[ly]=x,ly++;
	}
	if(allzero) ly=0,numy=0;
	if(tempy[pp]!=0) pp++;
	if(allzero) initzero = true;
	else initzero = false;
	while(tempy[pp]!='.'&&tempy[pp]!=0&pp<201){
		x = int(tempy[pp]-'0');
		pp++;
		if(x!=0) initzero = false;
		if(x==0&&initzero){
			digity++;
			continue;
		}
		if(ly+1<=n) ey[ly]=x,ly++;
	}
	if(allzero&&initzero){
		numy=digity=0;
		yn--;
	}
	while(lx+1<=xn){
		ex[lx] = 0;lx++;
	}
	while(ly+1<=yn){
		ey[ly]=0;ly++;
	}
	
//	for(int i=0;i<n;i++) cout<<ex[i]<<" ";
//	cout<<endl;
//	for(int i=0;i<n;i++) cout<<ey[i]<<" ";
//	cout<<endl;
	if(judge()){
		printf("YES 0.");
		for(int i=0;i<n;i++) printf("%d",ex[i]);
		printf("*10^%d",numx-digitx);
	}else{
		printf("NO 0.");
		for(int i=0;i<n;i++) printf("%d",ex[i]);
		printf("*10^%d",numx-digitx);
		printf(" 0.");
		for(int i=0;i<n;i++) printf("%d",ey[i]);
		printf("*10^%d",numy-digity);
	}
}
