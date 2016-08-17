#include<string>
#include<vector>
#include<iostream>

#define N 3
using namespace std;
vector<double> games[N];
char status[3] = {'W','T','L'}; 
int findmax(vector<double>& x){
	int l = x.size();
	int maxf = 0;
	for(int i=0;i<l;i++) if (x[i]>x[maxf]) maxf = i;
	return maxf;
}

int main(){
	for(int i=0;i<N;i++){
		double x,y,z;
		cin>>x>>y>>z;
		games[i].push_back(x);
		games[i].push_back(y);
		games[i].push_back(z);
	}
	int c1 = findmax(games[0]);
	int c2 = findmax(games[1]);
	int c3 = findmax(games[2]);
	double ans = (games[0][c1]*games[1][c2]*games[2][c3]*0.65-1)*2;
	printf("%c %c %c %.2f",status[c1],status[c2],status[c3],ans+0.0000001);
}
