#include <iostream>
#include<windows.h>
#include <iomanip>



using namespace std;


int factorial(int n)
{
    int factorial = 1;

    for (int i = 1; i <= n; ++i)
        factorial *= i;

    return factorial;
}
void Stirling(int** F, int n)
{
    for (int j = 0; j < n; j++)
    {
        F[j][0] = 1;
        F[j][j] = 1;
    }

    for (int j = 2; j < n; j++)
        for (int k = 1; k < j; k++)
        {
            F[j][k] = F[j - 1][k - 1] + (k + 1) * F[j - 1][k];
        }
    for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
            if (F[j][k] < 0)
                F[j][k] = 0;
}
void Bell(int** F, int* B, int n)
{
    for (int j = 0; j < n; j++)
        B[j] = 0;

    for (int j = 0; j < n; j++)
        for (int k = 0; k < j; k++)
        {
            B[j] = B[j] + F[j][k];
        }
}
void PrintS(int** F, int n)
{
    cout << "Числа Стірлінга другого роду:" << endl;
    cout << "  ";
    for (int i = 0; i < n; i++)
        cout << setw(9) << i + 1;
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << setw(2) << i + 1;
        for (int j = 0; j < n; j++)
        {
            if (F[i][j] == 0)
                cout << setw(9);
            else 
                cout << setw(9) << F[i][j];       
        }
        cout <<endl;      
    }
    cout << endl;

}
void PrintB(int* B, int n)
{
    cout << "Числа Белла" << endl;
    for (int j = 0; j < n; ++j) 
       cout << setw(2)<< j+1 << "|" << setw(9) << B[j]<<endl;
       
    

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Завдання 1: " << endl;
    int n = 10;
    int r = 9;

    int P1 = factorial(n);
    int P2 = factorial(n - r);
    int A = P1 / P2;
    cout << "n = " << n << endl;
    cout << "r = " << r << endl;
    cout << "A = " << A << endl << endl;
   
    cout << "Завдання 2: " << endl;

    n = 11;

    int** F = new int* [n];
    for (int j = 0; j < n; j++)
        F[j] = new int[n];

    int* B = new int[n];
    
    
    Stirling(F, n);
    PrintS(F, n);
    Bell(F, B, n);
    PrintB(B, n);
   
    

    return 0;
}
