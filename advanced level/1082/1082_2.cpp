#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int a;
char temp[31]; 
string words[11] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};


string deal(int q){
	if(q==0) return words[0];
	if(q<10){
		return words[q];
	}
	if(q<100){
		int x = q % 10;
		int y = q / 10;
		if(x==0) return deal(y) + " Shi";
		else return deal(y) + " Shi " + deal(x);
	}
	if(q<1000){
		int x = q%100;
		int y = q / 100;
		if(x==0) return deal(y) + " Bai";
		else{
			if(x<10) return deal(y)+" Bai ling " + deal(x);
			else return deal(y)+" Bai "+deal(x);
		}
	}
	if(q<10000){
		int x = q%1000;
		int y = q/1000;
		if(x==0) return deal(y) + " Qian";
		else{
			if(x<100) return deal(y) + " Qian ling "+deal(x);
			else return deal(y) + " Qian " + deal(x);
		}
	}
	if(q<100000000){
		int p1 = q % 10000;
		int p2 = q / 10000;
		if(p1==0) return deal(p2) + " Wan";
		else{
			if(p1<1000) return deal(p2) + " Wan ling " + deal(p1);
			else return deal(p2) + " Wan " + deal(p1);
		}
	}
	if(q>100000000){
		int p1 = q % 100000000;
		int p2 = q / 100000000;
		if(p1 == 0) return deal(p2) + " Yi";
		else{
			if(p1<10000000) return deal(p2) + " Yi ling" + deal(p1);
			else return deal(p2) + " Yi " + deal(p1);
		}
	}
}



int main(){
	int x,y;
	int d;
	scanf("%d",&a);
	d = a;
	string ans;
	if(a<0) ans = "Fu "+deal(-a);
	else ans = deal(a);
	printf("%s",ans.c_str());
	
}
