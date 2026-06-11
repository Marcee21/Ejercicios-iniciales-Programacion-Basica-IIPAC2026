#include <iostream>

using namespace std;
/* DEFINICIÓN DE LA FUNCIÓN
Recibe un entero (int) y devuelve un valor booleano (true/false).*/
bool esPar(int numero)
{
    // El operador '%' es el MOD. Divide el numero entre 2 y calcula el residuo.
    if (numero % 2 == 0)
    {
        return true; // Si el residuo es 0, el numero es par. Devuelve verdadero.
    }
    else
    {
        return false; // Retorna falso si no es cero
    }
}

int main()
{
    int numero;

    cout << "Ingrese un numero entero: ";
    cin >> numero;

    // LLAMADA A LA FUNCIÓN:
    if (esPar(numero))
    {
        // Le mandamos el numero a 'esPar'. Si nos devuelve 'true', entra al IF.
        cout << "El numero es par" << endl;
    }
    else
    {
        cout << "El numero es impar" << endl; // Se ejecuta si es falso
    }

    return 0;
}