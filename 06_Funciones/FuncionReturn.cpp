#include <iostream>
using namespace std;


// Función que devuelve la suma de dos números enteros
int sumar(int a, int b) {
	return a + b; // Devuelve la suma de a y b
}


int main(int argc, char *argv[]) {
	
	
	int num1 = 5;
	int num2 = 7;
	
	// Llamada a la función con valor de retorno
	int resultado = sumar(num1, num2);
	
	cout << "El resultado de sumar " << num1 << " y " << num2 << " es: " << resultado << "\n";
	
	
	
	
	return 0;
}
