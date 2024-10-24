#include <iostream>
#include <cstdlib>
#include <ctime> 
#define m 7
using namespace std;

void mediana(int m_arr[], int lon)
{   
    int centro=(lon/2);
    int num=0;
    float n_de=0.0;
    //si es impar
    if (((lon) % 2) != 0)
    {   
        num=m_arr[centro];
        cout<<"____MEDIDA IMPAR____"<<endl;
        cout<<endl;
        cout <<"La mediana es: "<<num;
    }
    //si es par
    else
    {
        n_de=((m_arr[centro-1]+m_arr[centro])/2.0);
        cout<<"____MEDIDA PAR____"<<endl;
        cout<<endl;
        cout <<"La mediana es: "<<n_de;
    }
    
}


int* fusion_arr(int arr_a[], int arr_b[], int tam_1, int tam_2 )
{
    int sum=tam_1+tam_2;
    int *ar_fus = new int[sum];
    int i=0, j=0,cont=0;
    
    while (i<tam_1)
    {   
        while (j < tam_2)
        {
            ar_fus[j]=arr_b[j];
            
            cont++;
            j++;
        }
        
        ar_fus[cont]=arr_a[i];
        cont++;
        i++;
    }
    
   return ar_fus;
   delete[] ar_fus;
}


void ordenar(int arreglo_0[], int tam)
{
    int p, aux;
    for (int i = 0; i < tam; i++)
    {
        p = i;
        aux = arreglo_0[i];
        while (p > 0 && (arreglo_0[p - 1] > aux))
        {
            arreglo_0[p] = arreglo_0[p - 1];
            p--;
        }
        arreglo_0[p] = aux; 
    }
    for (int i = 0; i < tam; i++) 
    {
        cout << arreglo_0[i] << " ";
    }
    cout << endl; 
}




int main()
{   
    unsigned t0, t1;
    //EMPIEZA A CONTAR TIEMPO DE EJECCIÓN
    t0=clock();
    
    srand((unsigned)time(NULL));
    int len_1 = rand() % m + 1; 
    int len_2 = rand() % m + 1; 

    // Array dinámico
    int *arr_1 = new int[len_1];
    int *arr_2 = new int[len_2];

    cout << "____ARREGLO N°1 [" << len_1 << "]____" << endl;
    int a;
    bool repetido;
    
    for (int i = 0; i < len_1; i++)
    {
        
        do
        {
            repetido = false;
            a = rand() % m+1;
            
            for (int j = 0; j < i; j++)
            {
                if (arr_1[j] == a)
                {
                    repetido = true;
                    break; 
                }
            }
        } while (repetido);

        arr_1[i] = a;
    }

    ordenar(arr_1, len_1);
    cout<<endl;
    cout << "____ARREGLO N°2 [" << len_2 << "]____" << endl;
    for (int i = 0; i < len_2; i++)
    {
        int a;
        bool repetido;
        do
        {
            repetido = false;
            a = rand() % m+1;
            
            for (int j = 0; j < i; j++)
            {
                if (arr_2[j] == a)
                {
                    repetido = true;
                    break; 
                }
            }
        } while (repetido);
    
    arr_2[i] = a;
    }
    
    ordenar(arr_2, len_2);
    
    int tam_t=len_1+len_2;
    
    int * n_arr = fusion_arr(arr_1,arr_2,len_1,len_2);
    
    cout<<endl;
    cout<<"____ARREGLO VINCULADO ["<<tam_t<<"]____"<< endl; 
    cout<<endl;
    for (int i=0; i<tam_t;i++)
    {
       cout<< n_arr[i]<< " "; 
    }
    cout<<endl<<endl;
    cout<<"____ARREGLO ORDENADO____"<<endl;
    cout<<endl;
    ordenar(n_arr,tam_t);
    cout<<endl;
    
    mediana(n_arr,tam_t);

    delete[] arr_1;
    delete[] arr_2;
    
    //TERMINA TIEMPO EJECUCCIÓN
    t1 = clock();
    double segundos = (double(t1 - t0) / CLOCKS_PER_SEC);
    double milisegundos = segundos * 1000; // Conversión a ms
    cout << endl << endl;
    cout <<"____TIEMPO DE EJECUCCIÓN____ " << endl << endl << milisegundos << " ms" << endl;

    return 0;
}
