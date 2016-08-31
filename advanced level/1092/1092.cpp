#include<stdio.h>
using namespace std;
#define N 1001
#define fff 101
char s1[N],s2[N];
int f1[fff],f2[fff];

int c2flag(char x){
	if(x<='9'&&x>='0') return int(x-'0');
	if(x>='a'&&x<='z') return int(x-'a')+10;
	return int(x-'A')+40;
}
int n,m,k;
int main(){
	scanf("%s",&s1);
	scanf("%s",&s2);
	int pp=0;
	for(int i=0;i<fff;i++) f1[i] = 0,f2[i]=0;
	while(s1[pp]!=0){
		int x = c2flag(s1[pp]);
		f1[x]++;pp++;
	}
	pp=0;
	while(s2[pp]!=0){
		int x = c2flag(s2[pp]);
		f2[x]++;pp++;
	}
	for(int i=0;i<fff;i++){
		f1[i] = f1[i]-f2[i];
	}
	bool b = true;
	for(int i=0;i<fff;i++){
		if(f1[i]<0){
			b = false;
			break;
		}
	}
	int ans = 0;
	if(b) for(int i=0;i<fff;i++) ans+=f1[i];
	else for(int i=0;i<fff;i++) if(f1[i]<0) ans+=-f1[i];
	if(b) printf("Yes %d",ans);
	else printf("No %d",ans);
}
