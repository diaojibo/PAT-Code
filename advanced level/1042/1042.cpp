#include<vector>
#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
string cards[55],answer[55];
int order[55];
int k;
int main(){
  scanf("%d",&k);
  for(int i=1;i<=13;i++){
    stringstream ss;
    ss.str("");
    ss<<'S'<<i;
    cards[i] = ss.str();
    ss.str("");ss<<'H'<<i;
    cards[i+13]=ss.str();
    ss.str("");ss<<'C'<<i;
    cards[i+13*2]=ss.str();
    ss.str("");ss<<'D'<<i;
    cards[i+13*3]=ss.str();    
  }
  cards[53]="J1";cards[54]="J2";
  for(int i=1;i<=54;i++){
    scanf("%d",&order[i]);
  }
  for(int i=0;i<k;i++){
    for(int i=1;i<=54;i++){
      answer[order[i]] = cards[i];
    }
    for(int i=1;i<=54;i++) cards[i] = answer[i];
  }
  for(int i=1;i<=53;i++) printf("%s ",cards[i].c_str());
  printf("%s",cards[54].c_str());
}
