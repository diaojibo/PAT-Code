#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int left;
	int right;
};

int n;
node tree[25];

int main(){
	int flag[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{

		char tempx[5],tempy[5];
		int tl,tr;
		scanf("%s %s",&tempx,&tempy);
		if(tempx[0]=='-'){
			tree[i].left = -1;
		}else{
			sscanf(tempx,"%d",&tl);
			flag[tl] = 1;
			tree[i].left = tl;
		}
		if(tempy[0]=='-'){
			tree[i].right = -1;
		}else{
			sscanf(tempy,"%d",&tr);
			flag[tr] = 1;
			tree[i].right = tr;
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(flag[i]!=1) root = i;
	}

	queue<int> q;
	q.push(root);
	int now;
	bool isc = true;
	bool ifleave = false;
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(tree[now].left != -1 || tree[now].right!=-1){
			if(ifleave){
				isc = false;
				break;
			}
			if(tree[now].left !=-1) q.push(tree[now].left);
			if(tree[now].right !=-1) q.push(tree[now].right);
			if(tree[now].right!=-1 && tree[now].left==-1){
				isc = false;
				break;
			}
			if(tree[now].left==-1 || tree[now].right==-1){
				ifleave = true;
			}
		}else{
			ifleave = true;
		}

	}
	if(isc){
		cout<<"YES "<<now;
	}else{
		cout<<"NO "<<root;
	}


	return 0;
}