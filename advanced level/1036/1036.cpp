#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct stu{
	string name;
	char gender;
	int score;
	string id;
};
int n;
vector<stu> male,female;
bool mcomp(stu x,stu y){
	return x.score<y.score;
}
bool fecomp(stu x,stu y){
	return x.score > y.score;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		stu t;
		char x;
		cin>>t.name>>t.gender>>t.id>>t.score;
		x = t.gender;
		if(x=='M') {
			//t.gender = true;
			male.push_back(t);
		}else{
			//t.gender = false;
			female.push_back(t);
		}
	}
	sort(female.begin(),female.end(),fecomp);
	sort(male.begin(),male.end(),mcomp);
	int lf = female.size();
	int lm = male.size();
	if(lf==0) printf("Absent\n");
	else printf("%s %s\n",female[0].name.c_str(),female[0].id.c_str());
	if(lm==0) printf("Absent\n");
	else printf("%s %s\n",male[0].name.c_str(),male[0].id.c_str());
	if(lf==0||lm==0) printf("NA");
	else printf("%d",female[0].score-male[0].score);
	
}
