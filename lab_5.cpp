#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
#define m 3
#define n 3

int main ()
{   
    int arr_a[m][n]={ {1,2,4}, {3,4,5}, {0,1,6} };
    
    //El nuevo arreglo
    int cont=0;
    int k=0;
    
    cout << "LISTA VINCULADA: " ;
    cout << endl; ;
     for(int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {   
           cout << arr_a[i][j];
           cout <<" ";
           cont++;
        }
    cout << endl;
    }
    
    int *arr_b= new int [cont];
    
     for(int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            arr_b[k] = arr_a[i][j];
            k++;
        }
    }
    
    //ORDENAR
    
    int pos, aux;
    
    for (int i; i<cont; i++)
    {
     pos = i;
     aux= arr_b[i];
     
     while (pos >0 && (arr_b[pos-1] > aux ) )
     {
        arr_b[pos]=arr_b[pos-1];
        pos--; 
     }
        
    }
    
    
    //IMPRIMIR
    cout<<endl;
    cout <<"LISTA FUSIONADA: ";
    cout<<endl;
    for(int i=0; i<k; i++)
    {
        cout <<arr_b[i];
        cout <<" ";
      
    }
    
    
     delete[] arr_b;
    return 0;
}
