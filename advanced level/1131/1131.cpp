#include<stdio.h>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
#define N 20002


struct edge{
	int source,target;
	int next;
	int line;
};

struct record{
	int now;
	int prevRecord;
	int line;
	int transfer;
	int stops;
};

int n,m,el,q;
int link[N];
edge e[N];
bool flag[101][10001];
vector<string> ans;
int ansTransfer,ansStop;

void addEdge(int x,int y,int line){
	edge temp;
	temp.source = x;
	temp.target = y;
	temp.line = line;
	temp.next = link[x];
	link[x] = el;
	e[el] = temp;
	el++;
}

void init(){
	for(int i=0;i<101;i++)
	for(int j=0;j<10001;j++) flag[i][j]=false;
}

void bfs(int source,int dest){
	vector<record> que;
	bool isFindOne = false;
	ans.clear();
	init();
	record first;
	first.line = -1;
	first.now = source;
	first.prevRecord = -1;
	first.transfer = 0;
	first.stops = 0;
	que.push_back(first);
	int nowIndex = 0;
	int ql=1;
	ansStop = -1;
	while(nowIndex<=ql){
		record nowRec;
		int nowStop,nowPrev,nowLine,nowTransfer,nowStep;
		nowRec = que[nowIndex];
		nowStop = nowRec.now;
		nowPrev = nowRec.prevRecord;
		nowLine = nowRec.line;
		nowTransfer = nowRec.transfer;
		nowStep = nowRec.stops;
		if(ansStop!=-1&&nowStep>ansStop) break;
		if(nowStop==dest){ //find 
			 if(!isFindOne){ //not fine before
			 	int j = nowIndex;
			 	while(que[j].prevRecord!=-1){
			 		int jj = que[j].prevRecord;
			 		string st;
			 		char temps[100];
				 	sprintf(temps,"Take Line#%d from %04d to %04d",que[j].line,que[jj].now,que[j].now);
			 		st = temps;
					 ans.push_back(st);
			 		j = que[j].prevRecord;
			 	}
			 }else{ //find before
			 	if(nowTransfer<ansStop){
			 		int j = nowIndex;
			 		while(que[j].prevRecord!=-1){
			 		int jj = que[j].prevRecord;
			 		string st;
			 		char temps[100];
				 	sprintf(temps,"Take Line#%d from %04d to %04d",que[j].line,que[jj].now,que[j].now);
			 		st = temps;
			 		ans.push_back(st);
			 		j = que[j].prevRecord;
				 }
			 }
			}
		}else{ //not find
			int j = link[nowStop];
			while(j!=-1){
				int n_des = e[j].target;
				int n_line = e[j].line;
				if(n_line==nowLine){//sameline
					if(!flag[nowTransfer][n_des]){
						record t;
						t.prevRecord = nowPrev;
						t.line = n_line;
						t.stops = nowStep+1;
						t.now = n_des;
						t.transfer = nowTransfer;
						flag[nowTransfer][n_des] = true;
						ql++;
						que[ql]=t;
					}
				}else{ //not same line
					if(!flag[nowTransfer+1][n_des]){
						record t;
						t.prevRecord = nowIndex;
						t.line = n_line;
						t.stops = nowStep+1;
						t.now = n_des;
						t.transfer = nowTransfer+1;
						flag[nowTransfer+1][n_des] = true;
						ql++;que[ql]=t;
					}
				}
				j = e[j].next;
			}
			
		}
		nowIndex++;
	}
	printf("%d\n",ansStop);
	int l = ans.size();
	for(int i=l-1;i>=0;i++){
		printf("%s\n",ans[i].c_str());
	}
}

int main(){
	scanf("%d",&n);
	vector<int> temp;
	for(int i=0;i<N;i++) link[i]=-1;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		temp.clear();
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			temp.push_back(x);
		}
		int prev;
		prev = temp[0];
		for(int j=1;j<m;j++){
			addEdge(temp[j-1],temp[j],i+1);
			addEdge(temp[j],temp[j-1],i+1);
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
	}
} 
