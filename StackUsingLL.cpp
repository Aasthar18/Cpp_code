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
    node *head = NULL;

public:
    void insertAtHead(int val)
    {
        node *n = new node(val);

        n->next = head;
        head = n;
    }

    void deleteHead()
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
    }

    void getHead()
    {
        cout << head->data << endl;
    }

    bool is_empty()
    {
        return (head == NULL);
    }

    void clear()
    {
        head = NULL;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        // cout << "Null";
        cout << endl;
    }
};

class stack
{
    sll list;

public:
    void push(int x)
    {
        list.insertAtHead(x);
    }

    void pop()
    {
        if (list.is_empty())
        {
            cout << "Stack Empty" << endl;
            return;
        }
        list.deleteHead();
    }

    void topel()
    {
        if (list.is_empty())
        {
            cout << "Stack Empty" << endl;
            return;
        }
        cout << "Top Element: ";
        list.getHead();
        // cout << endl;
    }

    void clear()
    {
        list.clear();
    }

    void is_empty()
    {
        if (list.is_empty())
        {
            cout << "Stack Empty" << endl;
            return;
        }
        else
        {
            cout << "Stack Not Empty" << endl;
        }
    }

    void display()
    {
        if (list.is_empty())
        {
            cout << "Stack Empty" << endl;
            return;
        }

        cout << "Stack: ";
        list.display();
    }
};

int main()
{
    stack s1;
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