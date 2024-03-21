#include<bits/stdc++.h>
using namespace std;

typedef struct File{
    string filename;

    File(string& filename) {
        this->filename=filename;
        ofstream file(filename);
        string line;
        cout<<"�������ļ����ݣ� "<<endl;
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
            // ����������ַ���ƥ�亯������line���д���
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
            // ����������ַ���ƥ�亯������line���д���
            // ��ӡ�кš����ʳ��ִ�����λ��
            if(searchWord(line,word,1)){
                printf("LineNumber:  %d\n\n",lineNumber);
            }
        }
    }

    int searchWord(string &line, string &word, int type) {
        int count = 0;
        size_t pos = line.find(word, 0); // ʹ�ñ�׼�⺯�����ҵ���
        while(pos != string::npos) {
            count++;
            if(type){
                cout<<"Position: "<<pos<<endl;
            }
            pos = line.find(word, pos + 1); // ������һ������λ��
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