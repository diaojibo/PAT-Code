#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 100001
struct user{
	int id;
	int score[5];
	//vector<int> score;
	int tol=0;
	bool pass=false;
	int perfect=0;
};


vector<user> a;
int n,m,k;
int maxscore[6];
int flag[N];
int al=0;

void update(int uid,int nb,int mark){
	int p = flag[uid];
	if(mark!=-1){
		a[p].pass = true;
	}
	int number = nb-1;
	if(mark==-1) mark = 0;
	if(a[p].score[number]==-1){
		a[p].score[number] = mark;
		a[p].tol += mark;
		if(mark==maxscore[number]){
			a[p].perfect++;
		}
	}else{
		if(mark>a[p].score[number]){
			a[p].tol+=(mark-a[p].score[number]);
			if(mark==maxscore[number]){
				a[p].perfect++;
			}
			a[p].score[number] = mark;
		}
	}
}

bool mcompare(user x,user y){
	if(x.tol>y.tol) return true;
	if(x.tol<y.tol) return false;
	if(x.perfect>y.perfect) return true;
	if(x.perfect<y.perfect) return false;
	return(x.id<y.id);
}

int main(){
	scanf("%d %d %d",&n,&k,&m);
	for(int i=0;i<k;i++){
		scanf("%d",&maxscore[i]);
	}
	for(int i=0;i<N;i++) flag[i] = -1;
	for(int i=0;i<m;i++){
		int xid,xn,sc;
		user temp;
		scanf("%d %d %d",&xid,&xn,&sc);
		if(flag[xid]==-1){
			flag[xid] = al;
			al++;
			temp.id = xid;
			for(int j=0;j<k;j++) temp.score[j]=-1;
			temp.tol=0;temp.pass=false;
			a.push_back(temp);
			update(xid,xn,sc);
		}else{
			update(xid,xn,sc);
		}
	}
	sort(a.begin(),a.end(),mcompare);
	int j=0;
	int l = a.size();
	int nowscore=99999999;
	int nextrank=1;
	int nowrank = 0;
	while(j<=l-1){
		if(a[j].pass){
			if(a[j].tol<nowscore){
				nowrank = nextrank;
				nextrank++;
				nowscore = a[j].tol;
				printf("%d %05d %d",nowrank,a[j].id,a[j].tol);
				for(int i=0;i<k;i++){
					if(a[j].score[i]==-1){
						printf(" -");
					}else{
						printf(" %d",a[j].score[i]);
					}
				}
				printf("\n");
			}else{
				nextrank++;
				printf("%d %05d %d",nowrank,a[j].id,a[j].tol);
				for(int i=0;i<k;i++){
					if(a[j].score[i]==-1){
						printf(" -");
					}else{
						printf(" %d",a[j].score[i]);
					}
				}
				printf("\n");
			}
		}
		j++;
	}
} 
