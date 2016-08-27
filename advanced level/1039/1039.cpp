#include<string>
#include<vector>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int n,k,q,p,x;
char temp[10];
vector<int> m[27*27*27*11];
bool flag[2501];
bool mycmp(int x,int y){
	return x<y;
}
void initb(){
	for(int i=0;i<2501;i++) flag[i] = false;
}
int c2i(char x){
	if(x>='A'&&x<='Z') return int(x-'A');
	return int(x-'0');
}
int main(){
	//mm["asd"][1] = true;
	string sss = "asd";
	//bool w = mm[sss][100];
	//cout<<w<<" sad"<<endl;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		int index;
		scanf("%d %d",&index,&x);
		for(int j=0;j<x;j++){
			scanf("%s",&temp);
			int ind = c2i(temp[0])*26*26*10+c2i(temp[1])*26*10+c2i(temp[2])*10+c2i(temp[3]);
			//cout<<ind<<endl;
			m[ind].push_back(index);
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		string ss;
		ss = string(temp);
		int ind = c2i(temp[0])*26*26*10+c2i(temp[1])*26*10+c2i(temp[2])*10+c2i(temp[3]);
		int l = m[ind].size();
		printf("%s %d",temp,l);
		sort(m[ind].begin(),m[ind].end(),mycmp);
		for(int i=0;i<l;i++) printf(" %d",m[ind][i]);
		printf("\n");
	}
} 
