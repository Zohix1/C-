#include<bits/stdc++.h>
using namespace std;
enum RAM_Rank{DDR=1,DDR2,DDR3};
enum CPU_Rank{i3,i5,i7,i9};
class CPU
{
private:
    enum CPU_Rank a;
    int frequency1;
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
    CPU(CPU_Rank a1,int f,float v){
        cout<<"正在构造对象CPU"<<endl;
        this->a=a1;
        frequency1=f;
        voltage=v;
    };
    CPU(){
        a=i3;
        frequency1=2000;
        voltage=2.0;
        cout<<"正在默认构造对象CPU"<<endl;
    };
    void Complex(const CPU&c){
        cout<<"正在复制构造对象CPU"<<endl;
        a=c.a;
        frequency1=c.frequency1;
        voltage=c.voltage;
    }
    CPU(const CPU&c){
        cout<<"正在复制构造对象CPU"<<endl;
        a=c.a;
        frequency1=c.frequency1;
        voltage=c.voltage;
    }
    ~CPU(){
        cout<<"正在删除对象CPU"<<endl;
    };
    
};
    
CPU_Rank CPU::GetRank(){
    return a;
}
int CPU::GetFrequency(){
    return frequency1;
}
float CPU::GetVoltage(){
    return voltage;
}
void CPU::SetRank(CPU_Rank r){
    this->a=r;
}
void CPU::SetFrequency(int f){
    this->frequency1=f;
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
        case i3:cout<<"i3"<<" ";break;
        case i5:cout<<"i5"<<" ";break;
        case i7:cout<<"i7"<<" ";break;
        case i9:cout<<"i9"<<" ";break;
    }
    cout<<frequency1<<" "<<voltage<<" ";
}

class RAM{
private:
    enum RAM_Rank x;
    int Memory;
    float frequency;
public:
    void SetRank(RAM_Rank r);
    void SetFrequency(float f);
    void SetMemory(int m);
    RAM(RAM_Rank x1,int m,float f){
        x=x1;
        Memory=m;
        frequency=f;
        cout<<"正在构造对象RAM"<<endl;
    };
    RAM(){
        cout<<"正在默认构造对象RAM"<<endl;
        x=DDR;
        Memory=6;
        frequency=2.0;
    }
    void Complex(const RAM&c){
        x=c.x;
        Memory=c.Memory;
        frequency=c.frequency;
        cout<<"正在复制构造对象RAM"<<endl;
    }
    RAM(const RAM&c){
        x=c.x;
        Memory=c.Memory;
        frequency=c.frequency;
        cout<<"正在复制构造对象RAM"<<endl;
    }
    ~RAM(){
        cout<<"正在删除对象RAM"<<endl;
    }
    void Print(){
        switch(x){
            case 1:cout<<DDR<<" ";break;
            case 2:cout<<DDR2<<" ";break;
            case 3:cout<<DDR3<<" ";break;
        }
        cout<<Memory<<" "<<frequency<<" ";
    }
    void Run(){
        cout<<"RAM开始运行!"<<endl;
    }
    void Stop(){
        cout<<"RAM停止运行!"<<endl;
    }
};
void RAM::SetRank(RAM_Rank r){
    this->x=r;
}
void RAM::SetFrequency(float f){
    frequency=f;
}
void RAM::SetMemory(int m){
    Memory=m;
}
class COMPUTER
{
private:
    int price;
    CPU a1;
    RAM b1;
public:
    COMPUTER(){
        cout<<"默认构造了一个COMPUTER!"<<endl;
        CPU (this->a1);
        RAM (this->b1);
        price=3000;
    };
    COMPUTER(const COMPUTER& c){
        cout<<"调用COMPUTER的复制构造函数"<<endl;
        a1.Complex(c.a1);
        b1.Complex(c.b1);
        price=c.price;
    };
    COMPUTER(CPU a,RAM b,int price1){
        a1.Complex(a);
        b1.Complex(b);
        this->price=price1;
    }
    
    void Print(){
        a1.Print();
        b1.Print();
        cout<<price<<endl;
    }
    void Run(){
        a1.Run();
        b1.Run();
        cout<<"COMPUTER开始运行!"<<endl;
    }
    void Stop(){
        a1.Stop();
        b1.Stop();
        cout<<"COMPUTER停止运行!"<<endl;
    }
    void SetComputer(enum CPU_Rank a,int frequency1,float voltage,enum RAM_Rank x,int Memory,float frequency,int price1){
        a1.SetFrequency(frequency1);
        a1.SetRank(a);
        a1.SetVoltage(voltage);
        b1.SetFrequency(frequency);
        b1.SetMemory(Memory);
        b1.SetRank(x);
        price=price1;
    }
    ~ COMPUTER(){
        cout<<"正在删除COMPUTER对象!"<<endl;
    };
    
};

int main(){
    CPU mycpu(i5,2400,2.8);
    RAM myram(DDR3,8,2.4);
    COMPUTER computer1(mycpu,myram,4000);
    computer1.Print();
    computer1.Run();
    computer1.Stop();
    COMPUTER computer2(computer1);
    computer2.Print();
    computer2.SetComputer(i7,3000,4.0,DDR3,16,6.0,6000);
    computer2.Print();
    return 0; 
}
