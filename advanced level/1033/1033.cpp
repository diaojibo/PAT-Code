#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 501
#define CMAX 101
struct station{
	int dis;
	float v;
};


int cmax,n,d;
float davg;
vector<station> s;
bool mycmp(station x,station y){
	return x.dis<y.dis;
}
int main(){
	scanf("%d %d %f %d",&cmax,&d,&davg,&n);
	for(int i=0;i<n;i++){
		station temp;
		scanf("%f %d",&temp.v,&temp.dis);
		s.push_back(temp);
	}
	sort(s.begin(),s.end(),mycmp);
	int p=0;
	float cost;
	float oil = 0;
	int lastbuy = 0;float consume;
	float maxdis;bool reach = true;
	bool smaller = false;int min=-1;
	if(s[0].dis!=0){
		printf("The maximum travel distance = %.2f",0);
		return 0;
	}
	while(true){
		//printf("%d cost:%.3f oil %.3f\n",p,cost,oil);
		int dist = d - s[p].dis;
		consume = dist/davg;
		if(oil>=consume){
			oil -= consume;
			cost = cost-s[lastbuy].v*oil;
			break;
		}
		min=-1;
		smaller = false;
		for(int i=p+1;i<n;i++){
			if(s[i].dis-s[p].dis>davg*cmax) {
				//printf("%d %d \n",p,i);
				break;
			}
			if(s[i].v<=s[p].v){
				smaller = true;
				//printf("%d %d \n",p,i);
				min = i;
				break;
			}
			if(min==-1||s[i].v<s[min].v) min = i;
		}
		if(smaller){
			dist = s[min].dis - s[p].dis;
			if(dist/davg<=oil){
				oil = oil-dist/davg;
				p = min;
			}else{
				cost+=(dist/davg-oil)*s[p].v;
				lastbuy = p;
				p = min;
				oil = 0;
			}
		}else{
			if(d-s[p].dis<=cmax*davg){
				cost+=((d-s[p].dis)/davg-oil)*s[p].v;
				break;
			}
			if(min==-1){
				reach = false;
				maxdis = s[p].dis+cmax*davg;
				break;
			}
			cost += (cmax-oil)*s[p].v;
			oil = cmax;lastbuy = p;
			//printf("%d %d %f\n",p,min,oil);
			oil = oil - (s[min].dis-s[p].dis)/davg;
			p = min;
		}
	}
	if(!reach){
		printf("The maximum travel distance = %.2f",maxdis+0.00001);
	}else{
		printf("%.2f",cost+0.00001);
	}

}
