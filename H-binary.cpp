#include<bits/stdc++.h>
using namespace std;

string getNextBinaryString(const string &current) {
    string next = current;
    int len = next.length();
    int i = len - 1;
    while (i >= 0 && next[i] == '1') {
        next[i] = '0';
        --i;
    }
    if (i >= 0) {
        next[i] = '1';
    } else {
        next = '1' + next;
    }
    return next;
}

int main(){
    long long n;
    string origin;
    cin>>n;
    cin>>origin;
    long long time=origin.length();
    string temp="1";
    for(long long i=1;i<=time;i++){
        if(temp.length()>origin.length()){
            break;
        }
        size_t pos=origin.find(temp);
        if(pos != string::npos){
            size_t pos2 = 0;
            long long count = 0;
            while ((pos2 = origin.find(temp,pos2)) != string::npos) {
                ++count;
                pos2 += 1;
            }
            cout<<pos+1<<" "<<count;
            origin.erase(pos, temp.length());
        }
        else{
            cout<<"-1 0";
        }
        if(i!=time)
            printf("\n");
        temp=getNextBinaryString(temp);
    }
}
