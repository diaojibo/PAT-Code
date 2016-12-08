#include<stdio.h>
using namespace std;
#define N 105
int a[N],b[N],heap[N],sortl[N];
int n;

void move_one(int k,int q,int x[]){
	for(int i=q;i>k;i--){
		x[i] = x[i-1];
	}
}
void isort(int p){
	int j=p-1;
	while(j>=0&&a[p]<sortl[j]) j--;
	move_one(j+1,p,sortl);
	sortl[j+1] = a[p];
}
void mswap(int& x,int& y){
	int temp;
	temp=x;x=y;y=temp;
}
void adjust(int p,int nn){
	if(p*2>nn) return;
	if(heap[p]<heap[p*2]){
		if(p*2+1<=nn&&heap[p*2+1]>heap[p*2]){
			mswap(heap[p*2+1],heap[p]);
			adjust(p*2+1,nn);
		}else{
			mswap(heap[p*2],heap[p]);
			adjust(p*2,nn),nn;
		}
	}else{
		if(p*2+1<=nn&&heap[p]<heap[p*2+1]){
			mswap(heap[p*2+1],heap[p]);
			adjust(p*2+1,nn);
		}
	}
}
void build(int nn){
	int j=nn/2;
	for(int i=j;i>0;i--){
		adjust(i,nn);
	}
	
}
bool finish(int x[],int d){
	for(int i=0;i<n-1;i++){
		if(x[i+d]>x[i+1+d]) return false;
	}
	return true;
}
bool thesame(int x[],int y[],int d){
	for(int i=0;i<n;i++)
	  if(x[i+d]!=y[i]) return false;
	return true;
}
void oprint(int x[]){
	for(int i=0;i<n-1;i++) printf("%d ",x[i]);
	if(n>0) printf("%d\n",x[n-1]);
}
void oprint2(int x[]){
	for(int i=1;i<n;i++) printf("%d ",x[i]);
	if(n>0) printf("%d\n",x[n]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sortl[i] = a[i];
		heap[i+1] = a[i];
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	int j=1;
	while(j<n){
		//oprint(sortl);
		int q=j-1;
		while(q<n-1&&sortl[q]<sortl[q+1]) q++;
		j = q+1;
		//printf(" %d\n",j);
		if(thesame(b,sortl,0)){
			isort(j);
			printf("Insertion Sort\n");
			oprint(sortl);
			return 0;
		}else{
			isort(j);
			j++;
		}
	}
	j = n;
	build(j);
	while(j>1){
		//oprint2(heap);
		if(thesame(heap,b,1)){
			mswap(heap[1],heap[j]);
			build(j-1);
			printf("Heap Sort\n");
			oprint2(heap);
			return 0;
		}else{
			//build(j);
			mswap(heap[1],heap[j]);
			//oprint2(heap);
			build(j-1);
			j--;
		}
	}
	if(thesame(sortl,b,0)){
		printf("Insertion Sort\n");
		oprint(b);
	}
}

