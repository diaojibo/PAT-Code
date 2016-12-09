#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n,m;
vector<int> a,b,c;

bool mycmp(int x,int y){
	return x<y;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),mycmp);
    int k,ans,gd;
	if(n%2==0){
		k = n/2 - 1;
		gd = 0;

	}else{
		k=n/2-1;
		gd = 1;
	}
	ans = 0;
	for(int i=0;i<=k;i++) ans=ans - a[i];
	for(int i=k+1;i<n;i++) ans = ans+a[i];
	printf("%d %d",gd,ans);
} 
