#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector<long long> a;
long long n,p;
vector<int> jump;
bool mycmp(int x,int y){
	return x<y;
}

int find(int x,int y,long long p){
	if(x==y) return x;
	int mid = (x+y)/2;
	if(a[mid]==p) return mid;
	if(a[mid]>p) return find(x,mid-1,p);
	else return find(mid+1,y,p);
}

int find2(int x,int y,long long p){
	//if(x==y) return x;
	while(x<=y){
		if(x==y) return x;
		int mid = (x+y)/2;
		if(a[mid]==p) return mid;
		if(a[mid]>p) y = mid - 1;
		else x = mid + 1;
	}
	return x;
}



int main(){
	scanf("%d %ld",&n,&p);
	for(int i=0;i<n;i++){
		long x;
		scanf("%ld",&x);
		a.push_back(x);
	}
	sort(a.begin(),a.end(),mycmp);
	int ans = 0;
	int i=0;
	for(int i=0;i<n;i++){
		if(ans>=n-1-i+1) break;
		long long m = a[i]*p;
		int k = find2(0,n-1,m);
		//printf("k=%d\n",k);
		//while(k+1<n&&a[k]==a[k+1]) k++;
		if(k+1<n&&a[k+1]<=m) k++;
		if(a[k]<=m&&k-i+1>ans) ans = k-i+1;
	}
	printf("%d",ans);
}
