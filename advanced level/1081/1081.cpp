#include<stdio.h>
#include<vector>
using namespace std;

char temp[100];
int n;

struct rational{
	long num;
	long den;
	bool positive;
};
vector<rational> a;
int gcd(int x,int y){
	if(x<y) return gcd(y,x);
	if(y==0) return x;
	return gcd(y,x%y);
}
rational simpler(rational x){
	int g = gcd(x.den,x.num);
	rational y;
	y.den = x.den / g;
	y.num = x.num / g;
	y.positive = x.positive;
	return y;
}

rational addr(rational x,rational y){
	long fenmu = x.den*y.den;
	long a1,a2;
	if(x.positive) a1=x.num;
	else a1 = -x.num;
	if(y.positive) a2=y.num;
	else a2 = -y.num;
	long fenzi = a1*y.den+a2*x.den;
	rational res;
	if(fenzi<0) res.positive=false;
	else res.positive = true;
	res.den = fenmu;
	res.num = fenzi;
	return simpler(res);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",&temp);
		rational t;
		long j,q=0;
		if(temp[0]=='-'){
			t.positive = false;
			j=1;
			while(temp[j]!='/'){
				q = q*10+int(temp[j]-'0');
				j++;
			}
			j++;
			t.num = q;q=0;
			while(temp[j]!=0){
				q=q*10+int(temp[j]-'0');
				j++;
			}
			t.den = q;
		}else{
			t.positive = true;
			j=0;
			while(temp[j]!='/'){
				q = q*10+int(temp[j]-'0');
				j++;
			}
			j++;
			t.num = q;q=0;
			while(temp[j]!=0){
				q=q*10+int(temp[j]-'0');
				j++;
			}
			t.den = q;
		}
		//printf("fenzi=%d,fenmu=%d\n",t.num,t.den);
		a.push_back(simpler(t));
	}
	rational x = a[0];
	for(int i=1;i<n;i++){
		x = addr(x,a[i]);
		//printf("fenzi=%d,fenmu=%d\n",x.num,x.den);
	}
	if(x.den==1){
		if(!x.positive) printf("-");
		printf("%ld",x.num);
	}else{
		if(x.num>x.den){
			int y=x.num / x.den;
			if(!x.positive) printf("-");
			printf("%ld",y);
			if(x.num%x.den==0) return 0;
			printf(" %ld/%ld",x.num%x.den,x.den);
		}else{
			if(x.num==0){
				printf("0");
				return 0;
			}
			if(!x.positive) printf("-");
			printf("%ld/%ld",x.num,x.den);
		}
	}
}
