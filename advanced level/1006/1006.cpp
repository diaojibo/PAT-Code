#include<string>
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>


using namespace std;
struct records{
	int hs,ms,ss;
	int he,me,se;
	string id;
};

bool compare_earlier(records x,records y){
	if(x.hs!=y.hs) return x.hs<y.hs;
	if(x.ms!=y.ms) return x.ms<y.ms;
	if(x.ss!=y.ss) return x.ss<y.ss;
	return false;
}
bool compare_later(records x,records y){
	if(x.he!=y.he) return x.he>y.he;
	if(x.me!=y.me) return x.me>y.me;
	if(x.se!=y.se) return x.se>y.se;
	return false;
}

int n;
vector<records> v;
char temp[100],t[100];
int main(){
	scanf("%d",&n);
	cin.get();
	for(int i=0;i<n;i++){
		records tr;
		cin.getline(t,100);
		sscanf(t,"%s %d:%d:%d %d:%d:%d",&temp,&tr.hs,&tr.ms,&tr.ss,&tr.he,&tr.me,&tr.se);
		tr.id = string(temp);
		v.push_back(tr);
	}
	bool blocker = false,bunlocker = false;
	records locker,unlocker;
	if(n>0) locker = unlocker = v[0];
	for(int i=1;i<n;i++){
		if(compare_later(v[i],locker)){
			locker = v[i];
		}
		if(compare_earlier(v[i],unlocker)){
			unlocker = v[i];
		}
	}
	cout<<unlocker.id<<" "<<locker.id;
	//cin>>n;
}