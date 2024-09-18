#include <iostream>
using namespace std;

int main()
{
    int m = 15;
    int arr[m] = {0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5};

    // Imprime el arreglo original
    cout << "ARREGLO ORIGINAL:" << endl;
    for (int i = 0; i < m; i++) 
    {   
        cout << arr[i] << " ";
    }
    cout << endl;

    // Elimina duplicados
    int n_tam = 0;
    
    for (int i = 0; i < m; i++)
    {
        bool band = false;
        
        for (int j = 0; j < n_tam; j++)
        {
            if (arr[i] == arr[j])
            {
                band = true;
                break;
            }
        }
        if (!band)
        {
            arr[n_tam++] = arr[i];
        }
    }

    // Imprime el arreglo nuevo
    cout << "ARREGLO NUEVO:" << endl;
    for (int i = 0; i < n_tam; i++) 
    {   
        cout << arr[i] << " ";
    }
    cout << endl;

    // Muestra la cantidad de números únicos
    cout << "Los números sin repetir son: " << n_tam << endl;

    return 0;
}