#include<stdio.h>
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
#define N 100001
int n,m;
stack<int> st;
int bit[N];
char temp[30];

int lowbit(int p){
	return p&(-p);
}
int update(int p,int dealta){
	for(int i=p;i<=N;i=i+lowbit(i)){
		bit[i]+=dealta;
	}
}
int cal_sum(int p){
	int ans=0;
	for(int i=p;i>0;i=i-lowbit(i)){
		ans+=bit[i];
	}
	return ans;
}
int peek(){
	int l = st.size();
	int index = 0;
	if(l%2==0) index = l/2;
	else index = (l+1)/2;
	int x=1,y=N-1;
	int bg=-1;
	while(x<=y){
		int mid = (x+y)/2;
		int ans = cal_sum(mid);
		//cout<<x<<" "<<y<<" "<<ans<<endl;
		if(ans>=index){
			bg = mid;
			y = mid-1;
		}else{
			x = mid + 1;
		}
	}
	return bg;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		if(temp[1]=='o'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n",st.top());
				update(st.top(),-1);
				st.pop();
			}
		}
		if(temp[1]=='u'){
			int num;
			scanf("%d",&num);
			update(num,1);
			st.push(num);
		}
		if(temp[1]=='e'){
			if(st.empty()) printf("Invalid\n");
			else printf("%d\n",peek());
		}
	}
}
