#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
char cx[1001],cy[1001];
int f[1001][1001];
int main(){
  //scanf("%s",&cx);
  cin.getline(cx,1001);
  int pp=0;
  while(cx[pp]!=0) pp++;
  for(int i=0;i<pp;i++){
    cy[i] = cx[pp-i-1];
  }
  //printf("%s %s\n",cx,cy);
  cy[pp] = 0;
  f[0][0] = 0;
  int ans=0;
  for(int i=0;i<pp;i++)
  for(int j=0;j<pp;j++) f[i][j] = 0;
  for(int i=0;i<pp;i++){
    for(int j=0;j<pp;j++){
      int t;
      if(i>0&&j>0) t=f[i-1][j-1];
      else t = 0;
      if(cx[i]==cy[j]) f[i][j]=t+1;
      else f[i][j] = 0;
      if(f[i][j]>ans) ans = f[i][j];
    }
  }
  printf("%d",ans);
}
