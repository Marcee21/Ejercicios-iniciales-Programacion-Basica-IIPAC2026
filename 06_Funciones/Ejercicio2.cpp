#include <iostream>

using namespace std;

/* DEFINICIÓN DE LA FUNCIÓN
Recibe dos enteros (base y altura) y devuelve un entero.*/

int calcularAreaRectangulo(int base, int altura) {
    // Multiplica directamente los dos parámetros y devuelve el resultado al main
    return base * altura; 
}

int main() {
    // 1. Creamos las variables locales para la base, la altura y el area
    int base, altura, area;

    // 2. Solicitamos los datos al usuario en la consola
    cout << "Ingrese la base: ";
    cin >> base;

    cout << "Ingrese la altura: ";
    cin >> altura;

    // 3. LLAMADA A LA FUNCIÓN:
    area = calcularAreaRectangulo(base, altura);

    // 4. Mostramos el resultado final guardado en la variable
    cout << "El area es: " << area << endl;

    return 0;
}