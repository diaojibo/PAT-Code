#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;
struct rec{
	string id;
	string name;
	int score;
};



int n,m,c;
vector<rec> students;
rec temp;
bool cmp1(rec x,rec y){
	return x.id<y.id;
}
bool cmp2(rec x,rec y){
	if(x.name!=y.name) return x.name<y.name;
	return x.id<y.id;
}
bool cmp3(rec x,rec y){
	if(x.score!=y.score) return x.score<y.score;
	return x.id<y.id;
}

int main(){
	cin>>n>>c;
	char tt[100],tt2[100];
	for(int i=0;i<n;i++){
		//cin>>temp.id>>temp.name>>temp.score;
		scanf("%s %s %d",&tt,&tt2,&temp.score);
		temp.id = string(tt);temp.name=string(tt2);
		students.push_back(temp);
	}
	if(c==1) sort(students.begin(),students.end(),cmp1);
	if(c==2) sort(students.begin(),students.end(),cmp2);
	if(c==3) sort(students.begin(),students.end(),cmp3);
	for(int i=0;i<n;i++){
		//cout<<students[i].id<<" "<<students[i].name<<" "<<students[i].score<<endl;
		printf("%s %s %d\n",students[i].id.c_str(),students[i].name.c_str(),students[i].score);
	}
} 
