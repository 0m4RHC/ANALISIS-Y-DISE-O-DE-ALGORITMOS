#include <iostream>
using namespace std;

int factorial(int m)
{
    int i,s=1;
    for(i=1; i<a; i++)
    {
        s*=i;
    }
    return s;
}

int combinacion(int a, int b)
{
    return factorial(a)/faactorial(b)*factorial(a-b);
}

int main()
{      
    int i,j,k;

    cout <<"Escribe el número de filas: "<<endl;
    cin>>k;
    for(i=0; i<=k; i++)
    {
        for (j=0; j<=i; j++)
        {
            cout<<combinacion(i,j);
        }
        cout <<endl;
    }
    return 0; 
}