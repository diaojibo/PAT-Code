#include<stdio.h>
#include<vector>
using namespace std;
#define N 1001

char a[N];
bool flag[N];
bool is_checked[N];
vector<char> v;
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",&a);
	for(int i=0;i<N;i++) flag[i]=true,is_checked[i]=false;
	int j=0;
	while(a[j]!=0){
		int k=0;
		char c = a[j];
		while(c==a[j]){
			k++;
			j++;
		}
		if(k%n!=0){
			flag[int(c)] = false;
		}
	}
	j=0;
	while(a[j]!=0){
		int x = int(a[j]);
		char c = a[j];
		if(flag[x]&&!is_checked[x]){
			is_checked[x] = true;
			printf("%c",c);
			v.push_back(c);
			j = j+n;
		}else{
			v.push_back(c);
			if(flag[x]){
				j=j+n;
			}else j++;
		}
	}
	printf("\n");
	int l = v.size();
	for(int i=0;i<l;i++){
		printf("%c",v[i]);
	}
} 
