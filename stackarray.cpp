#include<iostream>
using namespace std;
const int size = 5;
class stack{
    int s[size];
    int top ;
    public :
    stack(){
        top = -1;
    }
    void push(int);
    int pop();
    void display();
    bool isEmpty();
    // int full();
};
void stack :: push(int item){
    if(top==size-1){
        cout<<"stack is overflow "<<endl;
    }
    else{
        top++;
        s[top]=item;
    }
}
int stack :: pop(){
    if(top==-1){
        cout<<"stack is underflow "<<endl;
    }
    else 
     return s[top--];
}
void stack :: display(){
    if (top == -1){
        cout<<"nothing can be displayed";
    }
    else{
        cout<<"elements are : "<<endl;
        
        for(int i= top;i>=0;i--){
            cout<<s[i]<<" ";
            cout<<endl;
        }
    }
}
bool stack::isEmpty(){
    if(top==-1)
       return true;
    else
        return false;
}
int main(){
    stack ob;
   ob.push(8);
   ob.push(0);
   ob.push(9);
   ob.push(3);
   ob.display();
//    cout<<ob.pop()<<endl;
    // return 0;
  
}