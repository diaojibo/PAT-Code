#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;

int k,p,n;
vector<int> final_ans;

long long mypower(long long x,long long y){
	long long z;
	z = 1;
	for(int i=0;i<y;i++) z*=x;
	return z;
}

int sumV(vector<int> x){
	int l,sum=0;
	l = x.size();
	for(int i=0;i<l;i++) sum+=x[i];
	return sum;
}

bool bigger(vector<int> x,vector<int> y){
	int xx,yy;
	xx = sumV(x);
	yy = sumV(y);
	if(xx!=yy) return xx>yy;
	xx = x.size()-1;
	yy = y.size()-1;
	while(xx>=0 && yy>=0){
		if(x[xx]==y[yy]){
			xx--;yy--;
			continue;
		}
		return x[xx]>y[yy];
	}
	if(xx>=0) return true;
	else return false;
}

vector<int> dfs(int n,int k,int p,int upline){
	vector<int> answer;
	if(k==1){
		for(int i=upline;i>0;i--)
		{
			long long x; 
			x = mypower(i,p);
			if(x==n){
				answer.push_back(i);
				return answer;
			}
		}
		return answer;
	}else{
		vector<int> temp;
		for(int i=upline;i>0;i--){
			long long x; 
			x = mypower(i,p);
			if(x>=n) continue;
			temp = dfs(n-x,k-1,p,i);
			if(temp.empty()) continue;
			temp.push_back(i);
			if(answer.empty()||bigger(temp,answer)){
				answer = temp;
			}

		}
		return answer;
	}

}

string getstring(vector<int> x){
	int l;
	l = x.size();
	char temp[100];
	sprintf(temp,"%d^%d",x[l-1],p);
	string st = string(temp);
	for(int i=l-2;i>=0;i--){
		sprintf(temp,"%d^%d",x[i],p);
		st = st + " + "+temp;
	}
	return st;
}

int main(){
	scanf("%d %d %d",&n,&k,&p);
	final_ans = dfs(n,k,p,n);
	string stt;
	if(final_ans.empty()){
		printf("Impossible");
	}else{
		stt = getstring(final_ans);
		printf("%d = %s",n,stt.c_str());
	}
}