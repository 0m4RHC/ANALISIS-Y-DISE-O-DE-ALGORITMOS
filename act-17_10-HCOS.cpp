#include <iostream>
using namespace std;
#define m 10

int main ()
{   
    int total=0;
    int val=0;
    int arr_cam[m]={1,2,5,10,20,50,100,200,500,1000};
    int i=0;
    int recu=0;

    cout << "Elige el valor: " << endl;
    cin >> val; 
    cout <<"El cambió será de: "<< endl;
    do 
    {
        val = val - total;
        while (val >= arr_cam[i])
        {
            total=arr_cam[i];
            i++;
        }
        cout << total;  
        cout <<" ";
        i=0;

    } while (val != 1 && val != 0);
    

    return 0;
}