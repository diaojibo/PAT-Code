#include<stdio.h>
#include<vector>
using namespace std;

#define N 37

int flag[N];
vector<int> v;
vector<int> friendNumber;
int n,m;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		v.push_back(t);
		int fn;
		fn = 0;
		while(t!=0){
			fn += t%10;
			t = t/10;
		}
		friendNumber.push_back(fn);
		flag[fn]++;
	}
	vector<int> ans;
	for(int i=0;i<N;i++){
		if(flag[i]>0) ans.push_back(i);
	}
	int l = ans.size();
	printf("%d\n",l);
	for(int i=0;i<l-1;i++) printf("%d ",ans[i]);
	if(l>0) printf("%d\n",ans[l-1]);

}
