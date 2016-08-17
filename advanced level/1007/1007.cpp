#include<iostream>
#include<vector>

using namespace std;
#define N 10005
int n,m,p,mymax,now,nbegin,nend,mbegin,mend;
int  a[N];

int main(){
	cin>>n;
	a[0] = 0;
	bool all_nagative = true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0) all_nagative = false;
	}
	if(!all_nagative){
		p = 1;
		mymax = -1;
		now = 0;
		nbegin = 1;nend = 1;
		mbegin = 1;mend = 1;
		while(p<=n){
			now+=a[p];
			if(now<0){
				now = 0;
				nbegin = p+1;
				nend = p+1;
			}else{
				nend = p;
				if(now>mymax){
					mymax = now;
					mbegin = nbegin;
					mend = nend;
				}
			}
			p++;
		}
		cout<<mymax<<" "<<a[mbegin]<<" "<<a[mend];
	}else{
		cout<<0<<" "<<a[1]<<" "<<a[n];
	}
}
