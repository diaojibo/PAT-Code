#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

#define N 100000
int a[N],pos[N];
bool mright[N];
int n,m,rp=0;
stack<int> wrong;
int tol = 0;
void mswap(int x,int y){
	int t;
	tol++;
	if(a[x]==y) rp++,mright[y]=true;
	else mright[a[x]]=false,wrong.push(a[x]);
	if(a[y]==x) rp++,mright[x]=true;
	else mright[a[y]]=false,wrong.push(a[y]);
	pos[a[x]] = y;
	pos[a[y]] = x;
	t = a[x];
	a[x] = a[y];
	a[y] = t;
}

int main(){
	scanf("%d",&n);
	//cout<<n<<endl;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		pos[a[i]] = i;
		if(a[i]==i) rp++,mright[i]=true;
		else wrong.push(a[i]),mright[i]=false;
	}
	while(rp<n){
		//for(int i=0;i<n;i++) cout<<a[i]<<" ";
		//cout<<endl;
		if(a[0]==0){
			rp--;
			int j = 0;
			while(!wrong.empty()&&(wrong.top()==0||mright[wrong.top()])) wrong.pop();
			int w = wrong.top();
			wrong.pop();
			mswap(pos[0],pos[w]);
		}
		mswap(pos[0],pos[pos[0]]);
	}
	printf("%d",tol);
}
