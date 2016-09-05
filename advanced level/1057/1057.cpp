#include<stack>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
char temp[100];
int flag[100001]; 
int n;
int llmax=-1,rrmin=-1,med=-1;
stack<int> st;

struct leftn{
	int v;
	bool operator <(const leftn &y) const{
		return v>y.v;
	}
};
struct rightn{
	int v;
	bool operator <(const rightn &y) const{
		return v<y.v;
	}
};
priority_queue<leftn> lmax;
priority_queue<rightn> rmin;


void stinsert(int p){
	while(!rmin.empty()&&flag[rmin.top().v]<1) rmin.pop();
	while(!lmax.empty()&&flag[lmax.top().v]<1) lmax.pop();
	int l = st.size();
	if(l%2==0){
		if(med==-1){
			med = p;
			flag[p]++;
			return;
		}
		if(p<med){
			leftn ln;
			ln.v = p;
			lmax.push(ln);
		}else{
			int x;
			if(!rmin.empty()) x = rmin.top().v;
			if(rmin.empty()||p<x){
				leftn ln;
				ln.v = med;
				lmax.push(ln);
				med = p;
			}else{
				rightn  rn;
				rn.v = med;
				rmin.push(rn);
			}
		}
	}else{
		if(p<med){
			int x;
			if(!lmax.empty()) x = lmax.top().v;
			if(lmax.empty()||p>x){
				rightn rn;
				rn.v = med;
				rmin.push(rn);
				med = p;
			}else{
				leftn ln;
			    ln.v = p;
				lmax.push(ln);
			}
		}else{
			rightn rn;
			rn.v = p;
			rmin.push(rn);
		}
	}
	flag[p]++;
}

void stpop(){
	int l = st.size();
	int x = st.top();
	flag[x]--;
	if(l%2==0){
		if(x==med){
			int p = rmin.top().v;
			med = p;
			rmin.pop();
			return;
		}
		if(!lmax.empty()&&x==lmax.top().v) lmax.pop();
		else if(!rmin.empty()&&x==rmin.top().v) rmin.pop();
		return;
	}else{
		if(x==med){
			int p = lmax.top().v;
			med = p;
			lmax.pop();
			return;
		}
		if(!lmax.empty()&&x==lmax.top().v) lmax.pop();
		else if(!rmin.empty()&&x==rmin.top().v) rmin.pop(); 
	}
}
int main(){
	scanf("%d",&n);
	cin.get();
	for(int i=0;i<n;i++){
		cin.getline(temp,100);
		if(temp[1]=='o'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n",st.top());
				stpop();
				st.pop();
			}
		}
		if(temp[1]=='u'){
			int pp = 5;
			int num=0;
			while(temp[pp]!=0){
				num=num*10;
				num+=int(temp[pp]-'0');
				pp++;
			}
			stinsert(num);
			st.push(num);
			//printf("%d\n",num);
		}
		if(temp[1]=='e'){
			if(med==-1) printf("Invalid\n");
			else printf("%d\n",med);
		}
	}
}
