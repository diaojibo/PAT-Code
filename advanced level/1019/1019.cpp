#include<string>
#include<vector>
#include<iostream>

using namespace std;
long long n,b;

vector<int> change(long long x,long long b){
	vector<int> a;
	if(x==0){
		a.push_back(0);
		return a;
	}
	while(x>0){
		a.push_back(x%b);
		x = x / b;
	
	}
	return a;
}

bool judge(vector<int> x){
	int k=0;
	int l = x.size();
	int i = l;
	while(i>0){
		if(x[k]!=x[l-1-k]) return false;
		i--;k++;
	}
	return true;
}
int main(){
	cin>>n>>b;
	vector<int> ans;
	ans = change(n,b);
	if(judge(ans)){
		cout<<"Yes"<<endl;
		int l = ans.size();
		if(l>0) cout<<ans[l-1];
		for(int i=l-2;i>=0;i--) cout<<" "<<ans[i];
	}else{
		cout<<"No"<<endl;
		int l = ans.size();
		if(l>0) cout<<ans[l-1];
		for(int i=l-2;i>=0;i--) cout<<" "<<ans[i];
	}
}
