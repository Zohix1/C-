#include<bits/stdc++.h>
using namespace std;

typedef struct File{
    string filename;

    File(string& filename) {
        this->filename=filename;
        ofstream file(filename);
        string line;
        cout<<"请输入文件内容： "<<endl;
        while (getline(cin, line) && line != "END") {
            file << line << endl;
        }
        file.close();
    }
    
    int countWord(string& word) {
        ifstream file(filename);
        string line;
        int count = 0;
        while (getline(file, line)) {
            // 在这里调用字符串匹配函数，对line进行处理
            count+=searchWord(line,word,0);
        }
        return count;
    }

    void findWordPositions(string& word) {
        ifstream file(filename);
        string line;
        int lineNumber = 0;
        while (getline(file, line)) {
            lineNumber++;
            // 在这里调用字符串匹配函数，对line进行处理
            // 打印行号、单词出现次数和位置
            if(searchWord(line,word,1)){
                printf("LineNumber:  %d\n\n",lineNumber);
            }
        }
    }

    int searchWord(string &line, string &word, int type) {
        int count = 0;
        size_t pos = line.find(word, 0); // 使用标准库函数查找单词
        while(pos != string::npos) {
            count++;
            if(type){
                cout<<"Position: "<<pos<<endl;
            }
            pos = line.find(word, pos + 1); // 查找下一个出现位置
        }
        return count;
    }
}File;


int main(){
    string filename="./test.txt";
    File f(filename);
    string findword="apple";
    f.countWord(findword);
    f.findWordPositions(findword);
}