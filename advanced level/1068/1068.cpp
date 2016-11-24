#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<iostream>
#define N 10001
#define M 101
using namespace std;
int n,m;
vector<int> coins;
int f[N][M][2];
int answer[N];
int ans[N];
int temp[N];
int ansn=0,tempn=0;

bool mcom(int x,int y){
	return x>y;
}
bool usmall(){
  int l;
  int l1 = ansn;
  int l2 = tempn;
  if(l1==0) return true;
  if(l1<l2) l = l1;
  else l = l2;
  for(int i=0;i<l;i++){
    if(temp[i]<ans[i]) return true;
    if(temp[i]>ans[i]) return false;
  }
  return l2<l1;
}

void work(int q,int p){
	//cout<<q<<" "<<p<<endl;
	if(p==0){
		if(usmall()){
			//ans = temp;
			ansn = tempn;
			for(int i=0;i<tempn;i++) ans[i] = temp[i];
		}
	}else{
		if(q<0) return;
		if(f[q][p][1]>0){
			tempn++;
			temp[tempn-1] = coins[q];
			work(q-1,p-coins[q]);
			tempn--;
		}
		else if(f[q][p][0]>0){
			work(q-1,p);
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		coins.push_back(x);
		f[i][0][0] = 1;
	}
	sort(coins.begin(),coins.end(),mcom);
	bool isfind = false;
	f[0][coins[0]][1] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=m;j++){
			if(f[i-1][j][0]>0){
				if(j+coins[i]<=m) f[i][j+coins[i]][1] = 1;
				f[i][j][0] = 1;
			}
			if(f[i-1][j][1]>0){
				if(j+coins[i]<=m) f[i][j+coins[i]][1] = 1;
				f[i][j][0] = 1;
			}
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=m;j++) cout<<f[i][j][1]<<" ";
//		cout<<endl;
//	}
	int start;
	for(int i=n-1;i>=0;i--){
		if(f[i][m][1]>0){
			work(i-1,m-coins[i]);
			isfind = true;
			start = coins[i];
			break;
		}
	}
	if(!isfind||m==0){
		printf("No Solution\n");
	}else{
		printf("%d",start);
		for(int i=0;i<ansn;i++){
			printf(" %d",ans[i]);
		}
	}
}
