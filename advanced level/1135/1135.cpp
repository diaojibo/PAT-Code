#include<stdio.h>
using namespace std;

#define N 35

int n,m,o;
int preOrder[N];
int left[N],right[N];
int black_number;
bool isPass;
bool fbn;

void init(){
	for(int i=0;i<n;i++){
		right[i]=left[i]=-1;
	}
}

void dfs(int p,int bn){
	//printf("check dfs:%d %d\n",p,bn);
	if(!isPass) return;
	if(p==-1){
		//if(preOrder[p]>0) bn++;
		//printf("bn=%d\n",bn);
		if(fbn){
			fbn = false;
			black_number = bn;
		}else{
			if(black_number!=bn){
				isPass = false;
				return;
			}
		}
		return;
	}
	int value_p = preOrder[p];
	//printf("value_p: %d\n",value_p);
	if(left[p]!=-1){
		int value_left = preOrder[left[p]];
		if(value_left<0&&value_p<0){
			isPass = false;
			return;
		}
		if(value_p>0) dfs(left[p],bn+1);
		else dfs(left[p],bn);
	}else{
		if(value_p>0) dfs(left[p],bn+1);
		else dfs(left[p],bn);
	}
	if(right[p]!=-1){
		int value_right = preOrder[right[p]];
		if(value_right<0&&value_p<0){
			isPass = false;
			return;
		}
		if(value_p>0) dfs(right[p],bn+1);
		else dfs(right[p],bn);
	}else{
		if(value_p>0) dfs(right[p],bn+1);
		else dfs(right[p],bn);	
	}
}

bool check(){
	isPass = true;
	fbn = true;
	dfs(0,0);
}

int myabs(int x){
	if(x<0) return -x;
	else return x;
}

void putNode(int root,int node){
	int vRoot = myabs(preOrder[root]);
	int vNode = myabs(preOrder[node]);
	if(vNode<vRoot){
		if(left[root]==-1){
			left[root] = node;
		}else{
			putNode(left[root],node);
		}
	}else{
		if(right[root]==-1){
			right[root] = node;
		}else{
			putNode(right[root],node);
		}
	}
}

int main(){
	scanf("%d",&o);
	for(int q=0;q<o;q++){
		scanf("%d",&n);
		init();
		bool color;
		color = false;
		for(int j=0;j<n;j++){
			scanf("%d",&preOrder[j]);
			if(preOrder[j]<0) color = true;
		}
		for(int j=1;j<n;j++){
			putNode(0,j);
		}
		if(preOrder[0]<0){
			printf("No\n");
			continue;
		}
		check();
		if(n>1&&!color) isPass = false;
		if(isPass){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}
