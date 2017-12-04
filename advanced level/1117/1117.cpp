#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;

vector<int> v;
int n,m,ans;

bool mycmp(int x,int y){
	return x<y;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),mycmp);
	int e=0;
	bool isfind = false;
	for(int i=0;i<n;i++){
		e = n-i;
		if(v[i]>e){
			printf("%d\n",e);
			isfind = true;
			break;
		} 
	}
	
	if(!isfind) printf("0\n");
	
} 
