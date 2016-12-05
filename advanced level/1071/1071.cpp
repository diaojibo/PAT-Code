#include<map>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define N 1100000
char st[N];
vector<string> words; 
map<string, int> m;
map<string, int>::iterator it;
char lowers(char c){
	if(c>='A'&&c<='Z'){
		return char(c-'A'+'a');
	}
	return c;
}
bool isc(char c){
	if(c>='a'&&c<='z') return true;
	if(c>='0'&&c<='9') return true;
	return false;
}

int getcount(string s){
	it = m.find(s);
	if(it==m.end()){
		return 0;
	}else{
		return m[s];
	}
	
}

int main(){
	cin.getline(st,1048577);
	int j = 0;
	string ss = "";
	while(st[j]!=0){
		//cout<<ss<<" "<<j<<endl;
		char t = lowers(st[j]);
		if(isc(t)){
			ss+=t;
		}else if(ss!=""){
			if(getcount(ss)==0) {
				m[ss] = 1;
				words.push_back(ss);
			}else m[ss]++;
			ss="";
		}
		j++;
	}
	if(ss!=""){
			if(getcount(ss)==0) {
				m[ss] = 1;
				words.push_back(ss);
			}else m[ss]++;
			ss="";
		}
	int ansn = -1;
	string anss = "";
	int l = words.size();
	for(int i=0;i<l;i++){
		if(m[words[i]]>ansn){
			ansn = m[words[i]];
			anss = words[i]; 
		}else if(ansn==m[words[i]]){
			if(words[i]<anss){
				anss = words[i];
			}
		}
	}
	cout<<anss<<" "<<ansn;
}
