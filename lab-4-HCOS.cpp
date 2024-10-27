#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <cmath>

using namespace std;

// Función para calcular la distancia entre dos puntos
float calcularDistancia(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int num; 
    
    cout << "Escribe cuántos pares ordenados quieres: ";
    cin >> num;
    cout << endl;

    // Crear un arreglo dinámico para almacenar los puntos
    float **arreglo = new float*[num];
    for (int i = 0; i < num; i++) {
        arreglo[i] = new float[2];
    }
    
    srand(time(NULL));
    
    // Llenar el arreglo con puntos aleatorios
    for (int i = 0; i < num; i++) {
        arreglo[i][0] = rand() % 100 / 10.0; // Genera un valor entre 0 y 10
        arreglo[i][1] = rand() % 100 / 10.0; // Genera un valor entre 0 y 10
    }
    
    cout << "PARES DE PUNTOS: " << endl;
    for (int i = 0; i < num; i++) {   
        cout << "[ " << arreglo[i][0] << ", " << arreglo[i][1] << " ]" << endl;
    }
    
    // Inicializar la distancia mínima con un valor grande
    float distanciaMinima = FLT_MAX; // FLT_MAX es el valor más grande para un float
    cout << endl << "DISTANCIAS ENTRE PUNTOS: " << endl;

    // Iniciar el cronómetro
    clock_t inicio = clock();

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) { // Comparar todos los puntos
            float distancia = calcularDistancia(arreglo[i][0], arreglo[i][1], arreglo[j][0], arreglo[j][1]);
            cout << "Distancia entre [" << arreglo[i][0] << ", " << arreglo[i][1] << "] y [" 
                 << arreglo[j][0] << ", " << arreglo[j][1] << "] es: " << distancia << endl;
            
            // Actualizar la distancia mínima si es necesario
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
            }
        }
    }
    
    // Parar el cronómetro
    clock_t final = clock();
    double time_taken = (double)(final - inicio) / CLOCKS_PER_SEC; // Calcular tiempo transcurrido

    cout << "La distancia menor es: " << distanciaMinima << endl;
    
    cout <<"\n\nTIEMPO DE EJECUCIÓN (seg): "<< time_taken <<"seg";
    cout <<"\nTIEMPO DE EJECUCIÓN (ms): "<<time_taken * 1000<<"ms";


    // Liberar memoria
    for (int i = 0; i < num; i++) {
        delete[] arreglo[i];
    }
    delete[] arreglo;

    return 0;
}
