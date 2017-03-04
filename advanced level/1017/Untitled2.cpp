#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<map>
#include<set> 
#include<queue>
using namespace std;

struct nodes{
	int value;
	bool operator<(nodes x){
		return value>x.value;
	}
};

struct mycmp{
	bool operator()(nodes x,nodes y){
		return x.value>y.value;
	}
};

priority_queue<nodes,vector<nodes>,mycmp> c;
int main(){
	nodes n1,n2,n3;
	n1.value = 9;
	n2.value = 1;
	n3.value = 8;
	c.push(n1);
	c.push(n2);
	c.push(n3);
	while(!c.empty()){
	cout<<"front: "<<c.top().value<<endl;
	c.pop();	
	} 
} 
