#include<stdio.h>
#include<vector>
#include<string> 
#include<iostream>
#include<set>
using namespace std;

int n,m,s;
vector<string> nameList;


int main(){
	scanf("%d %d %d",&n,&s,&m);
	for(int i=0;i<n;i++){
		char temp[30];
		scanf("%s",temp);
		string s = temp;
		nameList.push_back(s);
	}
	int l = nameList.size();
	int i = m;
	set<string> winners;
	if(m>n){
		printf("Keep going...\n");
		return 0;
	}else{
		while(i<=n){
			//printf("%d %s\n",i,nameList[i-1].c_str());
			if(winners.find(nameList[i-1])==winners.end()){
				winners.insert(nameList[i-1]);
				printf("%s\n",nameList[i-1].c_str());
			}else{
				i++;
				continue;
			}
			i = i+s;
		}
	}
}
 
