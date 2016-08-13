#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct person{
	int height;
	string name;
};


int n,k;
vector<person> people;

bool compstring(string a,string b){
	int sizea,sizeb;
	sizea = a.length();
	sizeb = b.length();
	int msize = min(sizea,sizeb);
	for(int i=1;i<=msize;i++){
		if(a[i-1]<b[i-1]) return true;
		if(a[i-1]>b[i-1]) return false;
	}
	return (sizea<sizeb);
}

bool comparebig(person a,person b){
	if(a.height>b.height) return true;
	if(a.height<b.height) return false;
	return compstring(a.name,b.name);

}

string put_position(int begin,int end,vector<person>& people){
	string formation = people[begin].name;
	bool put_left = true;
	for(int i=begin+1;i<=end;i++){
		if(put_left){
			formation = people[i].name+" "+formation;
		}else{
			formation = formation + " " +people[i].name;
		}
		put_left = !put_left;
	
	}
	return formation; 
}


int main(){

	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int th;
		person tperson;
		char temp[20];
		scanf("%s %d",&temp,&th);
		tperson.height = th;
		tperson.name = string(temp);
		people.push_back(tperson);
	}

	sort(people.begin(),people.end(),comparebig);

	int row = 0;
	int row_number;
	int beg = 0;
	while(true){
		row ++;
		if(row>k) break;
		if(row==1){
			row_number = n/k + n%k;
		}
		else row_number = n/k;
		string thisrow = put_position(beg,beg+row_number-1,people);
		cout<<thisrow<<endl;
		beg += row_number;

	}

	return 0;
}