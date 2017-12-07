# include<stdio.h> 
using namespace std;

unsigned long long z;
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char temp[30];
		scanf("%s",&temp);
		sscanf(temp,"%ld",&z);
		int l=0;
		while(temp[l]!=0) l++;
		unsigned long long a,b;
		a = b = 0;
		int w=1;
		int j = l/2-1;
		while(j>=0){
			a+=(temp[j]-'0')*w;
			w = w*10;
			j--;
		}
		j=l-1;w=1;
		while(j>=l/2){
			b+=(temp[j]-'0')*w;
			w=w*10;
			j--;
		}
		//printf("%ld %ld\n",a,b);
		if(a*b==0){
			if(z==0){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
			continue;
		}
		if(z%(a*b)==0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}
