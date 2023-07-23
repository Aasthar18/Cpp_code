#include <iostream>
using namespace std;
class LowerTriangularMatrix
{
    private:
        int *B;
        int n;
    public:
        LowerTriangularMatrix ()
        {
            n = 3;
            B = new int[3 * (3 + 1) / 2];
        }
        LowerTriangularMatrix (int n)
        {
            this->n = n;
            B = new int[n * (n + 1) / 2];
        }
        ~LowerTriangularMatrix ()
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
void LowerTriangularMatrix::Set (int i, int j, int y)
{
    if (i >= j)
        B[i * (i - 1) / 2 + j - 1] = y;
}
int LowerTriangularMatrix::Get (int i, int j)
{
    if (i >= j)
        return B[i * (i - 1) / 2 + j - 1];
    return 0;
}
void LowerTriangularMatrix::Display ()
{
    cout << "\nMatrix is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
           if (i >= j)
             cout << B[i * (i - 1) / 2 + j - 1] << " ";
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
    LowerTriangularMatrix lm (d);
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