#include<vector>
#include<stdio.h>
using namespace std;
#define N 100
struct node{
	int h;
	int l,r;
	int v;
};
int n,m; 
node tree[N];
int geth(int p){
	if(p==-1) return 0;
	else return(tree[p].h);
}
int mmax(int x,int y){
	if(x>y) return x;
	else return y;
}
void updateh(int p){
	tree[p].h = 1+mmax(geth(tree[p].l),geth(tree[p].r));
}
int ll(int root){
	if(root == -1) return -1;
	int l = tree[root].l;
	tree[root].l = tree[l].r;
	tree[l].r = root;
	updateh(root);updateh(l);
	return l;
}

int rr(int root){
	if(root == -1) return -1;
	int r = tree[root].r;
	tree[root].r = tree[r].l;
	tree[r].l = root;
	updateh(root);updateh(r);
	return r;
}

int lr(int root){
	if(root == -1) return -1;
	tree[root].l = rr(tree[root].l);
	return ll(root);
}
int rl(int root){
	if(root==-1) return -1;
	tree[root].r = ll(tree[root].r);
	return rr(root);
}
int tinsert(int root,int p){
	int troot = root;
	//printf("root %d insert %d value %d h %d\n",root,p,tree[p].v,tree[root].h);
	if(root==-1) return p;
	//printf("left %d right %d\n",tree[root].l,tree[root].r);
	 if(tree[p].v<tree[root].v){
	 	tree[root].l = tinsert(tree[root].l,p);
	 	int nl = tree[root].l,nr = tree[root].r;
	 	if(geth(tree[nl].l)+1-geth(tree[root].r)>=2){
	 		root = ll(root);
		 }else if(geth(tree[nl].r)+1-geth(tree[root].r)>=2){
		 	root = lr(root);
		 }
	 }else{
	 	tree[root].r = tinsert(tree[root].r,p);
	 	int nl = tree[root].l,nr = tree[root].r;
	 	if(geth(tree[nr].r)+1-geth(tree[root].l)>=2){
	 		root = rr(root);
		 }else if(geth(tree[nr].l)+1-geth(tree[root].l)>=2){
		 	root = rl(root);
		 }
	 }
	 //tree[troot].h = 1+mmax(geth(tree[troot].l),geth(tree[troot].r));
	 tree[root].h = 1+mmax(geth(tree[root].l),geth(tree[root].r));
	 //printf("root %d insert %d value %d h %d\n",root,p,tree[p].v,tree[root].h);
	 //printf("root left %d right %d\n",tree[root].l,tree[root].r);
	 return root;
}

int main(){
	scanf("%d",&n);
	int ro = -1;
	for(int i=0;i<n;i++){
		node temp;
		temp.h = 1;temp.l = -1;
		temp.r = -1;
		scanf("%d",&temp.v);
		tree[i] = temp;
		ro = tinsert(ro,i);
	}
	printf("%d",tree[ro].v);
}
