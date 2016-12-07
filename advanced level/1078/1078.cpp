#include<stdio.h>
using namespace std;

int n,m,usize;
int ptable[10001];
int htable[10001];
int locations[10001];
int pn=1;

int hash_put(int p){
	int loc = p % usize;
	if(htable[loc]==-1){
		htable[loc] = p;
		return loc;
	}else{
		int j=1;
		while(true){
			int o = (p+j*j)%usize;
			if(htable[o]==-1){
				htable[o] = p;
				return o;
			}
//			if(loc-j*j>=0&&htable[loc-j*j]==-1){
//				htable[loc-j*j] = p;
//				return loc-j*j;
//			}
			if(j>usize) return -1;
			j++;
		}
	}
}
void moutput(int p){
	if(p==-1) printf("-");
	else printf("%d",p);
}
int main(){
	ptable[0] = 2;
	pn = 1;
	for(int i=3;i<=50000;i++){
		//printf("%d\n",i);
		bool isp = true;
		for(int j=0;j<pn;j++){
			if(i%ptable[j]==0){
				isp = false;
				break;
			}
		}
		if(isp){
			ptable[pn] = i;
			pn++;
		}
	}
	//for(int i=0;i<=500;i++) printf("%d ",ptable[i]);
	scanf("%d %d",&usize,&n);
	int q=0;
	while(ptable[q]<usize) q++;
	usize = ptable[q];
	for(int i=0;i<usize;i++) htable[i]=-1;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		locations[i] = hash_put(x);
	}
	for(int i=0;i<n-1;i++){
		moutput(locations[i]);
		printf(" ");
	}
	moutput(locations[n-1]);
}
