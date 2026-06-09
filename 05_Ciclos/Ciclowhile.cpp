#include <iostream>

using namespace std;

//Realizar un programa que muestre los numeros del 0 al 10 utilizando el ciclo while

int main()
{

int contador = 0;

while (contador <= 10)
{
cout << "Contador: " << contador << endl;
contador=contador + 1;//Inrementamos el contador en 1
}
return 0;
}