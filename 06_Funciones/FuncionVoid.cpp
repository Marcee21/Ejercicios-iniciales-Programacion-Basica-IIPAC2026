#include <iostream>
using namespace std;

// Función que imprime los números del 1 al 5
void imprimirNumeros() {
	for (int i = 1; i <= 5; ++i) {
		cout << i << " ";
	}
	cout << "\n";
}


int main(int argc, char *argv[]) {
	
	
	// Llamada a la función sin valor de retorno
	cout << "Imprimiendo numeros del 1 al 5:\n";
	imprimirNumeros();
	
	
	return 0;
}
