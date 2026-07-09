/*  crear un programa  en el cual lleve los datos y calificaciones
de N cantidad de estudiantes*(3 en adelante) 
se debe solicitar para cada estudiante Nombre, Apellido, numeroCuenta,
sexo(M/F), 
y la nota de cada parcial (en base a 100) 0.25 para Ier Parcial
0.35 para 2do Parcial y 0.40 para el 3er Parcial,
ademas de calcular el promedio final y mostrarlo en pantalla,

y una ponderacion de la nota final en base a la siguiente escala:
90-100 Excelente
80-89 Muy Bueno
70-79 Bueno              
60-65 Regular
64 - 0  Maleta  

se debe guardar los datos en un archivo de texto 
y mostrarlo en pantalla, 
\ademas de mostrar el promedio general de todos los estudiantes
 y la cantidad de estudiantes que se ingresaron.

 mostrar tambien cuantos y quienes aprobaron y reprobaron, asi como el porcentaje de aprobados y reprobados.
 
*/

#include <iostream>  
#include <vector>    
#include <string>    
#include <fstream>   // Para crear y escribir en el archivo de texto externo
#include <iomanip>   // Librería para usar fixed, setprecision y setw (alineación de columnas)

using namespace std;

// FUNCION PARA MOSTRAR LA NOTA FINAL Y SU ESCALA 

string obtenerPonderacion(double nota) {
    if (nota >= 90 && nota <= 100) return "Excelente";
    if (nota >= 80) return "Muy Bueno";
    if (nota >= 70) return "Bueno";
    if (nota >= 65) return "Regular";
    return "Maleta"; // Si es menor a 65
}
//ARREGLO: FUNCION PARA VALIDAR LAS NOTAS DE LOS PARCIALES MEJORAMOS LA VALIDACION PARA QUE NO ACEPTE LETRAS
double ValidarNotas (string Nparcial){
    double nota = 0.0;

    do {
        cout << "Nota " << Nparcial << " (0-100): ";
        cin >> nota;

        //  ARREGLO: Si no es un número, mostramos un mensaje de error y limpiamos el flujo de entrada
        if (cin.fail()) {
            cout << "Error: No se permiten letras. Ingrese un numero valido.\n";
            
            cin.clear(); // Reestablece el estado de cin (quita el bloqueo)
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia la letra de la memoria
            
            // Asignamos un valor fuera de rango para asegurar que el 'while' repita el ciclo
            nota = -1; 
        } 
        // Si es un número, revisamos que esté en el rango correcto
        else if (nota < 0 || nota > 100) {
            cout << "Error: La nota debe estar estrictamente entre 0 y 100.\n";
        }

    } while (nota < 0 || nota > 100); // Se repite si es menor a 0 (incluyendo el -1 del error) o mayor a 100
    
    return nota;
}

//ARREGLO: FUNCION PARA MOSTRAR LOS DATOS QUE SE VA INGRESANDO POR ESTUDIANTE  
void mostrarDatosEstudiante(vector<string>& nombres, vector<string>& apellidos, vector<string>& numerosCuenta, double
    notafinal, string ponderacion, string estado, int i) {
    cout << "\n=========================================\n";
    cout << "      DATOS REGISTRADOS CON EXITO        \n";
    cout << "=========================================\n";
    cout << "   ESTADISTICAS DEL ESTUDIANTE INGRESADO\n";
    cout << "=========================================\n";
    cout << "Estudiante Nro:    " << i + 1 << "\n";
    cout << "Nombre:            " << nombres[i] << "\n";
    cout << "Apellido:          " << apellidos[i] << "\n";
    cout << "Nro. de Cuenta:    " << numerosCuenta[i] << "\n";
    cout << "Nota Final:        " << fixed << setprecision(2) << notafinal << "%\n";
    cout << "Ponderacion:       " << ponderacion << "\n";
    cout << "Estado:            " << estado << "\n";
    cout << "=========================================\n\n";
}

int main() { 

    // Creacion de los vectores dinamicos y lo inicializamos al tener n cantidad
    // ingresada por el usuario
    vector<string> nombres;
    vector<string> apellidos;
    vector<string> numerosCuenta;
    vector<char> sexo;
    vector<double> parcial1;
    vector<double> parcial2;
    vector<double> parcial3;
    vector<double> notasFinales;
    vector<string> ponderaciones;
    vector<string> estados;
    
    double sumaPromedios = 0;
    int aprobados = 0;
    int reprobados = 0;

    //ARREGLO:
    int contadorEstudiantes = 0;
    char continuar = 'S';

    //  Lectura de datos del estudiante
    // Ciclo principal adaptado
    do {
        cout << "\n--- REGISTRO DE CALIFICACIONES ---\n";
        cout << "\n----------------------------------\n";
        cout << "\n----- Datos del Estudiante " << contadorEstudiantes + 1 << " -----\n";
        //Banderas de validación para cada campo
        bool NombreValido = false;
        bool ApellidoValido = false;
        bool NumeroCuentaValido = false;

        // Variables temporales para leer los datos antes de meterlos al vector
        string nombreTemporal, apellidoTemporal, cuentaTemporal;
        char sexoTemporal;
        double parcial1Temporal, parcial2Temporal, parcial3Temporal;

        // ==========================================
        // VALIDACIÓN NOMBRE
        // ==========================================
        while (!NombreValido) {
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, nombreTemporal); 
            if (nombreTemporal.empty()) {
                cout << "Error: El nombre no puede estar vacio.\n";
            } else {
                NombreValido = true; 
                for (int i = 0; i < nombreTemporal.length(); i++) {
                    if (!isalpha(nombreTemporal[i]) && nombreTemporal[i] != ' ') NombreValido = false; 
                }
                if (!NombreValido) cout << "Error: Solo letras y espacios.\n";
            }
        }
        nombres.push_back(nombreTemporal); // Guardamos en el vector definitivo

        // ==========================================
        // VALIDACIÓN APELLIDO
        // ==========================================
        while (!ApellidoValido) {
            cout << "Ingrese el apellido del estudiante: ";
            getline(cin, apellidoTemporal); 
            if (apellidoTemporal.empty()) {
                cout << "Error: El apellido no puede estar vacio.\n";
            } else {
                ApellidoValido = true; 
                for (int i = 0; i < apellidoTemporal.length(); i++) {
                    if (!isalpha(apellidoTemporal[i]) && apellidoTemporal[i] != ' ') ApellidoValido = false; 
                }
                if (!ApellidoValido) cout << "Error: Solo letras y espacios.\n";
            }
        }
        apellidos.push_back(apellidoTemporal);

        // ==========================================
        // VALIDACIÓN CUENTA
        // ==========================================
        while (!NumeroCuentaValido) {
            cout << "Ingrese el numero de Cuenta del estudiante: ";
            getline(cin, cuentaTemporal); 
            if (cuentaTemporal.empty()) {
                cout << "Error: El numero de cuenta no puede estar vacio.\n";
            } else {
                NumeroCuentaValido = true; 
                for (int i = 0; i < cuentaTemporal.length(); i++) {
                    if (!isdigit(cuentaTemporal[i])) NumeroCuentaValido = false; 
                }
                if (!NumeroCuentaValido) cout << "Error: Solo numeros.\n";
            }
        }
        numerosCuenta.push_back(cuentaTemporal);

        // ==========================================
        // VALIDACIÓN SEXO
        // ==========================================
        do {
            cout << "Sexo (M/F): ";
            cin >> sexoTemporal;
            sexoTemporal = toupper(sexoTemporal); 
            if (sexoTemporal != 'M' && sexoTemporal != 'F') {
                cout << "ERROR: Solo se permiten 'M' o 'F'.\n";
            }
        } while (sexoTemporal != 'M' && sexoTemporal != 'F'); 
        sexo.push_back(sexoTemporal);

        // ==========================================
        // VALIDACIÓN NOTAS
        // ==========================================
        parcial1Temporal = ValidarNotas("I Parcial");
        parcial2Temporal = ValidarNotas("II Parcial");
        parcial3Temporal = ValidarNotas("III Parcial");
        
        parcial1.push_back(parcial1Temporal);
        parcial2.push_back(parcial2Temporal);
        parcial3.push_back(parcial3Temporal);

        // Limpiamos el buffer del cin >> de las notas
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        system("cls");
        
        // Cálculos matemáticos usando las variables temporales
        double notaFinal = (parcial1Temporal * 0.25) + (parcial2Temporal * 0.35) + (parcial3Temporal * 0.40);
        notasFinales.push_back(notaFinal);
        
        string pond = obtenerPonderacion(notaFinal);
        ponderaciones.push_back(pond);

        if (notaFinal >= 65) {
            estados.push_back("Aprobado");
            aprobados++;
        } else {
            estados.push_back("Reprobado");
            reprobados++;
        }
        sumaPromedios += notaFinal;

        // Avanzamos al siguiente estudiante registrado
        contadorEstudiantes++; 
        // Mostrar datos individuales
        mostrarDatosEstudiante(nombres, apellidos, numerosCuenta, notaFinal, 
            ponderaciones.back(), estados.back(), contadorEstudiantes - 1);

        // ===================================================================
        // LA PREGUNTA que nos ayuda a continuar o no
        // Solo se activa si ya registramos al menos 3
        // ===================================================================
        if (contadorEstudiantes >= 3) {
            string entrada; // Cambiamos a string para poder detectar el "Enter" vacío

            do {
                cout << "Desea ingresar otro estudiante? (S/N): ";
                getline(cin, entrada); // Lee toda la línea, incluyendo si solo presionan Enter

                // 1. Validar si quedó vacío
                if (entrada.empty()) {
                    cout << "Error: No puede dejar la opcion en blanco.\n";
                    continuar = 'X'; // Forzamos valor inválido para repetir el ciclo
                }
                // 2. Validar que no metan más de un carácter (evita textos largos o números de varios dígitos)
                else if (entrada.length() != 1) {
                    cout << "Error: Ingrese solo una letra ('S' o 'N').\n";
                    continuar = 'X';
                }
                // 3. Si metieron un solo carácter, lo procesamos
                else {
                    continuar = toupper(entrada[0]); // Guardamos el carácter en tu variable original 'continuar'

                    if (isdigit(continuar)) {
                        cout << "Error: No se permiten numeros. Ingrese 'S' o 'N'.\n";
                        continuar = 'X';
                    }
                    else if (continuar != 'S' && continuar != 'N') {
                        cout << "Error: Ingrese una opcion valida ('S' o 'N').\n";
                    }
                }

            } while (continuar != 'S' && continuar != 'N');
            
            // Al usar getline aquí, ya no necesitas el cin.ignore() abajo.
        } else {
            continuar = 'S'; 
        }


    } while (continuar == 'S'); // Se repite si el usuario quiere 'S'

    system("cls"); // Limpiamos la pantalla antes de mostrar el reporte final
    
    // =======================================================
    // FIN DEL REGISTRO. ACTUALIZAMOS LA VARIABLE 'n'
    // =======================================================
    int contadorNuevo = contadorEstudiantes; // Ahora 'n' guarda el total real de alumnos ingresados
    
    // Promedio General y cantidad de aprobados y reprobados
    double promedioGeneral = sumaPromedios / contadorNuevo;
    double porcentajeAprobados = ((double)aprobados / contadorNuevo) * 100;
    double porcentajeReprobados = ((double)reprobados / contadorNuevo) * 100;

    // Crear el archivo e imprimimos los resultados 
    ofstream archivo("reporte_estudiantes.txt");
    
    if (!archivo) {
        cout << "Error al crear el archivo de texto.\n";
        return 1;
        }

    // Imprimir encabezado de la tabla en Pantalla y en el Archivo
    // usamos setw para alinear las columnas y left para alinear a la izquierda
    cout << "\n========================================= REPORTE DE ESTUDIANTES =================================================================================================\n";
    cout << left << setw(15) << "N Cuenta" << setw(30) << "Nombres" << setw(30) << "Apellidos" << setw(15) << "Nota Final" << setw(15) << "Ponderacion" << setw(12) << "Estado" << "\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    archivo << "========================================= REPORTE DE ESTUDIANTES ======================================================================================================\n";
    archivo << left << setw(15) << "N Cuenta" << setw(30) << "Nombres" << setw(30) << "Apellidos" << setw(15) << "Nota Final" << setw(15) << "Ponderacion" << setw(12) << "Estado" << "\n";
    archivo << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    // imprimir la tabla fila por fila
    for (int i = 0; i < contadorNuevo; i++) {
            cout << left << setw(15) << numerosCuenta[i] 
             << setw(30) << nombres[i] 
             << setw(30) << apellidos[i]
              //lo usamos para mostrar 2 decimales en la nota final
             << setw(15) << fixed << setprecision(2) << notasFinales[i] 
             << setw(15) << ponderaciones[i] 
             << setw(12) << estados[i] << "\n";
        //lo mismo para el archivo de texto
        archivo << left << setw(15) << numerosCuenta[i] 
                << setw(30) << nombres[i] 
                << setw(30) << apellidos[i] 
                << setw(15) << fixed << setprecision(2) << notasFinales[i] 
                << setw(15) << ponderaciones[i] 
                << setw(12) << estados[i] << "\n";
    }

    //  mostramos las estadisticas generales en Pantalla y en el Archivo
    cout << "----------------------------------------------------------------------------------------------------------\n";
    cout << "Total de estudiantes ingresados: " << contadorNuevo << "\n";
    cout << "Promedio general del grupo     : " << fixed << setprecision(2) << promedioGeneral << "\n";
    cout << "Cantidad de Aprobados          : " << aprobados << " (" << fixed << setprecision(2) << porcentajeAprobados << "%)\n";
    cout << "Cantidad de Reprobados         : " << reprobados << " (" << fixed << setprecision(2) << porcentajeReprobados << "%)\n";

    archivo << "----------------------------------------------------------------------------------------------------------\n";
    archivo << "Total de estudiantes ingresados: " << contadorNuevo << "\n";
     //lo usamos para mostrar 2 decimales en la nota final
    archivo << "Promedio general del grupo     : " << fixed << setprecision(2) << promedioGeneral << "\n";
    archivo << "Cantidad de Aprobados          : " << aprobados << " (" << fixed << setprecision(2) << porcentajeAprobados << "%)\n";
    archivo << "Cantidad de Reprobados         : " << reprobados << " (" << fixed << setprecision(2) << porcentajeReprobados << "%)\n";
    
    // Listado de aprobados en Pantalla y en el Archivo
    cout << "\nEstudiantes Aprobados:\n";
    archivo << "\nEstudiantes Aprobados:\n";
    for (int i = 0; i < contadorNuevo; i++) {
        if (estados[i] == "Aprobado") {
            cout << "- " << nombres[i] << " " << apellidos[i] << "\n";
            archivo << "- " << nombres[i] << " " << apellidos[i] << "\n";
        }
    }

    // Listado de reprobados en Pantalla y en el Archivo
    cout << "\nEstudiantes Reprobados:\n";
    archivo << "\nEstudiantes Reprobados:\n";
    for (int i = 0; i < contadorNuevo; i++) {
        if (estados[i] == "Reprobado") {
            cout << "- " << nombres[i] << " " << apellidos[i] << "\n";
            archivo << "- " << nombres[i] << " " << apellidos[i] << "\n";
        }
    }

    // Cerramos el flujo del archivo
    archivo.close();
    
    cout << "\n[!] Los datos han sido guardados exitosamente en el archivo 'reporte_estudiantes.txt'.\n";
    
    return 0;
}