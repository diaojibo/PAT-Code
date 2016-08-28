#include<vector>
#include<stdio.h>

using namespace std;

#define N 1001
int left[N],right[N];
int v[N];

int m,n;
int root;
vector<int> ori,porder,ans;
void initt(){
	for(int i=0;i<n;i++){
		left[i] = right[i] = -1;
	}
}

void putnode(int p,int r,bool flag){
	bool jud;
	jud = v[p]<v[r];
	if(!flag) jud = !jud;
	if(jud){
		if(left[r]==-1){
			left[r] = p;
			return;
		}else{
			putnode(p,left[r],flag);
		}
	}else{
		if(right[r]==-1){
			right[r]=p;
			return;
		}else{
			putnode(p,right[r],flag);
		}
	}
}

void dfs(int r){
	porder.push_back(v[r]);
	if(left[r]!=-1) dfs(left[r]);
	if(right[r]!=-1) dfs(right[r]);
}
void dfs2(int r){
	if(left[r]!=-1) dfs2(left[r]);
	if(right[r]!=-1) dfs2(right[r]);
	ans.push_back(v[r]);
}
bool isfind(vector<int>& a,vector<int>& b){
	int l1=a.size(),l2=b.size();
	if(l1!=l2) return false;
	for(int i=0;i<l1;i++) if(a[i]!=b[i]) return false;
	return true;
}
void myprint(vector<int>& x){
	int l = x.size();
	if(l>0) printf("%d",x[0]);
	for(int i=1;i<l;i++) printf(" %d",x[i]);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
		ori.push_back(v[i]);
	}
	initt();
	root = 0;
	for(int i=1;i<n;i++){
		putnode(i,root,true);
	}
	//for(int i=0;i<n;i++) if(left[i]!=-1) printf("%d ",v[left[i]]);
	//printf("\n");
	dfs(root);
	if(isfind(ori,porder)){
		printf("YES\n");
		dfs2(root);
		myprint(ans);
		return 0;
	}
	initt();
	for(int i=1;i<n;i++) putnode(i,root,false);
	porder.clear();
	dfs(root);
	if(isfind(ori,porder)){
		printf("YES\n");
		dfs2(root);
		myprint(ans);
		return 0;
	}
	printf("NO");
}
