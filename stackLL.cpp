#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
class stack{
    public:
    Node *top;
    stack(){
        top=NULL;
    }
    void push(int x);
    void pop();
    void display();
};
void stack::push(int x){
    Node *temp=new Node;
    if(temp==NULL){
    cout<<"overflow"<<endl;}
    temp->data=x;
    temp->next=NULL;
    top->next=temp;
    top=temp;
}
void stack::pop(){
    Node *temp=top;
    if(top==NULL){
        cout<<"empty stack"<<endl;
    }
    top=top->next;
    cout<<top<<"is being deleted."<<endl;
    
}
void stack:: display(){
    if(top==NULL)
    cout<<"empty stack"<<endl;
    Node *temp=top;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    stack s;
    s.push(2);
     s.push(3);
      s.push(5);
       s.push(1);
        s.push(7);
        s.display();
        // s.pop();
        //  s.display();

}