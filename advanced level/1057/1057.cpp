#include<stack>
#include<set>
#include<stdio.h>
#include<iostream>
using namespace std;

char temp[100];
int n,m;
stack<int> st;
multiset<int,greater<int> > lmax;
multiset<int,greater<int> >::iterator itl;
multiset<int,less<int> >::iterator itr;
multiset<int,less<int> > rmin;
int mid=-1;

void show(){
	cout<<mid<<endl;
	cout<<"left: ";
	for(itl=lmax.begin();itl!=lmax.end();itl++){
		cout<<*itl<<" ";
	}
	cout<<endl;
	cout<<"right: ";
	for(itr=rmin.begin();itr!=rmin.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}

void update(int p){
	if(mid==-1){
		mid = p;
		return;
	}
	int l = st.size();
	if(l%2==0){
		if(p<=mid){
			lmax.insert(p);
			return;
		}else{
			if(rmin.empty()){
				rmin.insert(p);
				return;
			}
			int rminn = *(rmin.begin());
			if(p<rminn){
				lmax.insert(mid);
				mid = p;return;
			}else{
				lmax.insert(mid);
				rmin.insert(p);
				mid = rminn;
				rmin.erase(rmin.find(rminn));
			}
		}
	}else{
		if(p>=mid){
			rmin.insert(p);
			return;
		}else{
			if(lmax.empty()){
				rmin.insert(mid);
				mid = p;
				return;
			}
			int lmaxn = *(lmax.begin());
			if(p>=lmaxn){
				rmin.insert(mid);
				mid = p;return;
			}else{
				rmin.insert(mid);
				lmax.insert(p);
				mid = lmaxn;
				lmax.erase(lmax.find(lmaxn));
				return;
			}
		}
	}
}

void mypop(int p){
	int l = st.size();
	if(p==mid){
		if(l%2==0){
			mid = (*rmin.begin());
			rmin.erase(rmin.find(mid));
			return;
		}else{
			if(!lmax.empty()){
				mid = (*lmax.begin());
				lmax.erase(lmax.find(mid));
				return;
			}else{
				mid = -1;
				return;
			}
		}
	}
	if(l%2==0){
		if((itl = lmax.find(p))!=lmax.end()){
		    lmax.erase(lmax.find(p));
		    lmax.insert(mid);
		    mid = *(rmin.begin());
		    rmin.erase(rmin.find(mid));
		    return;
	    }
	    if((itr = rmin.find(p))!=rmin.end()){
		rmin.erase(rmin.find(p));
		return;
	    }
	}else{
		if((itr = rmin.find(p))!=rmin.end()){
		    rmin.erase(rmin.find(p));
		    rmin.insert(mid);
		    mid = *(lmax.begin());
		    lmax.erase(lmax.find(mid));
		    return;
	    }
	    if((itl = lmax.find(p))!=lmax.end()){
		lmax.erase(lmax.find(p));
		return;
	    }
	}	
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		if(temp[1]=='o'){
			if(st.empty()){
				printf("Invalid\n");
			}else{
				int num = st.top();
				printf("%d\n",num);
				mypop(num);
				st.pop();
			}
		}
		if(temp[1]=='u'){
			int number;
			scanf("%d",&number);
			update(number);
			st.push(number);
		}
		if(temp[1]=='e'){
			if(mid == -1){
				printf("Invalid\n");
			}else printf("%d\n",mid);
		}
		show();
	}
}
