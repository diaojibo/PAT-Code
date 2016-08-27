#include<string>
#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

struct rec{
	string username;
	string pwd;
};

int n;
char tempx[20],tempy[20];
vector<rec> v;
char modify(char x){
	if(x=='1') return '@';
	if(x=='0') return '%';
	if(x=='l') return 'L';
	if(x=='O') return 'o';
	else return x;

}
int main(){
	scanf("%d",&n);
	rec temp;
	for(int i=0;i<n;i++){
		scanf("%s %s",&tempx,&tempy);
		temp.username = string(tempx);
		int p = 0;
		bool flag = false;
		while(tempy[p]!=0){
			char c;
			c = modify(tempy[p]);
			if(c!=tempy[p]) flag = true;
			tempy[p] = c;p++;
		}
		if(flag){
			temp.pwd = string(tempy);
			v.push_back(temp);
		}
	}
	int l = v.size();
	if(l>0){
		printf("%d\n",l);
		for(int i=0;i<l;i++){
			printf("%s %s\n",v[i].username.c_str(),v[i].pwd.c_str());
		}
	}else{
		if(n==1) printf("There is 1 account and no account is modified");
		else printf("There are %d accounts and no account is modified",n);
	}
} 
