#include<stack>
#include<vector>
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
#define N 50
char temp[100];
string s;
stack<int> st;
int n;
vector<int> pre,ino;

int leftn[N],rightn[N];
int position[N];
int buildtree(int x,int y){
	if(x==y) return ino[x];
	if(x>y) return -1;
	//printf("x=%d,y=%d\n",x,y);
	int minp = 100;
	int pp = -1;
	for(int i=x;i<=y;i++){
		int key = ino[i];
		if(position[key]<minp){
			minp = position[key];
			pp = i;
		}
	}
	int k = ino[pp];
	//printf("k=%d position[k]=%d\n",k,position[k]);
	leftn[k] = buildtree(x,pp-1);
	rightn[k] = buildtree(pp+1,y);
	//printf("l=%d r=%d x=%d y=%d \n",leftn[k],rightn[k],x,y);
	return k;
}

vector<int> ans;

void tranverse(int p){
	if(leftn[p]!=-1) tranverse(leftn[p]);
	if(rightn[p]!=-1) tranverse(rightn[p]);
	ans.push_back(p);
}

int main(){
	cin>>n;
	for(int i=0;i<N;i++) position[i]=-1;
	for(int i=0;i<2*n;i++){
		int k;
		cin>>s;
		if(s=="Push"){
			cin>>k;
			st.push(k);
			pre.push_back(k);
			position[k] = pre.size()-1;
		}else{
			int t = st.top();
			ino.push_back(t);
			st.pop();
		}
	}
	
	for(int i=0;i<N;i++) rightn[i]=leftn[i]=-1;
	int root = buildtree(0,n-1);
	tranverse(root);
	for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
	printf("%d",ans[n-1]);
	
}
