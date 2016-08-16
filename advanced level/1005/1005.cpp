#include<vector>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

char temp[101];

string getst(char x){
	if(x=='0') return string("zero");
	if(x=='1') return string("one");
	if(x=='2') return string("two");
	if(x=='3') return string("three");
	if(x=='4') return string("four");
	if(x=='5') return string("five");
	if(x=='6') return string("six");
	if(x=='7') return string("seven");
	if(x=='8') return string("eight");
	if(x=='9') return string("nine");
}


int main(){
	cin>>temp;
	int sum = 0;
	int p = 0;
	while(temp[p]!=0){
		sum = sum + (int)(temp[p] - '0');
		p++;
	}
	sprintf(temp,"%d",sum);
	string ans;
	if(temp[0]!=0){
		ans = getst(temp[0]);
	}
	p=1;
	while(temp[p]!=0){
		ans = ans + " " + getst(temp[p]);
		p++;
	}
	cout<<ans;
	//cin>>p;
}