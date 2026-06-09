#include <iostream>
using namespace std;

int main() {
    int num1, num2, suma;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    suma = num1 + num2;
    cout << "La suma de " << num1 << " + " << num2 << " = " << suma << endl;  

    return 0;
}




/* Operadores en c++ Lógicos:
- && (AND lógico): Devuelve verdadero si ambos operandos son verdaderos.        
- || (OR lógico): Devuelve verdadero si al menos uno de los operandos es verdadero.
- ! (NOT lógico): Devuelve verdadero si el operando es falso, y viceversa.
- == (Igualdad): Devuelve verdadero si ambos operandos son iguales.
- != (Desigualdad): Devuelve verdadero si ambos operandos son diferentes.
= (Asignación): Asigna el valor del operando derecho al operando izquierdo.
== (Comparación de igualdad): Compara dos operandos y devuelve verdadero si son iguales.
=== (Comparación estricta de igualdad): Compara dos operandos y devuelve verdadero si 
son iguales y del mismo tipo (no es un operador en C++, pero se menciona para aclarar la diferencia con ==).  

Operadores aritméticos:
- + (Suma): Suma dos operandos.        
- - (Resta): Resta el segundo operando del primero.
- * (Multiplicación): Multiplica dos operandos.
- / (División): Divide el primer operando por el segundo. Si ambos operandos son enteros, 
se realiza una división entera (el resultado es un entero). Si al menos uno de los operandos es un número de punto flotante, se realiza una división de punto flotante.
- % (Módulo): Devuelve el resto de la división entre dos operandos enteros. Solo se puede usar con operandos enteros.  

 

Operadores relacionales:
- < (Menor que): Devuelve verdadero si el operando izquierdo es menor que el
operando derecho.
- > (Mayor que): Devuelve verdadero si el operando izquierdo es mayor que el
operando derecho.
- <= (Menor o igual que): Devuelve verdadero si el operando izquierdo es menor o igual que el operando derecho.
- >= (Mayor o igual que): Devuelve verdadero si el operando izquierdo es mayor o igual que el operando derecho.


*/
