#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 400001
struct stu{
	int gpa,interview;
	int tol;
	int id;
	int pref[5];
	int rank;
};

bool mycmp(stu x,stu y){
	if(x.tol!=y.tol) return x.tol>y.tol;
	return x.gpa>y.gpa;
}
bool mycmp2(int x,int y){
	return x<y;
}
int n,m,k;
int quota[101];
int min_rank[101];
int admit[101];
vector<stu> a;
vector<int> school[101];
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d",&quota[i]);
	}
	for(int i=0;i<n;i++){
		stu temp;
		int x,y;
		scanf("%d %d",&x,&y);
		temp.id = i;
		temp.gpa = x;temp.interview = y;
		temp.tol = x+y;
		for(int j=0;j<k;j++){
			scanf("%d",&temp.pref[j]);
		}
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),mycmp);
	a[0].rank = 1;
	for(int i=1;i<n;i++){
		if(a[i].gpa==a[i-1].gpa&&a[i].tol==a[i-1].tol){
			a[i].rank = a[i-1].rank;
		}else{
			a[i].rank = i+1;
		}
	}
	for(int i=0;i<m;i++) admit[i] = 0,min_rank[i]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int g = a[i].pref[j];
			if(admit[g]<quota[g]||min_rank[g]==a[i].rank){
				admit[g]++;
				school[g].push_back(a[i].id);
				min_rank[g] = a[i].rank;
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		sort(school[i].begin(),school[i].end(),mycmp2);
		int l = school[i].size();
		for(int j=0;j<l-1;j++) printf("%d ",school[i][j]);
		if(l>0) printf("%d",school[i][l-1]);
		printf("\n");
	}
}
