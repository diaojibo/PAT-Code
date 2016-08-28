#include<stdio.h>

using namespace std;
int f[10001];
int num[10001];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<10001;i++) f[i] = 0,num[i]=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		f[x]++;
		num[x]=i+1;
	}
	bool isfind = false;
	int ans,minn = -1;
	for(int i=0;i<10001;i++){
		if(f[i]==1){
			if(minn==-1||num[i]<minn){
				isfind = true;
				ans = i;
				minn = num[i];
			}
		}
	}
	if(!isfind) printf("None");
	else printf("%d",ans);
}
