#include<vector>
#include<stdio.h>
using namespace std;

int a[] = {3,1,5,7,2,4,9,6,11,5,879,1,4,6};
int n = 14; 

void InsertSort(int a[],int n){
	//��������Ϊԭ������ǰ�������򣬺������������� 
	for(int i=1;i<n;i++){ //n�Ǵ����������� ��1��ԭ����ڶ���Ԫ�أ��ӵڶ�������ʼ 
		int x = a[i];// ��ν���ڱ������ǰѴ������������ 
		//��������������ԭ���������������Ϊ�����֣�ǰ��Ĳ������Ѿ��ź���ģ�������������������� 
		int j = i-1;// �Ӵ���Ԫ�ص�ǰһ��Ԫ�ؿ�ʼ��ǰ���� 
		while(j>=0&&a[j]>x){ //����ȷ��λ�� 
			a[j+1] = a[j]; //���������ȷ��λ�ã��Ͱ�����Ԫ�������ƶ�һ�� 
			j--; //������� 
		}
		a[j+1] = x; //�ҵ���λ�ã���Ԫ�طŵ���ȷλ���� 
	}
}

void merge(int l,int mid,int r){
	//merge����������Ҫ����һ��������[l,mid)��[mid,r]�����Ԫ����������mid�ֿ���λ�ö����ź�������� 
	
	vector<int> temp; //���������������� 
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
		a[i] = temp[i-l]; //������ɺ󣬷Ż�ԭ���� 
	}
}


void mergeSort(int l,int r){
	//�����Ĺ鲢�������¶��� 
	
	int piece = 1; //һ��ʼ�ȶ���ϲ�����С��λΪ1 
	while(piece<n){ //�����������ϲ��ĳ��ȴ��ڵ��������������ź� 
		int p = 0;//�ӵ�һ��Ԫ�ؿ�ʼ�ϲ�
		 
		while(p+piece<n){ //p+pieceָ���ǵ�ǰ�ϲ������һ���ϲ����λ�� 

			int mid = p+piece; //ȡmidΪ��һ���ϲ����λ�� 
			
			if(mid+piece-1<n) merge(p,mid,mid+piece-1);//�����һ���ϲ��������㹻����merge���� 
			
			else merge(p,mid,n-1); //��һ���ϲ������������ˣ���ֱ��ȡ�����һ��Ԫ�� 
			p = mid + piece; //�����������ϲ���ĺϲ� 
		}
		piece = piece * 2; //�ϲ�һ�����꣬��С��λ���� 
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
