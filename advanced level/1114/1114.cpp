#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 10000

vector<int> map[N];
int n;
int es_area[N],es_sets[N];
bool isVisited[N];

int total_sets=0;
int total_area=0;
int total_num = 0;
int min_id=-1;
bool ispeople[N];

struct rec{
	int fid;
	double avg_area;
	double avg_sets;
	int tol;
};

vector<rec> a;

bool mycmp(rec x,rec y){
	if(x.avg_area!=y.avg_area) return x.avg_area>y.avg_area;
	return x.fid<y.fid;
}

void dfs(int p){
	isVisited[p] = true;
	if(min_id==-1||p<min_id){
		min_id = p;
	}
	total_num++;
	total_sets += es_sets[p];
	total_area += es_area[p];
	int l = map[p].size();
	for(int i=0;i<l;i++){
		int x = map[p][i];
		if(!isVisited[x]){
			dfs(x);
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<N;i++){
		es_area[i] = 0;
		es_sets[i] = 0;
		isVisited[i] = false;
		ispeople[i] = false;
	}
	for(int i=0;i<n;i++){
		int fa,mo,x,y;
		scanf("%d %d %d",&x,&fa,&mo);
		if(fa!=-1) ispeople[fa]=true;
		if(mo!=-1) ispeople[mo]=true;
		int id = x;
		ispeople[id] = true;
		if(fa!=-1){
			map[id].push_back(fa);
			map[fa].push_back(id);
		}
		if(mo!=-1){
			map[id].push_back(mo);
			map[mo].push_back(id);
		}
		scanf("%d",&x);
		for(int i=0;i<x;i++){
			scanf("%d",&y);
			map[id].push_back(y);
			map[y].push_back(id);
			ispeople[y]=true;
		}
		scanf("%d %d",&es_sets[id],&es_area[id]);
	}
	for(int i=0;i<N;i++){
		if(ispeople[i]&&!isVisited[i]){
			total_sets = 0;
			total_area = 0;
			total_num = 0;
			min_id = -1;
			rec temp;
			dfs(i);
			temp.fid = min_id;
			temp.avg_area = double(total_area)/total_num;
			temp.avg_sets = double(total_sets)/total_num;
			temp.tol = total_num;
			a.push_back(temp);
		}
	}
	sort(a.begin(),a.end(),mycmp);
	int l = a.size();
	printf("%d\n",l);
	for(int i=0;i<l;i++){
		printf("%04d %d %.3lf %.3lf\n",
		a[i].fid,a[i].tol,a[i].avg_sets,a[i].avg_area);
	}
} 
