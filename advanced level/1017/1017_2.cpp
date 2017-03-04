#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;


int m,n,k;
struct per{
	int arr;
	int process;
};

struct window{
	int people;
	int end_time;
};

int getsecond(int x,int y,int z){
	return x*60*60+y*60+z;
}

bool mycmp(per x,per y){
	return x.arr<y.arr;
}

vector<per> a;
vector<window> w;
int num,total;
void getout(int now){
	for(int i=0;i<k;i++){
		if(w[i].people!=-1){
			if(w[i].end_time <= now) {
				//printf("%d is out now:%d\n",w[i].people,now);
				w[i].people = -1;
			}
		}
	}
}
double wait_time = 0;
int getin(int now,int p){
	bool onein = false;
	for(int i=p;i<total;i++){
		if(a[i].arr>now) return i;
		onein = false;
		for(int j=0;j<k;j++){
			if(w[j].people==-1){
				w[j].people = i;
				w[j].end_time = now + a[i].process;
				wait_time += now - a[i].arr;
				//printf("%d in time:%d\n",i,now);
				onein = true;
				break;
			}
		}
		if(!onein) return i;
	}
	return total;
}




int main(){
	scanf("%d %d",&n,&k);
	int latest = getsecond(17,0,0);
	for(int i=0;i<n;i++){
		int x,y,z,t;
		per temp;
		scanf("%d:%d:%d %d",&x,&y,&z,&t);
		temp.arr = getsecond(x,y,z);
		temp.process = t*60;
		if(temp.arr>latest) continue;
		a.push_back(temp);
	}
	for(int i=0;i<k;i++){
		window t;
		t.end_time = -1;
		t.people = -1;
		w.push_back(t);
	}
	sort(a.begin(),a.end(),mycmp);
//	for(int i=0;i<a.size();i++){
//		printf("arr=%d process=%d\n",a[i].arr,a[i].process);
//	}
	int start = getsecond(8,0,0);
	num = a.size();
	total = num;
	int time = start;
	int p = 0;
	while(p<total){
		getout(time);
		p = getin(time,p);
		time++;
	}
	printf("%.1f",wait_time/60/num+0.0000001);
}
