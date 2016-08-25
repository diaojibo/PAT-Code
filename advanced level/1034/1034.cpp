#include<vector>
#include<map>
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 3001
int g[N][N];
int w[N];
int n,k,index;
char xs[10],ys[10];
string xx,yy;
map<string,int> m;
string names[N];
bool isVisited[N];
int total=0,maxw,as;
void dfs(int p){
	//cout<<p<<" ";
	isVisited[p] = true;
	total += w[p];
	as++;
	if(maxw==0||w[p]>w[maxw]){
		maxw = p;
	}
	for(int i=1;i<=index;i++){
		if(g[p][i]>0&&!isVisited[i]){
			dfs(i);
		}
	}
}
struct rec{
	string ss;
	int ans;
};
bool mycmp(rec x,rec y){
	return x.ss<y.ss;
}
int main(){
	scanf("%d %d",&n,&k);
	index = 0;
	for(int i=0;i<N;i++) w[i] = 0;
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++) g[i][j] = 0; 
	for(int i=0;i<n;i++){
		int x;
		scanf("%s %s %d",xs,ys,&x);
		xx = string(xs);yy=string(ys);
		if(m[xx]==0){
			index++;
			names[index] = xx;
			m[xx] = index;
		}
		if(m[yy]==0){
			index++;
			names[index] = yy;
			m[yy]=index;
		}
		g[m[xx]][m[yy]]+=x;g[m[yy]][m[xx]] += x;
		w[m[xx]]+=x;w[m[yy]]+=x;
	}
	for(int i=1;i<=index;i++){
		isVisited[i] = false;
	}
	//for(int i=1;i<=index;i++) cout<<names[i]<<endl;
	//cout<<g[1][2]<<endl;
	vector<int> a,b;
	int area = 0;
	for(int i=1;i<=index;i++){
		if(!isVisited[i]){
			total = 0;
			maxw = 0;as=0;
			dfs(i);
			if(total>k*2&&as>2){
				a.push_back(maxw);
				b.push_back(as);
			}
		}
	}
	int l = a.size();
	vector<rec> r;
	if(l==0) printf("0");
	else{
		printf("%d\n",l);
		rec rr;
		for(int i=0;i<l;i++){
			rr.ans = b[i];
			rr.ss = names[a[i]];
			r.push_back(rr);
			//printf("%s %d\n",names[a[i]].c_str(),b[i]);
		}
		sort(r.begin(),r.end(),mycmp);
		for(int i=0;i<l;i++){
			printf("%s %d\n",r[i].ss.c_str(),r[i].ans);
		}
	}
}
