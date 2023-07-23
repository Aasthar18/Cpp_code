// #include <iostream>
// using namespace std;
// class queue{
//     int a[5];
//     int front;
//     int back;
//     public :
//     queue(){
//         front = -1;
//         back = -1;
//     }
//     void enqueue(int x);
//     void dequeue();
//     bool isEmpty();
//     int peek();   // top
//     void display();
// };
// void queue :: enqueue(int x){
//     if(back == 4){
//         cout<<"queue is full"<<endl;
//     }
//     else{
//         back ++;
//         a[back] = x;
//     }
//     if(front ==-1 ){
//         front++;
      
//         a[front]=x;
//     }
      
// }
// void queue :: dequeue(){
//     if(front==-1 || front>back){
//         cout<<"Queue is empty : "<<endl;
//     }
//     else
//       front++;
// }
// int queue:: peek(){
//     if(front==-1 || front>back){               
//         cout<<"Queue is empty : "<<endl;
//     }

//     return a[front++];
    
// }
// bool queue:: isEmpty(){
//     if(front==-1||front>back){
//         return true;
//     }
//     else 
//         return false;
// }
// void queue:: display(){
//     if(front==-1){
//       cout<<"NO element";
//     }
//     else{
//         for(int i = front;i<=back;i++){
//             cout<<a[i]<<" ";
//         }
//     }
//     cout<<endl;
// }

// int main(){
// queue q;
// q.enqueue(2);
// q.enqueue(5);
// q.enqueue(1);
// q.enqueue(7);
// q.enqueue(4);
// q.display();
// // cout<<endl<<q.peek()<<endl;
// // cout<<q.peek()<<endl;
// q.dequeue();
// q.display();
// // q.dequeue();
// // cout<<q.isEmpty();
//  }

#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class sll
{
protected:
    node *front = NULL;
    node *rear=NULL;

public:
    void insertAtrear(int val)
    {
        node *n = new node(val);

        rear->next = n;
        rear = n;
        if(front==NULL)
        front=n;
    }

    void deletefront()
    {
        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    // void getfront()
    // {
    //     cout << front->data << endl;
    // }

    bool is_empty()
    {
        return (front == NULL);
    }

    void clear()
    {
        front = NULL;
    }

    void display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        // cout << "Null";
        cout << endl;
    }
};

class queue{
    sll list;

public:
    void push(int x)
    {
        list.insertAtrear(x);
    }

    void pop()
    {
        if (list.is_empty())
        {
            cout << "queue Empty" << endl;
            return;
        }
        list.deletefront();
    }

    // void topel()
    // {
    //     if (list.is_empty())
    //     {
    //         cout << "queue Empty" << endl;
    //         return;
    //     }
    //     cout << "Top Element: ";
    //     list.getfront();
    //     // cout << endl;
    // }

    void clear()
    {
        list.clear();
    }

    void is_empty()
    {
        if (list.is_empty())
        {
            cout << "queue Empty" << endl;
            return;
        }
        else
        {
            cout << "queue Not Empty" << endl;
        }
    }

    void display()
    {
        if (list.is_empty())
        {
            cout << "queue Empty" << endl;
            return;
        }

        cout << "queue: ";
        list.display();
    }
};

int main()
{
    queue s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.display();
//     // s1.topel();
//     s1.is_empty();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     // s1.topel();
//     // s1.display();
//     s1.is_empty();
//     // s1.clear();

//     // s1.display();

//     return 0;
}