#include <iostream>
#include <string.h>
using namespace std;

string conteo (string &cadena) 
{
    char actual=cadena[0];
    int cont=1;
    string newcad="";
    
    for (int i=1; i<cadena.length(); i++)
    {
        if (cadena[i] == actual && cont < 9)
        {
            cont++;
        }
        else
        {
            newcad+=actual+ to_string(cont);
            actual=cadena[i];
            cont=1;
        }
    }

    newcad+=actual+ to_string(cont);

    if (newcad.empty() || newcad.length()>=cadena.length())
    {
        return cadena;
    }
    
    return newcad;

}

int main ()
{   
    string cadena;
    cout<<"Introduzca las letras: "<<endl;
    cin>>cadena;
    string solucion = conteo(cadena);
    cout<< solucion <<endl;
    return 0;
}