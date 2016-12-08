#include<vector>
#include<stdio.h>
using namespace std;
#define N 100002
struct node{
	int next;
	int v;
	int add;
};

int n,m,k,head;
int flag[N];
bool isr[N];
vector<node> a,remove_list,ans_list;

int myabs(int x){
	if(x<0) return -x;
	else return x;
}

int main(){
	scanf("%d %d",&head,&n);
	for(int i=0;i<N;i++) flag[i] = -1,isr[i]=false;
	for(int i=0;i<n;i++){
		int x,y,v;
		node temp;
		scanf("%d %d %d",&x,&v,&y);
		temp.v = v;
		temp.add = x;temp.next = y;
		if(flag[x]==-1){
			flag[x] = i;
		}
		a.push_back(temp);
	}
	int p = head;
	while(p!=-1){
		int now = flag[p];
		int abv = myabs(a[now].v);
		if(!isr[abv]){
			isr[abv]=true;
			ans_list.push_back(a[now]);
		}else{
			remove_list.push_back(a[now]);
		}
		p = a[now].next;
	}
	int l1 = ans_list.size();
	int l2 = remove_list.size();
	for(int i=0;i<l1-1;i++){
		printf("%05d %d %05d\n",ans_list[i].add,ans_list[i].v,ans_list[i+1].add);
	}
	if(l1>0) printf("%05d %d %d\n",ans_list[l1-1].add,ans_list[l1-1].v,-1);
	for(int i=0;i<l2-1;i++){
		printf("%05d %d %05d\n",remove_list[i].add,remove_list[i].v,remove_list[i+1].add);
	}
	if(l2>0) printf("%05d %d %d\n",remove_list[l2-1].add,remove_list[l2-1].v,-1);
}
