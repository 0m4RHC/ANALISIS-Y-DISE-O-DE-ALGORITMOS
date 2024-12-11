#include <iostream>
#include <cstring>
using namespace std;



int main ()
{  
    int limite=0;
    
    int k=0, threshold=0;
    int ale;
    cout<<"_____SUBARREGLOS_____"<<endl<<endl;
    cout<<"Escribe el número de subarreglos: "<<endl;
    cin>> k; 
    cout<<"Escribe el promedio que deseas buscar: "<<endl;
    cin>>threshold;
    
    int i=0;
   
    int *arr = new int[limite];
    int op;
    
    cout<<endl;
    
    cout<<"_____ARREGLO_____"<<endl<<endl<<"1.Elige un arreglo al azar"<<endl<<"2.Escribe un arreglo"<<endl;
 
    cin>>op;
    switch(op)
    {
        case 1: 
            
            cout<<"Elige el límite del arreglo: "<<endl;
            cin>>limite;
            
            srand(time(NULL));
             for (i=0; i<limite; i++)
                {
                    ale = rand()%10;
                    arr[i]=ale;
                    cout<<arr[i]<<"\t"<<endl;
                }
        break;
        
        case 2: 
            string cad;
            cout << "Ingresa una cadena de números " << endl;
            cin >> cad;
        
            for (i = 0; i < cad.length(); i++) 
            {
                arr[i] = cad[i] - '0'; // Convierte el carácter a su valor entero
            }
            limite=cad.length();
        break;
        
    }

    int suma=0;
    int promedio=0;
    int contador=0;
    int cont_sec=1;
    int cont_ter=1;
    i=0;
    
    while (i<limite)
    { 
        suma += arr[i];

        if (i!=0 && (cont_sec % k)==0)
        {
            promedio=(suma/k);

            if(promedio>=threshold)
            {
                contador++;
            }
            
            suma=0;
            cont_ter++;
            i=cont_ter-1;
        }
        
        i++;
        cont_sec++;
    }   
    
    if (contador!=0)
    {
        cout<<"Los subarreglos encontrados son: "<<endl;
        cout<<contador;
    }
    else
    {
        cout<<"No se encontró ningún subarreglo..."<<endl;
    }
    
    
    delete[] arr;

    return 0;    
}