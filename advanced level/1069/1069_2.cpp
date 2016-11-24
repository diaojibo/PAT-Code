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
int f[N][M];
bool goes[N][M];
int answer[N];
int ans[N];
int temp[N];
int sum[N];
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

void work(int n,int p){
  if(p>sum[n]) return;
  if(p==0){
    if(usmall()){
      //ans = temp;
      ansn = tempn;
      for(int i=0;i<tempn;i++) ans[i] = temp[i];
    }
  }else{
    if(n<0) return;
    if(n>0 && f[n-1][p-coins[n]]>0){
      tempn++;
      temp[tempn-1] = coins[n];
      work(n-1,p-coins[n]);
      tempn--;
    }
    if(f[n-1][p]>0){
      work(n-1,p);
    }
  }
}

int main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    coins.push_back(x);
    f[i][0] = 1;
  }
  sort(coins.begin(),coins.end(),mcom);
  sum[0] = coins[0];
  for(int i=1;i<n;i++) sum[i] = coins[i] + sum[i-1];
  for(int i=0;i<n;i++)
    for(int j=0;j<=m;j++) goes[i][j] = false; 
  bool isfind = false;
  f[0][0] = 1;
  f[0][coins[0]] = 1;
  for(int i=1;i<n;i++){
    for(int j=0;j<=m;j++){
      //cout<<f[i][j]<<" ";
      if(f[i-1][j]>0){
        if(j+coins[i]<=m) f[i][j+coins[i]] = 1;
        f[i][j] = 1;
      }
    }
    //cout<<endl;
    if(f[i][m]>0){
      isfind = true;
      work(i,m);
    }
  }
  if(!isfind||m==0){
    printf("No Solution");
  }else{
    for(int i=0;i<ansn-1;i++){
      printf("%d ",ans[i]);
    }
    printf("%d",ans[ansn-1]);
  }
}
