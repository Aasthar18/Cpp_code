#include <iostream>
using namespace std;
class UpperTriangularMatrix
{
    private:
        int *B;
        int n;
    public:
        UpperTriangularMatrix ()
        {
            n = 3;
            B = new int[3 * (3 + 1) / 2];
        }
        UpperTriangularMatrix (int n)
        {
            this->n = n;
            B = new int[n * (n + 1) / 2];
        }
        ~UpperTriangularMatrix ()
        {
            delete[]B;
        }
        int GetDimension ()
        {
            return n;
        }
    void Set (int i, int j, int y);
    int Get (int i, int j);
    void Display ();
};
void UpperTriangularMatrix::Set (int i, int j, int y)
{
    if (i <= j)
        B[((i - 1) * n - (i - 2) * (i - 1) / 2) + (j - i)] = y;
}
int UpperTriangularMatrix::Get (int i, int j)
{
    if (i <= j)
        return B[((i - 1) * n - (i - 2) * (i - 1) / 2) + (j - i)];
    return 0;
}
void UpperTriangularMatrix::Display ()
{
    cout << "\nMatrix is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
           if (i <= j)
             cout << B[((i - 1) * n - (i - 2) * (i - 1) / 2) + (j - i)] << " ";
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
    UpperTriangularMatrix lm (d);
    int x;
    cout << "Enter All Elements: " << endl;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        { 
            cin >> x;
            lm.Set (i, j, x);
        }
    }
    lm.Display ();
    return 0;
}