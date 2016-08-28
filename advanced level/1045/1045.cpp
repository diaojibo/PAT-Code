#include<vector>
#include<stdio.h>
using namespace std;
int n,m,k;
#define K 301
#define L 10050
int fav[K],st[L];
int f[L][K];
int mmax=0;
int main(){
	scanf("%d",&k);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&fav[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&st[i]);
	}
	
	if(st[0]==fav[0]) f[0][0] = 1;
	for(int i=0;i<n;i++){
		f[0][i] = f[0][i-1];
		if(st[0]==fav[i]) {
			f[0][i]=1;
			if(f[0][i]>mmax) mmax = f[0][i];
		}
	}
	
	for(int i=1;i<m;i++){
		f[i][0] = f[i-1][0];
		if(st[i]==fav[0]) {
		f[i][0]=f[i-1][0]+1;	
		}
		if(f[i][0]>mmax) mmax=f[i][0];
		for(int j=1;j<n;j++){
			f[i][j] = f[i][j-1];
			if(st[i]==fav[j]){
				if(f[i-1][j]+1>f[i][j]) f[i][j] =f[i-1][j]+1;
				if(f[i][j-1]+1>f[i][j]) f[i][j] = f[i][j-1]+1;
			}
			if(f[i-1][j]>f[i][j]) f[i][j] = f[i-1][j];
			if(f[i][j]>mmax) mmax=f[i][j];
		}
	}
	
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",f[i][j]);
		}
		printf("\n");
	}
	
	printf("%d",mmax);
}
