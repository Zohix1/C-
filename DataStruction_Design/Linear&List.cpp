#include<iostream>
using namespace std;

typedef struct ListNode
{
    ListNode* next;
    int data;
}ListNode;

typedef struct List
{
    ListNode* head;
    int number;
    ListNode* ptr;

    List(int number);

    void Delete(int m);

    void Print();

}List;
//List构造函数
List::List(int number){
    ListNode* p;
    int count=1;
    this->number=number;

    this->head=new(ListNode);
    this->head->next=new(ListNode);
    number--;
    p=this->head->next;
    p->data=count;
    count++;

    while(number){
        p->next=new(ListNode);
        p=p->next;
        p->data=count;
        count++;
        number--;
    }
    p->next=this->head->next;

    this->ptr=this->head->next;
}
//List删除对象
void List::Delete(int m){
    int count=1;
    while(count<m-1){
        ptr=ptr->next;
        count++;
    }

    ListNode* p=ptr->next;
    ptr->next=p->next;

    printf("%d  ",p->data);

    delete(p);
    ptr=ptr->next;

    this->number--;
}
//List打印剩余人数
void List::Print(){
    ListNode* p=this->head->next;
    ListNode* d;
    for(int i=0;i<this->number;i++){
        printf("%d  ",p->data);
        d=p;
        p=p->next;
        delete(d);
    }
    printf("\n");
}
/*#########################################*/
typedef struct Linear
{
    int* data;
    int number;
    int ptr;

    Linear(int number);

    void Delete(int m);

    void Print();

}Linear;
//Linear构造函数
Linear::Linear(int number){
    this->number=number;
    this->ptr=0;
    this->data=new int[number];
    for(int i=0;i<number;i++){
        this->data[i]=i+1;
    }
}
//Linear删除对象
void Linear::Delete(int m){
    int count=1;
    while(count<m){
        ptr=(ptr+1)%number;
        count++;
    }
    printf("%d  ",this->data[ptr]);

    for(int i=ptr;i<number-1;i++){
        this->data[i]=this->data[i+1];
    }
    number--;
    // ptr=(ptr+1)%number;
}
//Linear打印剩余人数
void Linear::Print(){
    for(int i=0;i<number;i++){
        printf("%d  ",this->data[i]);
    }
    printf("\n");

    delete(this->data);
}

//主函数
int main(){
    int number;
    int m;
    cin>>number>>m;
    List list_imp(number);
    while(list_imp.number>(number/2))
        list_imp.Delete(m);
    printf("\n");
    list_imp.Print();

    Linear linear_imp(number);
    while(linear_imp.number>(number/2))
        linear_imp.Delete(m);
    printf("\n");
    linear_imp.Print();
}