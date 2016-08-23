#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int n,k;
struct rec{
	int score;
	int local_rank;
	int location;
	string id;
	int rank;
};

vector<rec> total;
vector<rec> places[102];

void calrank(vector<rec>& x,int p){
	int l = x.size();
	int j = 0,ms=-1;
	int rank = 1;
	while(j<l){
		if(x[j].score!=ms){
			rank = j+1;
			ms = x[j].score;
		}
		if(p==0) x[j].local_rank = rank;
		else x[j].rank = rank;
		j++;
	}
}

bool mycmp(rec x,rec y){
	if(x.score!=y.score) return x.score>y.score;
	return x.id<y.id;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		string t;
		int x;
		rec temp;
		for(int j=0;j<k;j++){
			cin>>t>>x;
			temp.id = t;
			temp.score = x;
			temp.location = i;
			places[i].push_back(temp);
		}
	}
	for(int i=1;i<=n;i++) 
	   sort(places[i].begin(),places[i].end(),mycmp),calrank(places[i],0);
	for(int i=1;i<=n;i++){
		int l = places[i].size();
		for(int j=0;j<l;j++) total.push_back(places[i][j]);
	}
	sort(total.begin(),total.end(),mycmp);
	calrank(total,1);
	int len = total.size();
	cout<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<total[i].id<<" "<<total[i].rank<<" "<<total[i].location<<" "<<total[i].local_rank<<endl;
	}
	
	
}
