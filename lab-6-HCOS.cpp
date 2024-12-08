#include <iostream>
using namespace std;
#define m 30


int calculo(int *contenedor, int len)
{   
    
    int area=0,comp=0;
    int resta=0;
    
    for (int i=0; i<len; i++)
    {   
        for (int j=0; j<len-1; j++)
        {
            if (contenedor[i] <= contenedor[j+1])
            {
                comp=contenedor[i] * (j+1);
                if (comp>area)
                	{
                		area=comp;
                	}
            }
            
            else
            {   
                resta=contenedor[i]-contenedor[j+1];
                comp=(contenedor[i]-resta) * (j+1);
                if (comp>area)
                	{
                		area=comp;
                	}
            }
        }
    }
    return area;
}



int main ()
{   
    int altura, ancho;
    
    cout<<"Escribe el tamaño del contenedor: "<<endl;
    cin >> altura;
    ancho=altura;
    
    int **arreglo = new int*[altura];
    for (int i = 0; i < altura; i++) 
    {
        arreglo[i] = new int[ancho];
    }
    
    
    int contenedor[ancho];
    cout<<"Las alturas dadas aleatoriamente son: "<<endl<<"{ ";
    for (int i=0; i<ancho; i++)
    {
        contenedor[i]=rand()%altura;
        cout<<contenedor[i]<<" ";
    }
    cout<<"}"<<endl;

    cout<<endl;
    
    // (altura = 7 - contenedor = 5) = 2
    // 6
    // 0 1,2,3,4,5
    // - - 2 - - -
    // 0 1,2,3,4,5
    // - - - - 2 -
    int celda=0;
    
    for (int i=0;i<altura; i++)
    {   
       
        for (int j=0; j<ancho; j++)
        {   
            //columnas
            celda = altura - contenedor[j];
            if (i==celda)
            {
                arreglo[i][j] = 1;
            }
            
            else if ( (i!=0) && (arreglo[i-1][j]) != 0)
            {
                arreglo[i][j] = 1;
            }
            else 
            {
                arreglo[i][j]=0;
            }
        }
    }
    
    cout<<endl;
    
    if (altura < m)
    {
        for (int i=0;i<altura; i++)
    {  
        for (int j=0; j<ancho; j++)
        {  
            if ((arreglo[i][j])==1)
            {
                cout<<"\t"<<'o';
            }
            else
            {
                cout<<"\t"<<'-';
            }
        }
        cout<<endl;
    }
    }
    else
    {
        cout<<"Lo sentimos, el arreglo es muy grande para mostrar..."<<endl; 
    }
    
    
    
    cout<<endl;
    
    cout << "La cantidad máxima de agua que puede tener el contenedor es: " 
         << calculo(contenedor, ancho) << endl;
    
    delete[] arreglo;



    return 0;
}