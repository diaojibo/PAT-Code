#include<stdio.h> 
#include<iostream>
#include<vector>
using namespace std; 

int n;
vector<int> a,b;
vector<int> ans;
bool isfind = false;
bool ise(vector<int> &x,vector<int> &y){
	int xx = x.size();
	for(int i=0;i<xx;i++){
		if(x[i]!=y[i]) return false;
	}
	return true;
}

void mergeSort(vector<int> &x);


void InsertSort(vector<int> a){
	int l = a.size();
	int stop = -1;
	for(int i=1;i<l;i++){
		
		if(ise(a,b)){
			isfind = true;
			stop = i;
		}
		int x = a[i];
		int j = i-1;
		while(j>=0 && a[j]>x){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
		if(stop==i&&!ise(a,b)){
			ans = a;
			return;
		}
	}
}

void merge(int l,int mid,int r,vector<int> &x){
	vector<int> temp;
	int i = l;
	int j = mid;
	while(i<mid && j<=r){
		if(x[i]<x[j]) temp.push_back(x[i]),i++;
		else temp.push_back(x[j]),j++;
	}
	if(i<mid) for(int k=i;k<mid;k++) temp.push_back(x[k]);
	if(j<=r) for(int k=j;k<=r;k++) temp.push_back(x[k]);
	for(int i=l;i<=r;i++){
		x[i] = temp[i-l];
	}
}

void mergeSort(int l,int r,vector<int> &a){
	int piece = 1;
	int al = a.size();
	int stop = -1;
	while(piece<al){
		
		if(ise(a,b)){
			isfind = true;
			stop = piece;
		}
		
		int p = 0;
		while(p+piece<al){
			int mid = p+piece;
			if(mid+piece-1<al){
				merge(p,mid,mid+piece-1,a);
			}else{
				merge(p,mid,al-1,a);
			}
			p = mid + piece;
		}
		//for(int i=0;i<a.size();i++) printf("%d ",a[i]);
		//printf("\n");
		if(stop==piece){
			ans = a;
			return;
		}
		piece *= 2;
	}
}


int main()	{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);

	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	InsertSort(a);
	if(isfind){
		int l = ans.size();
		printf("Insertion Sort\n");
		for(int i=0;i<l-1;i++) printf("%d ",ans[i]);
		printf("%d",ans[l-1]);
		return 0;
	}
	mergeSort(0,n-1,a);
		if(isfind){
		int l = ans.size();
		printf("Merge Sort\n");
		for(int i=0;i<l-1;i++) printf("%d ",ans[i]);
		printf("%d",ans[l-1]);
	}
}
