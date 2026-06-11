#include <iostream>
using namespace std;

// Declaración de la función
void sumar(int a, int b) {
	cout << "La suma de " << a << " y " << b << " es: " << a + b << "\n";
}

int main(int argc, char *argv[]) {

		int num1 = 5;
		int num2 = 7;
		
		// Llamada a la función con argumentos
		sumar(num1, num2);
		return 0;

}