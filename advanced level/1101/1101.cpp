#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

#define N 100005
using namespace std;
long long maxn[N],minn[N],num[N];
long long n,tmax=-1,tmin=1000000001;
vector<long long> answer;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>num[i];
		maxn[i] = tmax;
		if(num[i]>tmax){
			tmax = num[i];
		}
	}
	for(int i=n-1;i>=0;i--){
		minn[i] = tmin;
		if(num[i]<tmin){
			tmin = num[i];
		}
	}
	for(int i=0;i<n;i++){
		if(num[i]>maxn[i] && num[i]<minn[i]){
			answer.push_back(num[i]);
		}
	}
	sort(answer.begin(),answer.end());
	int l = answer.size();
	if(l==0) cout<<0<<endl;
	else cout<<l<<endl;
	if(l>0) cout<<answer[0];
	for(int i=1;i<l;i++) cout<<" "<<answer[i];
	cout<<endl;
}
