#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int n,m;
char x1[100],x2[100],y1[100],y2[100];
string days[8] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int calday(char x){
	if(x<='G'&&x>='A') return int(x-'A');
	//if(x<='z'&&x>='a') return int(x-'a');
	return -1;
}
int calhour(char x){
	if(x>='0'&&x<='9') return int(x-'0');
	if(x>='A'&&x<='N') return int(x-'A')+10;
	return -1;
}
bool jmm(char x){
	if(x>='a'&&x<='z') return true;
	if(x>='A'&&x<='Z') return true;
	return false;
}
int main(){
	scanf("%s",&x1);scanf("%s",&x2);
	scanf("%s",&y1);scanf("%s",&y2);
	int pp=0;
	int finds = 0;
	int wd = 0,hh=0;
	while(x1[pp]!=0&&x2[pp]!=0){
		if(x1[pp]==x2[pp]){
			if(finds==0){
				wd = calday(x1[pp]);
				if(wd!=-1) finds++;
			}else if(finds==1){
				hh = calhour(x1[pp]);
				if(hh!=-1) finds++;
			}
		}
		if(finds==2) break;
		pp++;
	}
	int mm;
	pp = 0;finds=0;
	while(y1[pp]!=0&&y2[pp]!=0){
		if(y1[pp]==y2[pp]&&jmm(y1[pp])){
			break;
		}
		pp++;
	}
	if(pp==60) pp=0;
	printf("%s %02d:%02d",days[wd].c_str(),hh,pp);
}
