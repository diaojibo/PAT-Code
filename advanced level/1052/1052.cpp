#include<vector>
#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define N 100001
struct node{
	long v;
	int address;
	int next;
};
bool mycmp(node x,node y){
	return x.v<y.v;
}
vector<node> a;
int n,k;
node m[N];
int head;
int main(){
	scanf("%d %d",&n,&head);
	for(int i=0;i<n;i++){
		long ad,v,next;
		node temp;
		scanf("%ld %ld %ld",&ad,&v,&next);
		m[ad].address = ad;
		m[ad].v = v;
		m[ad].next=next; 
	}
	while(head!=-1){
		a.push_back(m[head]);
		head = m[head].next;
	}
	sort(a.begin(),a.end(),mycmp);
	int l=a.size();
	if(l>0) printf("%d %05d\n",l,a[0].address);
	else printf("0 -1");
	for(int i=0;i<l-1;i++){
		printf("%05d %ld %05d\n",a[i].address,a[i].v,a[i+1].address);
	}
	if(l>0) printf("%05d %ld -1",a[l-1].address,a[l-1].v);
}
