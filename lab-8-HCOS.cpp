#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int limite = 0, k = 0, threshold = 0;

    cout << "_____SUBARREGLOS_____" << endl << endl;
    cout << "Escribe el número de subarreglos: ";
    cin >> k;
    cout << "Escribe el promedio que deseas buscar: ";
    cin >> threshold;

    int op;
    cout << endl << "_____ARREGLO_____" << endl << endl
         << "1. Elige un arreglo al azar" << endl
         << "2. Escribe un arreglo" << endl;
    cin >> op;

    int *arr;
    if (op == 1) {
        cout << "Elige el límite del arreglo: ";
        cin >> limite;
        arr = new int[limite];
        srand(time(NULL));
        for (int i = 0; i < limite; i++) {
            arr[i] = rand() % 10;
            cout << arr[i] << "\t";
        }
        cout << endl;
    } else {
        string cad;
        cout << "Ingresa una cadena de números: ";
        cin >> cad;
        limite = cad.length();
        arr = new int[limite];
        for (int i = 0; i < limite; i++) {
            arr[i] = cad[i] - '0'; // Convertir caracteres a enteros
        }
    }

    // Ventana deslizante para calcular el promedio
    int suma = 0, contador = 0;

    // Calcular la suma inicial para el primer subarreglo de tamaño k
    for (int i = 0; i < k && i < limite; i++) {
        suma += arr[i];
    }

    if (suma >= k * threshold) {
        contador++;
    }

    // Ajustar la ventana para los siguientes subarreglos
    for (int i = k; i < limite; i++) {
        suma += arr[i];       // Agregar el nuevo elemento
        suma -= arr[i - k];   // Eliminar el elemento que sale de la ventana

        if (suma >= k * threshold) {
            contador++;
        }
    }

    // Mostrar resultado
    if (contador > 0) {
        cout << "Los subarreglos encontrados son: " << contador << endl;
    } else {
        cout << "No se encontró ningún subarreglo..." << endl;
    }

    delete[] arr;
    return 0;
}
