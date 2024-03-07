#include<bits/stdc++.h>
using namespace std;
class Clock{
public:
    void showTime(){
        printf("%02d:%02d:%02d\n",hour,minute,second);
    }
    void setTime(int a=8,int b=8,int c=8);
private:
    int hour;
    int minute;
    int second;
};
void Clock::setTime(int a,int b,int c){
    this->hour=a;
    this->minute=b;
    this->second=c;
}

int main(){
    Clock p,q;
    int hour,minute,second;
    cout<<"ÊäÈëÊ±£º·Ö£ºÃë"<<endl;
    scanf("%d:%d:%d",&hour,&minute,&second);
    p.setTime(hour,minute,second);
    p.showTime();
    q.setTime();
    q.showTime();
    return 0;
}