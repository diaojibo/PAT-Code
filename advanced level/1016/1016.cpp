#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<sstream>
#include<iomanip>
using namespace std;

struct records{
	string name;
	int mo,dd,hh,mm;
	int status;
};
struct calls{
	string start;
	string end;
	int mint;
	float money;
};


int paid[24];
int n;
vector<records> v;
bool flag[1001];
vector<calls> c;


bool comparev(records x,records y){
	if(x.name!=y.name) return x.name<y.name;
	if(x.mo!=y.mo) return x.mo<y.mo;
	if(x.dd!=y.dd) return x.dd<y.dd;
	if(x.hh!=y.hh) return x.hh<y.hh;
	if(x.mm!=y.mm) return x.mm<y.mm;
	return false;
	
}

string makest(records x){
	stringstream sss;
	sss.str();
	if(x.dd<10) sss<<0;
	sss<<x.dd<<":";
	if(x.hh<10) sss<<0;
	sss<<x.hh<<":";
	if(x.mm<10) sss<<0;
	sss<<x.mm;
	return sss.str();
	
}

int calrec(records x,records y){
	int minx,miny;
	minx = (x.dd*24*60+x.hh*60+x.mm);
	miny = (y.dd*24*60+y.hh*60+y.mm);
	return miny-minx;
}

float calmoney(records x){
	int d = x.dd;
	int sum=0;
	float im=0;
	for(int i=0;i<24;i++) sum+=paid[i]*60;
	im = (d-1)*sum;
	for(int i=0;i<=x.hh-1;i++) im+=60*paid[i];
	im+=x.mm*paid[x.hh];
	return im/100;
}

int main(){
	for(int i=0;i<24;i++) cin>>paid[i];
	cin>>n;
	for(int i=0;i<n;i++){
		records r;
		flag[i] = false;
		char temp[25],temp2[10];
		scanf("%s %d:%d:%d:%d %s",&temp,&r.mo,&r.dd,&r.hh,&r.mm,&temp2);
		if(temp2[1]=='n') r.status = 0;//on
		else r.status = 1;//off
		r.name = string(temp);
		v.push_back(r);
	}
	sort(v.begin(),v.end(),comparev);
	//for(int i=0;i<v.size();i++) cout<<v[i].name<<" "<<v[i].mo<<" "<<v[i].dd<<endl;
	int l = v.size();
	string uname="";
	stringstream ss;
	stringstream ts;
	int x=-1,y=-1;
	calls cc;
	for(int i=0;i<l;i++){
		ss.str("");
		ss<<v[i].name<<" "<<setw(2)<<setfill('0')<<v[i].mo;
		//cout<<"test: "<<ss.str()<<endl;
		if(uname==""||uname!=ss.str()){
			int lc = c.size();
			if(lc>0){
				cout<<uname<<endl;
				double tol = 0;
				for(int j=0;j<lc;j++){
					printf("%s %s %d $%.2lf\n",c[j].start.c_str(),c[j].end.c_str(),c[j].mint,c[j].money);
					tol += c[j].money;
					//cout<<c[j].start<<" "<<c[j].end<<" "<<c[j].mint<<" $"<<c[j].money<<endl;
				}
				printf("Total amount: $%.2lf\n",tol);
			}
			uname = ss.str();
			c.clear();
			x=-1;y=-1;
		}
		if(v[i].status==0){
			x = i;
			
		}
		if(x!=-1&&v[i].status==1){
			y=i;
			//cout<<x<<" "<<y<<endl;
			cc.start = makest(v[x]);
			cc.end = makest(v[y]);
			cc.mint = calrec(v[x],v[y]);
			cc.money = calmoney(v[y]) - calmoney(v[x]);
			c.push_back(cc);
			x=-1;y=-1;
		}
	}
	int lc = c.size();
	double tol = 0;
	if(lc>0){
		cout<<uname<<endl;
		for(int j=0;j<lc;j++){
			printf("%s %s %d $%.2lf\n",c[j].start.c_str(),c[j].end.c_str(),c[j].mint,c[j].money);
			tol += c[j].money;
			}
			printf("Total amount: $%.2lf\n",tol);
	}	
}
