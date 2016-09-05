#include<vector>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
struct per{
	string name;
	int age;
	int money;
};

bool mycmp(per x,per y){
	if(x.money!=y.money) return x.money>y.money;
	if(x.age!=y.age) return x.age<y.age;
	return x.name<y.name;
}

int n,m;
char temp[10];
vector<per> people;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		per t;
		scanf("%s %d %d",&temp,&t.age,&t.money);
		t.name = string(temp);
		people.push_back(t);
	}
	sort(people.begin(),people.end(),mycmp);
	for(int i=0;i<m;i++){
		int ps,amin,amax;
		int pp=0,num=0;
		scanf("%d %d %d",&ps,&amin,&amax);
		printf("Case #%d:\n",i+1);
		while(pp<n&&num<ps){
			if(people[pp].age>=amin&&people[pp].age<=amax){
				num++;
				printf("%s %d %d\n",people[pp].name.c_str(),people[pp].age,people[pp].money);
			}
			pp++;
		}
		if(num==0){
			printf("None\n");
		}
	}
}
