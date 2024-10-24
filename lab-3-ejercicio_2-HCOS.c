//Serie de Fibonacci
#include <stdio.h>
#include <time.h>


int imprimir(int serie)
{
    printf("%d", serie);
    
    return 0;
}

int fibonacci (int num)
{
    if (num == 0 || num==1)
    {
        return 1;
    }
    else
    {
        return fibonacci (num-1)+ fibonacci (num-2);
    }
    
}


int numero(int n)
{   
    printf("Elige un rango: ");
    scanf("%d", &n);
    
    return n;
}


int main ()
{   
    clock_t inicio, final;
    double segundos;
    
    int rango;

    int m = numero (rango);

    inicio = clock();

    printf("\n__SERIE DE FIBONACCI__\n\n");
    for (int i = 0; i < m; i++) 
    {   
        imprimir(fibonacci(i));
        printf(" "); // Para separar los números.
    }
    
    final = clock();
    
    double time_taken = (double)(final - inicio) / CLOCKS_PER_SEC;
    
    printf("\n\n");
    printf("TIEMPO DE EJECUCION (seg):\n\n%f seg\n", time_taken);
    printf("\n");
    printf("TIEMPO DE EJECUCION (ms):\n\n%f ms\n", time_taken * 1000);

    return 0;
}