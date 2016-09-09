#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct per{
	int v,t;
	int id;
};
int n,h,low;
bool mycmp(per x,per y){
	int tx = x.v+x.t;
	int ty = y.v+y.t;
	if(tx!=ty) return tx>ty;
	if(x.v!=y.v) return x.v>y.v;
	return x.id<y.id;
}

vector<per> sag,nob,foo,sma;
int main(){
	scanf("%d %d %d",&n,&low,&h);
	for(int i=0;i<n;i++){
		int x,y,z;
		per temp;
		scanf("%d %d %d",&x,&y,&z);
		temp.id = x;temp.v = y;
		temp.t = z;
		if(y>=h&&z>=h){
			sag.push_back(temp);
			continue;
		}
		if(y<low||z<low) continue;
		if(y>=h&&z<h){
			nob.push_back(temp);
			continue;
		}
		if(y>=z){
			foo.push_back(temp);
			continue;
		}
		sma.push_back(temp);
	}
	sort(sag.begin(),sag.end(),mycmp);
	sort(nob.begin(),nob.end(),mycmp);
	sort(foo.begin(),foo.end(),mycmp);
	sort(sma.begin(),sma.end(),mycmp);
	int l1 = sag.size();
	int l2 = nob.size();
	int l3 = foo.size();
	int l4 = sma.size();
	printf("%d\n",l1+l2+l3+l4);
	for(int i=0;i<l1;i++) printf("%08d %d %d\n",sag[i].id,sag[i].v,sag[i].t);
	for(int i=0;i<l2;i++) printf("%08d %d %d\n",nob[i].id,nob[i].v,nob[i].t);
	for(int i=0;i<l3;i++) printf("%08d %d %d\n",foo[i].id,foo[i].v,foo[i].t);
	for(int i=0;i<l4;i++) printf("%08d %d %d\n",sma[i].id,sma[i].v,sma[i].t);
} 
