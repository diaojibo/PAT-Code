#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 1001
int n,demand;
double amount[N];
double price[N];

struct mk{
	int type;
	double value;
};

vector<mk> a;

bool mycom(mk x,mk y){
	return x.value>y.value;
}

int main(){
	scanf("%d %d",&n,&demand);
	for(int i=0;i<n;i++){
		scanf("%lf",&amount[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&price[i]);
	}
	for(int i=0;i<n;i++){
		mk temp;
		temp.type = i;
		temp.value = price[i]/amount[i];
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),mycom);
	//double dd = double(demand);
	int dd = demand;
	int j=0;
	double ans = 0;
	while(dd>0&&j<n){
		if(dd>=amount[a[j].type]){
			dd = dd - amount[a[j].type];
			ans += price[a[j].type];
		}else{
			ans += dd*a[j].value;
			dd=0;
		}
		j++;
	}
	printf("%.2lf",ans+0.000001);
}
