#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
#define N 2002
int n,m;
string id[N];
int c[N],ma[N],e[N],a[N];
int rc[N],rma[N],re[N],ra[N];

int makerank(int x[N],int op[N]){
	int flag[101];
	for(int i=0;i<=100;i++) flag[i] = 0;
	for(int i=0;i<n;i++){
		flag[x[i]]+=1;
		op[i] = 0;
	}
	int sum=0;
	for(int i=100;i>=0;i--){
		if(flag[i]>0){
		    op[i] = sum+1;
			sum=sum+flag[i];	
		}
	}
}

string qu[N];

string calrank(int x){
	int ranka = ra[a[x]];
	int rankc = rc[c[x]];
	int rankma = rma[ma[x]];
	int ranke = re[e[x]];
	int min = ranka;
	char k = 'A';
	if(rankc<min){
		min = rankc;
		k = 'C';
	}
	if(rankma<min){
		min = rankma;
		k = 'M';
	}
	if(ranke<min){
		min = ranke;
		k = 'E';
	}
	stringstream ss;
	ss<<min<<" "<<k;
	return ss.str();
	
}
int ffind(string st){
	for(int i=0;i<n;i++){
		if(id[i]==st) return i;
	}
	return -1;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>id[i]>>c[i]>>ma[i]>>e[i];
		a[i] = (c[i]+ma[i]+e[i]) / 3;
	}
	for(int i=0;i<m;i++){
		cin>>qu[i];
	}
	makerank(c,rc);
	makerank(ma,rma);
	makerank(e,re);
	makerank(a,ra);
	for(int i=0;i<m;i++){
		int index = ffind(qu[i]);
		if(index == -1) cout<<"N/A"<<endl;
		else cout<<calrank(index)<<endl;
	}
} 
