#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;
#define K 2501
vector<int> cour[K];
int k,n;
char op[5];
bool mycmp(int x,int y){
	return x<y;
}
void makest(int x){
	op[3]= char(x%10+'0');
	x = x/10;
	op[2] = char(x%26+'A');
	x = x/26;
	op[1] = char(x%26+'A');
	x = x/26;
	op[0] = char(x+'A');
	op[4] = 0;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		char temp[5];
		int kk;
		scanf("%s %d",&temp,&kk);
		int value,d0,d1,d2,d3;
		d0 = int(temp[0]-'A');d1 = int(temp[1]-'A');
		d2 = int(temp[2]-'A');d3 = int(temp[3]-'0');
		value = d0*26*26*10+d1*26*10+d2*10+d3;
		//cout<<value<<" "<<temp<<endl;
		for(int j=0;j<kk;j++){
			int x;
			scanf("%d",&x);
			cour[x].push_back(value);
		}
	}
	for(int i=1;i<=k;i++){
		sort(cour[i].begin(),cour[i].end(),mycmp);
		int l = cour[i].size();
		printf("%d %d\n",i,l);
		for(int j=0;j<l;j++){
			makest(cour[i][j]);
			//cout<<"tt: "<<cour[i][j]<<endl;
			printf("%s\n",op);
		}
	}
}
