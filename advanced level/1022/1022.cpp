#include<string>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 10001
struct book{
	long long id;
	string total_id;
	string author;
	string title;
	vector<string> keywords;
	string publisher;
	string year;
};
int n,m;
vector<book> books;

vector<string> getv(char t[]){
	string tem = "";
	vector<string> v;
	int i = 0,j=0;
	char c[100];
	while(t[i]!=0){
		if(t[i]==' '){
			c[j]=0;
			v.push_back(string(c));
			j=0;
		}else{
			c[j] = t[i];
		    j++;	
		}
		i++;
	}
	c[j]=0;
	v.push_back(string(c));
	return v;
}

bool compareb(book x,book y){
	if(x.id!=y.id) return x.id<y.id;
	return false;
}

void findbook(int p,string tf){
	//cout<<"test "<<p<<" "<<tf<<endl;
	int l = books.size();
	bool isfind = false;
	string sid;
	for(int i=0;i<l;i++){
		string now;
		if(p==1) now = books[i].title;
		if(p==2) now = books[i].author;
		if(p==4) now = books[i].publisher;
		if(p==5) now = books[i].year;
		if(now==tf){
			isfind = true;
			sid = books[i].total_id;
			cout<<sid<<endl;
		}else{
			int l2 = books[i].keywords.size();
			for(int j=0;j<l2;j++){
				if(tf==books[i].keywords[j]){
					isfind = true;
					cout<<books[i].total_id<<endl;
				}
			}
		}
	}
	if(!isfind){
		cout<<"Not Found"<<endl;
	}
}


int main(){
	cin>>n;
	cin.get();
	book temp;
	char t[300];
	for(int i=0;i<n;i++){
		cin>>temp.total_id;
		sscanf(temp.total_id.c_str(),"%d",&temp.id);
		cin.get();
		//cout<<temp.id<<" op"<<endl;
		cin.getline(t,99);
		temp.title = string(t);
		//cout<<temp.title<<" op"<<endl;
		cin.getline(t,99);
		temp.author = string(t);
		//cout<<temp.author<<" op"<<endl;
		cin.getline(t,299);
		temp.keywords = getv(t);
		cin.getline(t,99);
		temp.publisher = string(t);
		cin>>temp.year;cin.get();
		books.push_back(temp);
	}
	sort(books.begin(),books.end(),compareb);
	cin>>m;cin.get();
	char tt[300];
	int j;
	for(int i=0;i<m;i++){
		cin.getline(t,99);
		cout<<t<<endl;
		int x = int(t[0]-'0');
		int index = 3;
		j = 0;
		while(t[index]!=0){
			tt[j] = t[index];
			index++;j++;
		}
		tt[j] = 0;
		string tofind = string(tt);
		findbook(x,tofind);
	}

}
