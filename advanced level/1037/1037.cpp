#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m;
vector<int> pcou,ppr,ncou,npr;
bool cmp1(int x,int y){
	return x>y;
}
bool cmp2(int x,int y){
	return x<y;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>0) pcou.push_back(x);
		if(x<0) ncou.push_back(x); 
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		if(x>0) ppr.push_back(x);
		if(x<0) npr.push_back(x); 
	}
	int l1=0,l2=0;
	int p1=0,p2=0;
	int ans=0;
	l1 = pcou.size();l2=ppr.size();
	sort(pcou.begin(),pcou.end(),cmp1);
	sort(ppr.begin(),ppr.end(),cmp1);
	while(p1<l1&&p2<l2){
		ans+=pcou[p1]*ppr[p2];
		p1++;p2++;
	}
	l1 = ncou.size();l2=npr.size();
	p1=0;p2=0;
	sort(ncou.begin(),ncou.end(),cmp2);
	sort(npr.begin(),npr.end(),cmp2);
	while(p1<l1&&p2<l2){
		ans+=ncou[p1]*npr[p2];
		p1++;p2++;
	}
	printf("%d",ans);
}
