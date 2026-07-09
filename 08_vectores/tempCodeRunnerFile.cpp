#include <iostream>  // Única librería necesaria para entrada, salida y limpieza del teclado
using namespace std;

int main()
{
    // ============================================================================
    // DECLARACIÓN DE VARIABLES Y ARREGLOS ESTÁTICOS ORIGINALES
    // ============================================================================
    int par = 0, impar = 0; 
    int inicio = 0, limite = 0;
    int datos[99];   // Ajustado estrictamente a 99 espacios máximos permitidos
    int pares[99];   
    int impares[99]; 
    int totalCorrelativos = 0;

    // ============================================================================
    // ENTRADA Y VALIDACIÓN DEL VALOR INICIAL (BLOQUEA LETRAS Y ESPACIOS)
    // ============================================================================
    cout << "Ingrese el valor inicial: ";
    cin >> inicio;

    // Si el usuario ingresa una letra o deja espacios incorrectos, cin.fail() lo detecta de inmediato
    while (cin.fail())
    {
        cout << "Error: Ingreso invalido. No se permiten letras ni espacios.\n";
        cout << "Ingrese el valor inicial: ";
        cin.clear();           // Borra el estado de error del teclado
        cin.ignore(100, '\n'); // Descarta cualquier letra o espacio que haya quedado en la memoria
        cin >> inicio;
    }
    cin.ignore(100, '\n');     // Limpia el Enter para que no afecte la siguiente lectura

    // ============================================================================
    // ENTRADA Y VALIDACIÓN DEL VALOR FINAL (MÁXIMO 99 NÚMEROS, BLOQUEA ERRORES)
    // ============================================================================
    do
    {
        cout << "Ingrese el valor final: ";
        cin >> limite;

        // Validación idéntica para el valor límite: bloquea letras y espacios usando solo iostream
        while (cin.fail())
        {
            cout << "Error: Ingreso invalido. No se permiten letras ni espacios.\n";
            cout << "Ingrese el valor final: ";
            cin.clear();           
            cin.ignore(100, '\n'); 
            cin >> limite;
        }
        cin.ignore(100, '\n');     

        // CONTROL DE SENTIDO: Evaluamos el orden para calcular el total de espacios ocupados
        if (inicio <= limite)
        {
            totalCorrelativos = (limite - inicio) + 1; // Calculo de forma Ascendente
        }
        else
        {
            totalCorrelativos = (inicio - limite) + 1; // Calculo de forma Descendente
        }
        
        cout << "Cantidad de correlativos entre " << inicio << " y " << limite << ": " << totalCorrelativos << endl;

        // VALIDACIÓN DE ESPACIOS: Verifica que no se superen los 99 espacios del vector
        if (totalCorrelativos > 99)
        {
            cout << "Error: La diferencia entre los valores ingresados no puede ser mayor a 99 espacios." << endl;
        }

    } while (totalCorrelativos > 99); // Se repite si el rango exige mas de 99 posiciones

    // ============================================================================
    // CICLO DE PROCESAMIENTO (MANTIENE LA ESTRUCTURA ORIGINAL)
    // ============================================================================
    cout << "Correlativos entre " << inicio << " y " << limite << ":" << endl;
    
    int posicionVector = 0; // Controla la posicion indice dentro de los vectores (0, 1, 2...)

    // Validacion de flujos: determina si el bucle incrementa o decrementa
    if (inicio <= limite)
    {
        // CASO ASCENDENTE: El bucle avanza de uno en uno (i++)
        for (int i = inicio; i <= limite; i++)
        {
            datos[posicionVector] = i; 
            cout << datos[posicionVector] << " ";

            // Ajuste logico manual para operar el residuo de numeros negativos correctamente sin cmath
            int numeroEvaluar = datos[posicionVector];
            if (numeroEvaluar < 0) {
                numeroEvaluar = -numeroEvaluar; // Lo convierte a positivo temporalmente para el % 2
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
            posicionVector++; // Cambia a la siguiente casilla del vector
        }
    }
    else
    {
        // CASO DESCENDENTE: El bucle retrocede de uno en uno (i--)
        for (int i = inicio; i >= limite; i--)
        {
            datos[posicionVector] = i; 
            cout << datos[posicionVector] << " ";

            // Mismo ajuste logico manual para el residuo con negativos descendentes
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
            posicionVector++; // Cambia a la siguiente casilla del vector
        }
    }

    cout << endl;
    cout << "----------------------------------------" << endl;

    // ============================================================================
    // IMPRESIÓN DE RESULTADOS FINALES
    // ============================================================================
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