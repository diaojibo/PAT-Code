#include<stdio.h>
#include<vector>
using namespace std;
#define N 1000
#define M 32
int n,m;
int pos[N];
int pre[M],post[M];
int ans_num=0;
vector<int> ans;
int ln[M],rn[M];
bool is_unique=true;

void dfs(int p){
	if(ln[p]!=-1) dfs(ln[p]);
	ans.push_back(pre[p]);
	if(rn[p]!=-1) dfs(rn[p]);
}

void put(int p,int num){
	//printf("%d %d number=%d\n",p,num-1,pre[num-1]);
	if(!is_unique) return;
	if(num>n){
		if(ans_num>0){
			is_unique = false;
			return;
		}
		dfs(0);
		ans_num++;
		return;
	}
	int now = pre[p];
	int x = pre[num-1];
	if(pos[x]<pos[now]){
		if(ln[p]==-1){
			if(rn[p]==-1){
				ln[p]=num-1;
			    put(0,num+1);
			    ln[p] = -1;
				rn[p]=num-1;
				put(0,num+1);
				rn[p]=-1;	
			}else{
				put(rn[p],num);
			}
		}else{
			if(rn[p]==-1){
				put(ln[p],num);
				rn[p]=num-1;
				put(0,num+1);
				rn[p]=-1;
			}else{
				put(rn[p],num);
			}
			
		}
	}else return;
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
		ln[i]=rn[i]=-1;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
		pos[post[i]] = i;
	}
	put(0,2);
	if(is_unique){
		printf("Yes\n");
		for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
		if(n>0) printf("%d\n",ans[n-1]);
	}else{
		printf("No\n");
		for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
		if(n>0) printf("%d\n",ans[n-1]);
	}
} 
