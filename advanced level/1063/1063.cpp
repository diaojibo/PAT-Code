#include<set>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define M 10002
#define N 52
set<int> s1,s2,sc,st;
set<int>::iterator it,it2;
set<int> nums[N];
int n;
float calsim(int x,int y){
	int c=0,t=0;
	for(it=nums[x].begin();it!=nums[x].end();it++){
		if((it2=nums[y].find(*it))!=nums[y].end()){
			//printf("%d %d\n",*it,*it2);
			c++;
		}
	}
	int l1 = nums[x].size();
	int l2 = nums[y].size();
    return float(c)/(l1+l2-c)*100;
}


int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int mm;
    scanf("%d",&mm);
    for(int j=0;j<mm;j++){
    	int x;
        scanf("%d",&x);
        nums[i+1].insert(x);
    }
  }
  int k;
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    float ans;
    ans = calsim(x,y);
    printf("%.1f%\n",ans);
  }
} 
