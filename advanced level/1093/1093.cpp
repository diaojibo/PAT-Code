#include<vector>
#include<stdio.h>
using namespace std;
#define N 100001

char s[N];
int pp=0;
int tp,ta,tt;
vector<int> vp,va,vt;
int npat[N],nat[N],nt[N];
long answer=0;

int main(){
	scanf("%s",&s);
	while(s[pp]!=0){
		if(s[pp]=='P'){
			vp.push_back(pp);
		}
		if(s[pp]=='A'){
			va.push_back(pp);
		}
		if(s[pp]=='T'){
			vt.push_back(pp);
		}
		pp++;		
	}
	int dp = pp-1;
	tp=0;ta=0;tt=0;
	while(dp>=0){
		if(s[dp]=='P') tp++;
		if(s[dp]=='A') ta++;
		if(s[dp]=='T') tt++;
		nt[dp]=tt;
		dp--;
	}
	dp = pp-1;
	int at = 0;
	for(int i=dp;i>=0;i--){
		if(s[i]=='A') at+=nt[i];
		nat[i] = at;
	}
	for(int i=dp;i>=0;i--){
		if(s[i]=='P') answer= (answer+nat[i])%1000000007;
	}

	printf("%ld",answer); 
}
