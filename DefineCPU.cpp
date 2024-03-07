#include<bits/stdc++.h>
using namespace std;
enum CPU_Rank{i3,i5,i7,i9};
class CPU
{
private:
    enum CPU_Rank a;
    int frequency;
    float voltage;
public:
    CPU_Rank GetRank();
    int GetFrequency();
    float GetVoltage();
    void SetRank(CPU_Rank r);
    void SetFrequency(int f);
    void SetVoltage(float v);
    void Print();
    void Run();
    void Stop();
};
CPU_Rank CPU::GetRank(){
    return a;
}
int CPU::GetFrequency(){
    return frequency;
}
float CPU::GetVoltage(){
    return voltage;
}
void CPU::SetRank(CPU_Rank r){
    this->a=r;
}
void CPU::SetFrequency(int f){
    this->frequency=f;
}
void CPU::SetVoltage(float v){
    this->voltage=v;
}
void CPU::Run(){
    cout<<"CPU开始运行!"<<endl;
}
void CPU::Stop(){
    cout<<"CPU停止运行!"<<endl;
}
void CPU::Print(){
    switch(a){
        case i3:cout<<"i3";break;
        case i5:cout<<"i5";break;
        case i7:cout<<"i7";break;
        case i9:cout<<"i9";break;
    }
    cout<<" "<<frequency<<" "<<voltage<<endl;
}

int main(){
    CPU i;
    CPU_Rank a;
    int b,d;
    float c;
    cout<<"设置CPU型号:"<<endl;
    cin>>d;
    a=(CPU_Rank)d;
    i.SetRank(a);
    cout<<"设置CPU频率:"<<endl;
    cin>>b;
    i.SetFrequency(b);
    cout<<"设置CPU电压:"<<endl;
    cin>>c;
    i.SetVoltage(c);
    i.Print();
    i.Run();
    i.Stop();
    return 0;
}
