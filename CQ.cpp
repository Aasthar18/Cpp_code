#include <iostream>
using namespace std;

class queue
{
public:
    int front, rear, size;
    int *arr;

    queue(int n)
    {
        arr = new int[n];
        size = n;
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if ((rear + 1) % size == front)
        {
            cout << "full" << endl;
            // return;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = x;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Empty" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Empty" << endl;
        }
        else if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    queue Q1(5);
    Q1.enqueue(5);
    Q1.enqueue(4);
    Q1.enqueue(3);
    Q1.enqueue(2);
    Q1.enqueue(1);
    Q1.display();
    Q1.dequeue();
    Q1.display();
    return 0;
}