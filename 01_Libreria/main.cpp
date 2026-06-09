#include <iostream>//Libreria para entrada y salida de datos
#include <math.h>//Libreria para funciones matematicas
#include <stdio.h>//Libreria para funciones de entrada y salida estándar
#include <stdlib.h>//Libreria para funciones de utilidad general
#include <string>//Libreria para manipulación de cadenas de texto
#include <conio.h>//Libreria para funciones de consola, como getch() y kbhit()


using namespace std;

string nombreestudiante;//Variable para almacenar el nombre del estudiante
string apellidoestudiante;

int main() {
    system("cls");
    
cout<<"Ingrese su nombre: ";//salida de valores
cin>>nombreestudiante;//entrada de valores
cout<<"Hola "<<nombreestudiante<<"!"<<endl;//salida de valores

printf ("Esta es la clase de programacion basica"); //Salida de valores con formato
//scanf (" ", & apellidoestudiante); //Entrada de valores con formato

cout<<" "<<endl;//salida de texto 
rand();//Genera un numero aleatorio

system("pause");//Pausa el programa para que el usuario pueda ver los resultados antes de que se cierre la ventana

    return 0;
}
