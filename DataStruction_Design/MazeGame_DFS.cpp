#include<bits/stdc++.h>
using namespace std;

typedef struct Map{
    char value[100][100];
    int state[100][100];
    int line,column;
    int start_x,start_y;
    int end_x,end_y;

    Map(int line,int column,int start_x,int start_y,int end_x,int end_y){
        this->start_x=start_x;
        this->start_y=start_y;
        this->end_x=end_x;
        this->end_y=end_y;
        this->line=line;
        this->column=column;
        cout<<"请输入地图:"<<endl;
        for(int i = 0; i < line; i++) {
            char c;
            for(int j = 0; j < column; j++){
                scanf("%c",&value[i][j]);
                c=getchar();
                state[i][j] = 0;
            }
        }
        
    }

}Map;

typedef struct StackNode{
    string value;
    StackNode* next;
}Node;

typedef struct Stack{
    StackNode* top;

    Stack(){
        top=new StackNode;
        top->next=NULL;
    }
    void Push(string str){
        StackNode* p=new StackNode;
        p->next=top->next;
        p->value=str;
        top->next=p;
    }
    void Print(){
        StackNode* ptr=top->next;
        while(ptr->next){
            cout << ptr->value<<"——>";
            ptr=ptr->next;
        }
    }

}Stack;

Stack* s=new Stack();

bool Judge(Map& map,int line,int column){
    if(map.value[line][column]=='#'||line>=map.line||column>=map.column||line<0||column<0)
        return false;
    else{
        map.state[line][column]=1;
        if(line==map.end_x&&column==map.end_y){
            return true;
        }
        else{
            if(map.state[line][column+1]==0&&Judge(map,line,column+1)){
                map.state[line][column+1]=1;
                string itm="(" + to_string(line) + "," + to_string(column+1) + ")";
                s->Push(itm);
                return true;
            }
            else if(map.state[line+1][column]==0&&Judge(map,line+1,column)){
                map.state[line][column+1]=1;
                string itm="(" + to_string(line+1) + "," + to_string(column) + ")";
                s->Push(itm);
                return true;
            }
            else if(map.state[line][column-1]==0&&Judge(map,line,column-1)){
                map.state[line][column-1]=1;
                string itm="(" + to_string(line) + "," + to_string(column-1) + ")";
                s->Push(itm);
                return true;
            }
            else if(map.state[line-1][column]==0&&Judge(map,line-1,column)){
                map.state[line-1][column]=1;
                string itm="(" + to_string(line-1) + "," + to_string(column+1) + ")";
                s->Push(itm);
                return true;
            }
            else{
                return false;
            }
        }        
    }
}

int main(){
    cout<<"请输入地图行数、列数、起点和终点:"<<endl;
    int line,column;
    int start_x,start_y;
    int end_x,end_y;
    cin>>line>>column>>start_x>>start_y>>end_x>>end_y;
    char c=getchar();
    Map map(line,column,start_x,start_y,end_x,end_y);
    if(Judge(map,map.start_x,start_y)){
        printf("(%d,%d)——>",start_x,start_y);
        s->Print();
        printf("(%d,%d)\n",end_x,end_y);
    }
    else{
        cout<<"无法到达终点"<<endl;
    }
}