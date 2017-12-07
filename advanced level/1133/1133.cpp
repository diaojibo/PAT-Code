#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define N 100005

struct node{
	int value;
	int address,nextAdd;
	int order;
};
int n,m,k,s;
int mem[N];
vector<node> v,ans;

bool mycmp(node x,node y){
	if(x.value<0&&y.value>=0) return true;
	if(x.value>=0&&y.value<0) return false;
	if(x.value>=0&&y.value>=0){
		if(x.value<=k&&y.value>k) return true;
		if(x.value>k&&y.value<=k) return false;
	}
	return x.order<y.order;
}

int main(){
	scanf("%d %d %d",&s,&n,&k);
	for(int i=0;i<n;i++){
		node temp;
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		temp.address = x;
		temp.value = y;
		temp.nextAdd = z;
		mem[x] = i;
		v.push_back(temp);
	}
	
	int head = mem[s];
	v[head].order = 0;
	int o = 0;
	ans.push_back(v[head]);
	while(v[head].nextAdd!=-1){
		int nextadd = v[head].nextAdd;
		o++;
		//printf("order:%d value:%d\n",v[head].order,v[head].value);
		head = mem[nextadd];
		v[head].order = o;
		ans.push_back(v[head]);
	}
	sort(ans.begin(),ans.end(),mycmp);
	int l = ans.size();
	for(int i=0;i<l-1;i++){
		printf("%05d %d %05d\n",ans[i].address,ans[i].value,ans[i+1].address);
	}
	if(l>0){
		printf("%05d %d -1\n",ans[l-1].address,ans[l-1].value);
	}
	
}
