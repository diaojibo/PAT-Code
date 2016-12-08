#include<stdio.h>
using namespace std;
#define N 1000000
int n;
int maxn = 0;
int ans=0;
int main(){
	scanf("%d",&n);
	for(int i=2;i<N*2;i++){
		if(i*i>n&&i!=n) break;
		if(n%i==0){
			int num=0;
			int j = i;
			int nn = n;
			while(nn%j==0){
				num++;
				//printf("%d %d\n",nn,j);
				nn = nn / j;
				j++;
			}
			if(num>maxn){
				maxn = num;
				ans = i;
			}
		}
	}
	if(maxn==0){
		printf("1\n");
		printf("%d",n);
		return 0;
	}
	printf("%d\n",maxn);
	for(int i=0;i<maxn-1;i++){
		printf("%d*",ans+i);
	}
	if(maxn>0) printf("%d",ans+maxn-1);
} 
