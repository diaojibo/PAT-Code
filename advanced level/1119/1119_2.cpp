#include<stdio.h>
#include<vector>
using namespace std;

#define N 35

int inOrder[N];
int postOrder[N],preOrder[N];
int left[N],right[N];
int position[100000];
int n;
bool isUnique = true;
int isFind = 0;
vector<int> ans;

void dfs(int position){
	if(left[position]!=-1) dfs(left[position]);
	ans.push_back(preOrder[position]);
	if(right[position]!=-1) dfs(right[position]);
}


void insertTree(int parentPos,int nodePos){
	//printf("x:%d y:%d\n",parentPos,nodePos);
	if(nodePos >= n){
		isFind++;
		//printf("isfind:%d \n",isFind);
		if(isFind>1){
			isUnique = false;
			printf("No\n");
			dfs(0);
			for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
			printf("%d\n",ans[n-1]);
			return;
		}else{
			dfs(0);
		}
		return;
	}
	if(!isUnique) return;
	
	int parentValue = preOrder[parentPos];
	int nodeValue = preOrder[nodePos];
	//printf("%d %d\n",parentValue,nodeValue);
	if(position[parentValue]<position[nodeValue]) return;
	
	//left tree is empty
	if(left[parentPos]==-1){
		if(right[parentPos]==-1){
			left[parentPos] = nodePos;
			insertTree(0,nodePos+1);
			left[parentPos] = -1;
			right[parentPos] = nodePos;
			insertTree(0,nodePos+1);
			right[parentPos] = -1;
		}else{
			insertTree(right[parentPos],nodePos);
		}
	}else{ //left tree is not empty
		insertTree(left[parentPos],nodePos);
		if(right[parentPos]==-1){
			right[parentPos] = nodePos;
			insertTree(0,nodePos+1);
			right[parentPos] = -1;
		}else{
			insertTree(right[parentPos],nodePos);
		}
	}
}


int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&preOrder[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&postOrder[i]);
		position[postOrder[i]] = i;
	}	
	for(int i=0;i<n;i++) left[i]=right[i]=-1;
	if(n==1){
		printf("Yes\n");
		printf("%d\n",preOrder[0]);
		return 0;
	}
	if(n>1) insertTree(0,1);
	if(isUnique){
		printf("Yes\n");
		for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
		printf("%d\n",ans[n-1]);
	}
}
