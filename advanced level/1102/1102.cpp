#include<iostream>
#include<vector>
#include<stdio.h>
#include<cstdio>
#include<stack>
using namespace std;

#define N 20
struct node{
	int left;
	int right;
};
int m,n;
node trees[N],itree[N];
bool flag[N];
vector<int> op1,op2;

void reverse_t(int p){
	int templ,tempr;
	templ = trees[p].left;
	tempr = trees[p].right;
	trees[p].left = tempr;
	trees[p].right = templ;
	if(templ!=-1) reverse_t(templ);
	if(tempr!=-1) reverse_t(tempr);
}

void level_order(int p){
	op1.push_back(p);
	int k=1;
	while(k<=op1.size()){
		int q = op1[k-1];
		if(trees[q].left!=-1) op1.push_back(trees[q].left);
		if(trees[q].right!=-1) op1.push_back(trees[q].right);
		k++;
	}
	
	
}

void in_order(int p){
	if(trees[p].left!=-1) in_order(trees[p].left);
	op2.push_back(p);
	if(trees[p].right!=-1) in_order(trees[p].right);
}

void myprint(vector<int> x){
	int l = x.size();
	if(l>0) cout<<x[0];
	for(int i=1;i<l;i++) cout<<" "<<x[i];
}

int main(){
	cin>>n;
	char x,y;
	int tx,ty;
    char tempx[10],tempy[10];
	for(int i=0;i<n;i++) flag[i] = true;
	for(int i=0;i<n;i++){
		scanf("%s %s",&tempx,&tempy);
		x = tempx[0];y=tempy[0];
		if(x=='-') trees[i].left = -1;
		else 
		{
			sscanf(tempx,"%d",&tx);
			trees[i].left = tx;
			flag[tx] = false;
		}
		if(y=='-') trees[i].right = -1;
		else {
			sscanf(tempy,"%d",&ty);
			trees[i].right = ty;
			flag[ty] = false;
		}
	}
	int root;
	for(int i=0;i<n;i++) if(flag[i]) root = i;
	reverse_t(root);
	in_order(root);
	level_order(root);
	myprint(op1);
	cout<<endl;
	myprint(op2);
	
}
