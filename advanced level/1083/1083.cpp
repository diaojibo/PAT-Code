#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct rec{
	char id[12];
	char name[12];
	int grade;
};

vector<rec> a;

bool mycom(rec x,rec y){
	if(x.grade!=y.grade) return x.grade>y.grade;
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		rec temp;
		scanf("%s %s %d",&temp.name,&temp.id,&temp.grade);
		a.push_back(temp);
	}
	int x,y;
	scanf("%d %d",&x,&y);
	vector<rec> ans;
	sort(a.begin(),a.end(),mycom);
	for(int i=0;i<x;i++){
		if(a[i].grade<=y && a[i].grade>=x) ans.push_back(a[i]); 
	}
	int len = ans.size();
	if(len==0){
		printf("NONE\n");
	}else{
		for(int i=0;i<len;i++){
			printf("%s %s\n",ans[i].name,ans[i].id);
		}
	}
}
