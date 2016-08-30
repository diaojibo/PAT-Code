#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

char ss[20];
long long form[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int pp;
int judge(string x){
	int l = x.size();
	int t = 0;
	for(int i=0;i<l;i++) if(x[i]=='1') t++;
	return t; 
}

long long final_cal(const char x[],long long g){
	int l = 0;
	while(x[l]!=0) l++;
	int p=0;
	long long answer = 0;
	//cout<<x<<" "<<l<<endl;
	while(p<l){
		int w = (l-p)-1;
		int number = int(x[p]-'0');
		long long weight=1;
		weight = form[w];
		//cout<<"we: "<<weight<<" number "<<number<<endl;
		if(false){
			answer+=(g-weight)+1;
		}else{
			long long q;
			q = g/weight/10;
			if(number>1) q++;
			answer+= q*weight;
			if(number==1){
				answer+=(g%weight)+1;
			}
		}
		p++;
		//cout<<p;
	}
	//cout<<answer<<endl;
	return answer;
}

int main(){
	long long total = 0;
	long long x=0;
	stringstream sss,ss2;
	scanf("%s",&ss);
	pp =0;
	while(ss[pp]!=0) pp++;
	for(int i=0;i<pp;i++){
		x=x*10+int(ss[i]-'0');
	}
	printf("%ld",final_cal(ss,x));
//	for(int i=6000;i<=6999;i++){
//		ss.str("");
//		ss<<i;
//		int xx = 0;
//		string tt = ss.str();
//		//cout<<tt<<endl;
//		for(int j=1;j<=i;j++){
//			ss2.str("");
//			ss2<<j;
//			xx += judge(ss2.str());
//		}
//		//int xx = judge(tt);
//		int yy = final_cal(tt.c_str(),i);
//		//cout<<xx<<endl;
//		if(xx!=yy) cout<<xx<<" "<<yy<<" i="<<i<<endl;
//	}
}
