#include <iostream>
using namespace std;
class DiagonalMatrix
{
    private:
        int *B;
        int n;
    public:
        DiagonalMatrix ()
        {
            n = 2;
            B = new int[2];
        }
    DiagonalMatrix (int n)
    {
        this->n = n;
        B = new int[n];
    }
    ~DiagonalMatrix ()
    {
        delete[]B;
    }
    void Set (int i, int j, int y);
    int Get (int i, int j);
    void Display ();
};
void DiagonalMatrix::Set (int i, int j, int y)
{
    if (i == j)
        B[i - 1] = y;
}
int DiagonalMatrix::Get (int i, int j)
{
    if (i == j)
        return B[i - 1];
    return 0;
}
void DiagonalMatrix::Display ()
{
    cout << "\nMatrix is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
           if (i == j)
             cout << B[i - 1] << " ";
           else
             cout << "0 ";
        }
        cout << endl;
    }
}
int main ()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;
    DiagonalMatrix dm (d);
    int x;
    cout << "Enter All Elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
           cin >> x;
           dm.Set (i, j, x);
        }
    }
    dm.Display ();
    return 0;
}