#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

string chinese[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};


char a[12];
string deal4(int x,int y){
	int wei = y - x +1;
	if(x>y) return "";
	if(wei==1) return chinese[int(a[x]-'0')];
	if(wei==2){
		int w1 = int(a[x]-'0');
		int w2 = int(a[y]-'0');
		if(a[y]=='0') return chinese[int(a[x]-'0')] + " Shi";
		else return chinese[w1] + " Shi " + chinese[w2];
	}
	if(wei==3){
		int w1 = int(a[x]-'0');
		int w2 = int(a[x+1]-'0');
		int w3 = int(a[x+2]-'0');
		if(w2 == 0 && w3 == 0) return deal4(x,x) + " Bai";
		if(a[x+1]=='0') return deal4(x,x) + " Bai ling " + deal4(y,y);
		return chinese[w1] + " Bai " + deal4(x+1,y);
	}
	if(wei==4){
		int w1 = int(a[x]-'0');
		int w2 = int(a[x+1]-'0');
		int w3 = int(a[x+2]-'0');
		int w4 = int(a[x+3]-'0');
		if(w2==0&&w3==0&w4==0) return deal4(x,x) + " Qian";
		if(w2==0){
			if(w3==0) return deal4(x,x) + " Qian ling " + deal4(y,y);
			else return deal4(x,x) + " Qian ling " + deal4(x+2,y);
		}else{
			return deal4(x,x) + " Qian " + deal4(x+1,y);
		}
	}
}

char digt[4][4];
bool dzero[4];

int main(){
	
	scanf("%s",&a);	
	int start = 0;
	
	if(a[0]=='-') start = 1;
	int lens = 0;
	while(a[lens]!=0) lens++;
	string ans = deal4(0,lens-1);
	if(lens-start<=4){
		ans = deal4(start,lens-1);
	}
	if(lens-start>4&&lens-start<=8){
		string t="";
		//cout<<lens<<endl;
		if(a[lens-4]=='0'){
			int p=lens-4;
			while(p<lens&&a[p]=='0') p++;
			cout<<p<<endl;
			if(p<=lens-1) t=" ling " + deal4(p,lens-1);
		}else t = deal4(lens-4,lens-1);
		ans = deal4(start,lens-5) + t;
	}
	if(lens-start>8){
	  	string t1="";
	  	string t2="";
		if(a[lens-8]=='0'){
			int p = lens - 8;
			while(p<=lens-5&&a[p]=='0') p++;
			if(p>lens-5){
				int q = lens-4;
				while(q<=lens-1&&a[q]=='0') q++;
				string ll = " ling ";
				if(q>lens-1){
					t1 = "";
					t2 = "";
				}else {
					if(q==lens-4) ll = "";
					t1 = "";
					t2 = ll + deal4(q,lens-1); 
				}
			}else{
				t1 = " ling " + deal4(p,lens-5) + " Wan";
				int q = lens-4;
				string ll = " ling ";
				while(q<=lens-1&&a[q]=='0') q++;
				if(q>lens-1) t2 = "";
				if(q==lens-4) ll = "";
				else t2 = ll+deal4(q,lens-1);
			}
		}else{
			t1 = deal4(lens-8,lens-5) + " Wan";
			int q=lens-4;
			while(q<=lens-1&&a[q]=='0') q++;
			if(q>lens-1) t2 = "";
			string ll = " ling ";
			if(q==lens-4) ll = "";
			else t2 = ll + deal4(q,lens-1);
		}
		ans = deal4(start,lens-9) + " Yi "+t1+t2;	
	}
	printf("%s",ans.c_str());
}
