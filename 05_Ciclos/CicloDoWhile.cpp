#include<iostream>

using namespace std;

//Realizar un programa que muestre los valores del 0 al 10

int main ()
{
    int contador=0;

    do
    {
        cout<<"Contador: " << contador << endl;
        contador = contador+2; //Incrementamos el contador en 2
    } while (contador <= 10);
    
return 0;
}