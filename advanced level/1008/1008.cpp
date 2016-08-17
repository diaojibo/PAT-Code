#include<iostream>
#include<vector>

using namespace std;
int x,y,n;

int main(){
	cin>>n;
	int time;
	int start = 0;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x>start) time+=6*(x-start);
		if(x<start) time+=4*(start-x);
		time+=5;
		start = x;
	}
	cout<<time;
}
