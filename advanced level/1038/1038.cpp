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
string answer  = "";
bool mcmp(string x,string y){
	return x+y<y+x;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%s",&temp);
		a.push_back(string(temp));
	}
	sort(a.begin(),a.end(),mcmp);
	for(int i=0;i<n;i++) answer+=a[i];
	int pp=0;int l = answer.length();
	while(answer[pp]=='0'&&pp<l) pp++;
	if(pp>=l){
		printf("0");
	}else{
		for(int i=pp;i<l;i++) printf("%c",answer[i]);
	}
	

}
