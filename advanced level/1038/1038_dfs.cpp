#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;
string b[10001];
int blen = 0;
vector<string> a;
string ans;
int n,m;
char temp[20];
bool isVisited[10001];
bool findanswer = false;
string answer  = "";
bool mcmp(string x,string y){
  return x<y;
}

bool myjd(int p){
	if(p>=n-1) return false;
	string a1 = a[p];
	string a2 = a[p+1];
	int l1 = a1.length();int l2 = a2.length();
	int ll;
	if(l1<l2) ll=l1;
	else ll=l2;int pp=0;
	while(pp<ll){
		if(a[p][pp]<a[p+1][pp]) return true;
		pp++;
	} 
	return false;
}

bool judge(){
  string ss="";
  for(int i=0;i<blen;i++){
    ss+=b[i];
  }
  return ss<answer;
}
void giveanswer(){
  string ss;
  for(int i=0;i<blen;i++){
    ss+=b[i];
  }
  answer = ss;
}

void dfs(int p,int level){
  isVisited[p] = true;
  //cout<<level<<" "<<a[p]<<endl;
  b[blen]=a[p];blen++;
  if(level==n){
    if(!findanswer||judge()){
      findanswer = true;
      giveanswer();
      blen--;isVisited[p]=false;
      return;
    }
  }
  if(findanswer){
    if(!judge()){
      isVisited[p] = false;
      blen--;
      return;
    }
  }
  for(int i=0;i<n;i++){
    if(!isVisited[i]){
      dfs(i,level+1);
      if(myjd(i)) break; 
    }
  }
  blen--;isVisited[p]=false;
  return;
}


int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int x;
    scanf("%s",&temp);
    a.push_back(string(temp));
    isVisited[i] = false;
  }
  sort(a.begin(),a.end(),mcmp);
  for(int i=0;i<n;i++){
    dfs(i,1);
    if(myjd(i)) break; 
  }
  //printf("%s",answer.c_str());
  int l = answer.length();
  int pp=0;
  while(answer[pp]=='0') pp++;
  if(pp<l) for(int i=pp;i<l;i++) printf("%c",answer[i]);
  else printf("0");
}
