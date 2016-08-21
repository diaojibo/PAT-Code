#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define N 32
#define NQ 9999
using namespace std;
struct node{
	int left,right;
};
int pt[N],it[N];
int n;
node trees[NQ];
int isroot(int x,int y){
	if(x>y) return -1;
	if(x==y) return x;
	for(int i=n-1;i>=0;i--){
		for(int j=x;j<=y;j++) if(it[j]==pt[i]) return j;
	}
}


void gotree(int x,int y){
	int r;
	if(x>y) return;
	r = isroot(x,y);
	//cout<<r<<" "<<it[r]<<" "<<x<<" "<<y<<endl;
	int ll,rr;
	ll = isroot(x,r-1);
	rr = isroot(r+1,y);
	if(ll!=-1) trees[it[r]].left = it[ll]; 
	if(rr!=-1) trees[it[r]].right = it[rr]; 
	
	gotree(x,r-1);
	gotree(r+1,y);
	
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pt[i];
		trees[i].left = -1;
		trees[i].right = -1;
	}
	for(int i=0;i<NQ;i++) trees[i].left = -1,trees[i].right = -1;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	int root = pt[n-1];
	int p=0;
	gotree(0,n-1);
	queue<int> st;
	st.push(root);
	vector<int> ans;
	while(!st.empty()){
		int x = st.front();
		ans.push_back(x);
		st.pop();
		//printf("%d %d\n",trees[x].left,trees[x].right);
		if(trees[x].left!=-1) st.push(trees[x].left);
		if(trees[x].right!=-1) st.push(trees[x].right);
	}
	int l = ans.size();
	if(l>0) cout<<ans[0];
	for(int i=1;i<l;i++) cout<<" "<<ans[i];
	
}
