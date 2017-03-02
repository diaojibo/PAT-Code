#include<vector>
#include<stdio.h>
using namespace std;

int a[] = {3,1,5,7,2,4,9,6,11,5,879,1,4,6};
int n = 14; 

void InsertSort(int a[],int n){
	//插入排序为原地排序，前面是有序，后面是输入序列 
	for(int i=1;i<n;i++){ //n是待排序数个数 ，1是原数组第二个元素，从第二个数开始 
		int x = a[i];// 所谓的哨兵，就是把待排序数抽出来 
		//插入排序这里是原地排序，所以数组分为两部分，前面的部分是已经排好序的，后面的序列是输入序列 
		int j = i-1;// 从待排元素的前一个元素开始往前遍历 
		while(j>=0&&a[j]>x){ //找正确的位置 
			a[j+1] = a[j]; //如果不是正确的位置，就把所有元素往后移动一格 
			j--; //往后遍历 
		}
		a[j+1] = x; //找到了位置，把元素放到正确位置中 
	}
}

void merge(int l,int mid,int r){
	//merge操作，很重要，把一个数列里[l,mid)和[mid,r]区域的元素排序，且由mid分开的位置都是排好序的序列 
	
	vector<int> temp; //额外数组用来排序 
	int i = l;
	int j =mid;
	while(i<mid&&j<=r){
		if(a[i]<a[j]) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(a[j]);
			j++;
		}
	}
	if(i<mid) for(int k=i;k<mid;k++) temp.push_back(a[k]);
	if(j<=r) for(int k=j;k<=r;k++) temp.push_back(a[k]);
	for(int i=l;i<=r;i++){
		a[i] = temp[i-l]; //排序完成后，放回原数列 
	}
}


void mergeSort(int l,int r){
	//迭代的归并排序，自下而上 
	
	int piece = 1; //一开始先定义合并的最小单位为1 
	while(piece<n){ //结束条件，合并的长度大于等于整个序列则排好 
		int p = 0;//从第一个元素开始合并
		 
		while(p+piece<n){ //p+piece指的是当前合并块的下一个合并块的位置 

			int mid = p+piece; //取mid为下一个合并块的位置 
			
			if(mid+piece-1<n) merge(p,mid,mid+piece-1);//如果下一个合并块数量足够，则merge操作 
			
			else merge(p,mid,n-1); //下一个合并块数量不足了，则直接取到最后一个元素 
			p = mid + piece; //进行下两个合并块的合并 
		}
		piece = piece * 2; //合并一轮走完，最小单位翻倍 
	}
} 



int main(){	
    //InsertSort(a,n);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    mergeSort(0,n-1);
    printf("\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
} 
