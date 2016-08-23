#include<iostream>
#include<string>

using namespace std;

bool judge(int num[],int l){
	bool jud = true;
	for(int i=0;i<l;i++) if(num[i]!=num[l-i-1]) return false;
	return true;
}


char t[200];
int number[200],newn[200];
int k,len=0;

void initn(){
	for(int i=0;i<200;i++) newn[i] = 0;
}
void cal(){
	initn();
	for(int i=0;i<len;i++){
		newn[i] = number[i]+number[len-i-1];
	}
	for(int i=0;i<len;i++) if(newn[i]>=10) newn[i+1]++,newn[i]=newn[i]%10;
	if(newn[len]>0) len++;
	for(int i=0;i<len;i++) number[i] = newn[i];
}
int main(){
	cin>>t>>k;
	while(t[len]!=0) len++;
	for(int i=0;i<len;i++) number[i] = int(t[len-i-1]-'0');
	bool ifsucc = false;
	ifsucc = judge(number,len);
	if(ifsucc){
		cout<<t<<endl;
		cout<<0;
		return 0;
	}
	int o=0;
	for(int i=1;i<=k;i++){
		cal();o=i;
		ifsucc = judge(number,len);
		if(ifsucc) break;
	}
	for(int i=0;i<len;i++) cout<<number[len-i-1];
	cout<<endl;
	cout<<o;
} 
