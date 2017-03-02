#include<stdio.h>
#include<vector>
using namespace std;
#define N 300
char x[N],y[N];
bool isw[N];


int getint(char x){
	if(x>='a'&&x<='z'){
		return int(x-'a'+'A');
	}
	return int(x);
}


int main(){
	
	scanf("%s",&x);
	scanf("%s",&y);
	for(int i=0;i<N;i++) isw[i] = false;
	int px=0,py=0;
	while(y[py]!=0){
		while(y[py]!=x[px]){
			int k = getint(x[px]);
			isw[k] = true;
			px++;
		}
		px++;py++;
	}
	while(x[px]!=0) isw[getint(x[px])]=true,px=px+1;
	int p = 0;
	while(x[p]!=0){
		int k = getint(x[p]);
		if(isw[k]){
			printf("%c",char(k));
			isw[k] = false;
		}
		p++;
	}
} 
