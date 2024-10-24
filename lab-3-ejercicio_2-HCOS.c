#include <stdio.h>
#include <time.h>

// Función para imprimir la serie
void imprimir(long long int serie) {
    printf("%lld ", serie);
}

// Función para calcular Fibonacci de manera iterativa
long long int fibonacci(int num) {
    if (num == 0) return 0; // Definición correcta
    if (num == 1) return 1;

    long long int a = 0, b = 1, c;
    for (int i = 2; i <= num; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b; // Retorna el último número de la serie
}

// Función para solicitar el rango al usuario
int numero() {   
    int n;
    printf("Elige un rango: ");
    scanf("%d", &n);

    // Verificar que el número sea positivo
    while (n < 0) {
        printf("Por favor, ingresa un número positivo: ");
        scanf("%d", &n);
    }
    return n;
}

int main() {   
    clock_t inicio, final;
    
    int rango = numero(); // Obtener rango del usuario

    inicio = clock(); // Iniciar el temporizador

    printf("\n__SERIE DE FIBONACCI__\n\n");
    for (int i = 0; i < rango; i++) {   
        imprimir(fibonacci(i)); // Imprimir la serie
    }
    
    final = clock(); // Finalizar el temporizador
    
    double time_taken = (double)(final - inicio) / CLOCKS_PER_SEC; // Calcular tiempo transcurrido

    // Mostrar tiempo de ejecución
    printf("\n\nTIEMPO DE EJECUCIÓN (seg): %f seg\n", time_taken);
    printf("TIEMPO DE EJECUCIÓN (ms): %f ms\n", time_taken * 1000);

    return 0;
}
