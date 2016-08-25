#include<string>
#include<iostream>
using namespace std;
int x,y,z;
int n1[20],n2[20],n3[20];

void change(int x,int a[]){
	a[0] = 0;
	if(x==0){
		a[0]=1;
		a[0]=0;
	}
	while(x>0){
		a[0]++;
		a[a[0]] = x%13;
		x = x/13;
	}
	if(a[0]==1){
		a[2] = 0;
		a[0]++;
	}
	return;
}

char getcc(int x){
	if(x==10) return 'A';
	if(x==11) return 'B';
	if(x==12) return 'C';
	return char('0'+x);
}

int main(){
	cin>>x>>y>>z;
	change(x,n1);change(y,n2);change(z,n3);
	cout<<"#"<<getcc(n1[2])<<getcc(n1[1])<<getcc(n2[2])<<getcc(n2[1])<<getcc(n3[2])<<getcc(n3[1]);
	
}
