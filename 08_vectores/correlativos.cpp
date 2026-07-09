/* Crear un porgrama en el cual luego de ingresar 2 valores (inicial y final)
debe mostrar los correlativos existentes para posteriormente
mostrar los valores pares y los pavlores impares que existen entre los valores ingresados.*/

/* Crear un porgrama en el cual luego de ingresar 2 valores (inicial y final)
debe mostrar los correlativos existentes para posteriormente
mostrar los valores pares y los pavlores impares que existen entre los valores ingresados.*/

#include <iostream>  
using namespace std;

int main()
{
    int par = 0, impar = 0; 
    int inicio = 0, limite = 0;
    int datos[100];   
    int pares[100];   
    int impares[100]; 
    int totalCorrelativos = 0;

    cout << "Ingrese el valor inicial: ";
    cin >> inicio;

    /*Agregamos esta validación para evitar que el programa se caiga o 
    procese basura si el usuario ingresa una letra por error.*/

    while (cin.fail())
    {
        cout << "Error: Ingreso invalido. No se permiten letras.\n";
        cout << "Ingrese el valor inicial: ";
        cin.clear();           // Restablece el canal de lectura para salir del estado de error.
        cin.ignore(100, '\n'); // Limpia la memoria del buffer eliminando la letra incorrecta que causó el fallo
        cin >> inicio;
    }
    cin.ignore(100, '\n');     

    do
    {
        cout << "Ingrese el valor final: ";
        cin >> limite;

        /*Agregamos el mismo control en el valor final por la misma razón: 
        asegurar que el programa solo reciba números enteros válidos*/

        while (cin.fail())
        {
            cout << "Error: Ingreso invalido. No se permiten letras.\n";
            cout << "Ingrese el valor final: ";
            cin.clear();           // Restablece el canal de lectura.
            cin.ignore(100, '\n'); // Borra los caracteres incorrectos del teclado.
            cin >> limite;
        }
        cin.ignore(100, '\n');     

        // Agregamos esta estructura if/else porque los números pueden venir en cualquier orden. 
        /*Si es ascendente restamos limite menos inicio, pero si es descendente 
        restamos inicio menos limite para que la distancia siempre dé positiva*/  
        
        if (inicio <= limite)
        {
            totalCorrelativos = (limite - inicio) + 1; 
            
        }
        else
        {
            totalCorrelativos = (inicio - limite) + 1; 
        }
        
        cout << "Cantidad de correlativos entre " << inicio << " y " << limite << ": " << totalCorrelativos << endl;

        /*Agregamos esta restricción de 99 para cumplir con la regla de no 
        llenar por completo el vector de tamaño 100, dejando siempre un margen seguro*/

        if (totalCorrelativos > 99)
        {
            cout << "Error: La diferencia entre los valores ingresados no puede ser mayor a 99 numeros." << endl;
        }

    } while (totalCorrelativos > 99); 

    cout << "Correlativos entre " << inicio << " y " << limite << ":" << endl;
    
    int posicionVector = 0; 

    //Separamos el procesamiento en dos bloques lógicos independientes.
    /*Si el rango es hacia arriba usamos un for que incrementa (i++), 
    y si es hacia abajo usamos un for que decrementa (i--), 
    permitiendo que el programa funcione en ambos sentidos*/
    
    if (inicio <= limite)
    {
        for (int i = inicio; i <= limite; i++)
        {
            datos[posicionVector] = i; 
            cout << datos[posicionVector] << " ";

            int numeroEvaluar = datos[posicionVector];
            if (numeroEvaluar < 0) {
                numeroEvaluar = -numeroEvaluar; 
            }

            if (numeroEvaluar % 2 == 0)
            {
                pares[par] = datos[posicionVector]; 
                par++;                              
            }
            else
            {
                impares[impar] = datos[posicionVector]; 
                impar++;                                   
            }
            posicionVector++; 
        }
    }
    else
    {
        for (int i = inicio; i >= limite; i--)
        {
            datos[posicionVector] = i; 
            cout << datos[posicionVector] << " ";

            int numeroEvaluar = datos[posicionVector];
            if (numeroEvaluar < 0) {
                numeroEvaluar = -numeroEvaluar; 
            }

            if (numeroEvaluar % 2 == 0)
            {
                pares[par] = datos[posicionVector]; 
                par++;                              
            }
            else
            {
                impares[impar] = datos[posicionVector]; 
                impar++;                                
            }
            posicionVector++; 
        }
    }

    cout << endl;
    cout << "----------------------------------------" << endl;

    cout << "\nValores pares " << ":" << endl;
    for (int i = 0; i < par; i++)
    {
        cout << pares[i] << " "; 
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "\nValores impares " << ":" << endl;
    for (int i = 0; i < impar; i++)
    {
        cout << impares[i] << " "; 
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    
    return 0; 
}