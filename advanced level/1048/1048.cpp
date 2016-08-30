#include<vector>
#include<stdio.h>

using namespace std;
int n,m;
int a[1001];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<1001;i++) a[i] = 0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	bool isfind = false;
	int ans;
	for(int i=0;i<1001;i++){
		if(i>m) break;
		a[i]--;
		if(a[i]>=0&&a[m-i]>0){
			isfind = true;
			ans = i;
			break;
		}
		a[i]++;
	}
	if(isfind) printf("%d %d",ans,m-ans);
	else printf("No Solution");
} 
