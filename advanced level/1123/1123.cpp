#include<vector>
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
#define N 30
int n;

int leftn[N],rightn[N],v[N],height[N];
bool isc = true;
bool node_end = false;


int maxh(int x,int y){
	int xh,yh;
	if(x==-1) xh = 0; else xh = height[x];
	if(y==-1) yh = 0; else yh = height[y];
	if(xh>yh) return xh;
	else return yh;
}

int geth(int p){
	if(p==-1) return 0;
	return height[p];
}

int ll(int p){
	int lc = leftn[p];
	int rc = rightn[p];
	int lcrc = rightn[lc];
	rightn[lc] = p;
	leftn[p] = lcrc;
	height[p] = maxh(leftn[p],rightn[p]) + 1;
	height[lc] = maxh(leftn[lc],rightn[lc]) + 1;
	return lc;
}

int rr(int p){
	int lc = leftn[p];
	int rc = rightn[p];
	int rclc = leftn[rc];
	leftn[rc] = p;
	rightn[p] = rclc;
	height[p] = maxh(leftn[p],rightn[p]) + 1;
	height[rc] = maxh(leftn[rc],rightn[rc]) + 1;
	return rc;
}

int lr(int p){
	int lc = leftn[p];
	int rc = rightn[p];
	leftn[p] = rr(lc);
	height[p] = maxh(leftn[p],rightn[p]) + 1;
	return ll(p);
}

int rl(int p){
	int lc = leftn[p];
	int rc = rightn[p];
	rightn[p] = ll(rc);
	height[p] = maxh(leftn[p],rightn[p]) + 1;
	return rr(p);
}
vector<int> ans;
int bfs(int root){
	queue<int> st;
	st.push(root);
	while(!st.empty()){
		int p = st.front();
		ans.push_back(v[p]);
		if(leftn[p]==-1) node_end = true;
		else{
			if(node_end) isc = false;
			st.push(leftn[p]);

		}
		if(rightn[p]==-1) node_end = true;
		else{
			if(node_end) isc = false;
			st.push(rightn[p]);

		}
		st.pop();
	}
}


int buildAVL(int now,int p){
	//printf("now=%d p=%d\n",now,p);
	int old_now = now;
	if(now == -1){
		return p;
	}
	if(v[p]<v[now]){
		if(leftn[now]==-1){
			leftn[now] = p;
		}else{
			leftn[now] = buildAVL(leftn[now],p);
		}
		int lc = leftn[now];
		int rc=rightn[now];
		if(geth(lc)>geth(rc)+1){
			int lclc = leftn[lc];
			int lcrc = rightn[lc];
			if(geth(lclc)==geth(rc)+1) now = ll(now);
			else now = lr(now);
			//rintf("oldn=%d newn=%d p=%d\n",old_now,now,p);
		}
	}else{
		if(rightn[now]==-1){
			rightn[now] = p;
		}else{
			rightn[now] = buildAVL(rightn[now],p);
		}
		int lc = leftn[now];
		int rc=rightn[now];
		if(geth(rc)>geth(lc)+1){
			int rcrc = rightn[rc];
			int rclc = leftn[rc];
			if(geth(rcrc)==geth(lc)+1) now = rr(now);
			else now = rl(now);
			//printf("oldn=%d newn=%d p=%d\n",old_now,now,p);
		}
	}
	height[now] = maxh(leftn[now],rightn[now]) + 1;
	//printf("final now=%d p=%d\n",now,p);
	return now;
}

int preorder(int p){
	printf("%d ",v[p]);
	if(leftn[p]!=-1) preorder(leftn[p]);
	if(rightn[p]!=-1) preorder(rightn[p]);
}

int main(){
	int root = -1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		leftn[i]=rightn[i]=-1;
		height[i]=0;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v[i] = x;
		height[i] = 1;
		root = buildAVL(root,i);
	}
	bfs(root);
	for(int i=0;i<n-1;i++){
		printf("%d ",ans[i]);
	}
	printf("%d\n",ans[n-1]);
	if(isc) printf("YES");
	else printf("NO");
} 
