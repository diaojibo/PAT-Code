#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

struct rt{
	long long d,n;
	int sign;
};

rt x,y;
char tempx[100],tempy[100];


long gcd(long x,long y){
	if(x<y) return gcd(y,x);
	if(y==0) return x;
	return gcd(y,x % y);
}



rt simp(rt x){
	if(x.d<0) return x;
	int f = gcd(x.d,x.n);
	x.d = x.d / f;
	x.n = x.n / f;
	return x;
}


rt rinit(char x[]){
	int p=0;
	rt t;
	t.n=0;t.d=0;t.sign=1;
	if(x[0]=='-') t.sign=-1,p=1;
	while(x[p]!='/'){
		int q=int(x[p]-'0');
		t.n = t.n*10+q;
		p++;
	}
	p++;
	while(x[p]!=0){
		int q=int(x[p]-'0');
		t.d = t.d*10+q;
		p++;
	}
	return simp(t);
}



rt radd(rt x,rt y){
	rt t;
	t.d = x.d*y.d;
	t.n = x.n*y.d*x.sign+y.n*x.d*y.sign;
	if(t.n>=0) t.sign=1;
	else{
		t.sign = -1;
		t.n = -t.n;
	}
	return simp(t);
}

rt rsub(rt x,rt y){
	rt t;
	t.d = x.d*y.d;
	t.n = x.n*y.d*x.sign-y.n*x.d*y.sign;
	if(t.n>=0) t.sign=1;
	else{
		t.sign = -1;
		t.n = -t.n;
	}
	return simp(t);
}

rt rmult(rt x,rt y){
	rt t;
	t.d = x.d*y.d;
	t.n = x.n*y.n*x.sign*y.sign;
	if(t.n>=0) t.sign=1;
	else{
		t.sign = -1;
		t.n = -t.n;
	}
	return simp(t);
}

rt rdiv(rt x,rt y){
	rt t;
	if(y.n==0){
		t.n = 0;
		t.sign = 1;
		t.d=-1;
		return simp(t);
	}
	
	t.d = x.d * y.n*y.sign;
	t.n = x.n*y.d*x.sign;
	if(t.n>=0) t.sign=1;
	else{
		t.sign = -1;
		t.n = -t.n;
	}
	if(t.d<0) t.sign = -t.sign,t.d=-t.d;
	return simp(t);
}


void pri(rt x){
	x = simp(x);
	if(x.d<=0){
		//printf("...%d %d...",x.d,x.n);
		printf("Inf");
		return;
	}
	if(x.n==0){
		printf("0");
		return;
	}
	if(x.sign<0) printf("(-");
	if(x.n%x.d==0){
		printf("%d",x.n/x.d);
	}
	else if(x.n>x.d){
		printf("%d ",x.n/x.d);
		printf("%d/%d",x.n%x.d,x.d);
	}else{
		printf("%d/%d",x.n,x.d);
	}
	if(x.sign<0) printf(")");
}

int main(){
	scanf("%s",&tempx);
	scanf("%s",&tempy);
	x = rinit(tempx);
	y = rinit(tempy);
	pri(x);printf(" + ");pri(y);printf(" = ");pri(radd(simp(x),simp(y)));printf("\n");
	pri(x);printf(" - ");pri(y);printf(" = ");pri(rsub(simp(x),simp(y)));printf("\n");
	pri(x);printf(" * ");pri(y);printf(" = ");pri(rmult(simp(x),simp(y)));printf("\n");
	pri(x);printf(" / ");pri(y);printf(" = ");pri(rdiv(simp(x),simp(y)));printf("\n");
}
 
