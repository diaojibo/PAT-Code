#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,x,y;
vector<int> a,ans;
int al=0;
int left[1001],right[1001];
int tree[1001];
bool mycmp(int x,int y){
	return x<y;
}

void putnum(int p){
	if(p*2<=n) putnum(p*2);
	//printf("%d\n",p);
	tree[p] = a[al];al++;
	if(p*2+1<=n) putnum(p*2+1);
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a.push_back(x);
		left[i] = right[i] = -1;
	}
	sort(a.begin(),a.end(),mycmp);
	putnum(1);
	for(int i=1;i<=n-1;i++) printf("%d ",tree[i]);
	printf("%d",tree[n]);
}
