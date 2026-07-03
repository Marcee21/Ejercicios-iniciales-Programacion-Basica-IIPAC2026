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
#include <vector>    // Para el uso de vectores paralelos que almacenan la informacion
#include <string>    // Para el manejo avanzado de cadenas de texto (nombres, cuentas, estados)
#include <fstream>   // Para la creacion, apertura, escritura y cierre del archivo fisico de texto
#include <iomanip>   // Para el control milimetrico de formateo de flujos y alineacion exacta de columnas
#include <cctype>    // Para el uso de funciones de verificacion de caracteres como isalpha y isspace

using namespace std; 

// =========================================================================
// FUNCION AUXILIAR DE VALIDACION DE TEXTO (SOLO LETRAS Y ESPACIOS)
// =========================================================================
// Esta funcion recibe una cadena y verifica caracter por caracter que no tenga numeros.
// Retorna 'true' si el texto es valido (solo letras/espacios) o 'false' si encuentra anomalias.
bool esTextoValido(const string& texto) {
    if (texto.empty()) return false; // Una cadena vacia no es un nombre valido
    
    for (int i = 0; i < texto.length(); ++i) {
        // isalpha comprueba si es letra, isspace comprueba si es un espacio en blanco
        if (!isalpha(texto[i]) && !isspace(texto[i])) {
            return false; // Si encuentra un numero o simbolo, rompe la validacion e informa el fallo
        }
    }
    return true; // El texto es completamente alfabetico
}

int main() {
    // -----------------------------------------------------------------
    // DECLARACION DE VECTORES PARALELOS
    // -----------------------------------------------------------------
    // Estructura de almacenamiento indexado donde la posicion [i] de cada vector pertenece al mismo alumno
    vector<string> nombres;       // Almacena el nombre completo concatenado (nombre + apellido)
    vector<string> cuentas;       // Almacena el numero de cuenta valido de exactamente 11 digitos
    vector<char> sexos;           // Almacena el genero de identificacion estudiantil (M/m/F/f)
    vector<double> promedios;     // Almacena el promedio final calculado bajo los pesos parciales
    vector<string> escalas;       // Almacena la ponderacion cualitativa asignada (Excelente, Regular, etc.)
    vector<string> estados;       // Almacena el estado final de la condicion (APROBADO o REPROBADO)

    // -----------------------------------------------------------------
    // VARIABLES DE CONTROL Y ESTADISTICAS GLOBAL
    // -----------------------------------------------------------------
    char continuar = 'S';          // Bandera que controla la continuidad del ciclo de captura de datos
    int contadorEstudiantes = 0;   // Contador entero para registrar el total de alumnos procesados
    double sumaPromedios = 0.0;    // Acumulador de punto flotante para totalizar las notas de la seccion
    int aprobados = 0;             // Contador especifico para alumnos con nota mayor o igual a 60%
    int reprobados = 0;            // Contador especifico para alumnos con nota menor a 60%

    // Banner de presentacion institucional limpio diseñado con caracteres uniformes
    cout << "=========================================================================" << endl;
    cout << "        SISTEMA DE CONTROL DE CALIFICACIONES - SECCION DE INFORMATICA    " << endl;
    cout << "=========================================================================" << endl;
    cout << " * Nota: Se deben ingresar obligatoriamente los primeros 3 estudiantes.\n" << endl;

    // Limpieza de banderas de error iniciales del flujo de la consola
    cin.clear();

    // -----------------------------------------------------------------
    // CICLO DE CAPTURA DE DATOS (Minimo 3 iteraciones obligatorias de control)
    // -----------------------------------------------------------------
    while (continuar == 'S' || continuar == 's' || contadorEstudiantes < 3) {
        
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "                    REGISTRO DEL ESTUDIANTE #" << (contadorEstudiantes + 1) << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        string nom, ape, numCuenta;
        char sexo;
        double p1, p2, p3;

        // --- VALIDACION DE ENTRADA PARA EL NOMBRE INDIVIDUAL ---
        while (true) {
            cout << "Ingrese el nombre: ";
            cin >> nom;
            cin.ignore(); // Vacia el residuo del teclado para evitar colisiones en la lectura del apellido
            
            if (esTextoValido(nom)) {
                break; // Nombre correcto, sale del bucle de validacion
            }
            cout << " -> [ERROR] El nombre no debe contener numeros ni caracteres especiales. Reintente.\n";
        }

        // --- VALIDACION DE ENTRADA PARA EL APELLIDO INDIVIDUAL ---
        while (true) {
            cout << "Ingrese el apellido: ";
            cin >> ape;
            cin.ignore(); // Limpia el bufer del teclado completamente
            
            if (esTextoValido(ape)) {
                break; // Apellido correcto, sale del bucle de validacion
            }
            cout << " -> [ERROR] El apellido no debe contener numeros ni caracteres especiales. Reintente.\n";
        }

        // Concatenacion formal de las variables alfabeticas validadas
        string nombreCompleto = nom + " " + ape; 

        // --- VALIDACION DE LONGITUD Y DUPLICIDAD DEL NUMERO DE CUENTA ---
        while (true) {
            cout << "Ingrese el numero de cuenta (11 digitos): ";
            cin >> numCuenta;
            cin.ignore(); 

            // Control estricto de longitud de caracteres de la cadena
            if (numCuenta.length() != 11) {
                cout << " -> [ERROR] Cuenta invalida. Debe tener exactamente 11 digitos. Reintente.\n";
                continue; 
            }

            // Verificacion de duplicados mediante busqueda secuencial en el vector existente
            bool yaExiste = false;
            for (int i = 0; i < cuentas.size(); ++i) {
                if (cuentas[i] == numCuenta) {
                    yaExiste = true; // Se encontro coincidencia exacta en el sistema
                    break;
                }
            }

            if (yaExiste) {
                cout << " -> [ERROR] Esta cuenta ya pertenece a otro estudiante. Reintente.\n";
            } else {
                break; // Cuenta unica y valida de 11 digitos aceptada
            }
        }

        // --- VALIDACION DEL CARACTER DE GENERO (SEXO) ---
        while (true) {
            cout << "Ingrese el sexo (M/m/F/f): ";
            cin >> sexo;
            cin.ignore(); 
            // Evaluacion de opciones aceptables mediante conectores logicos
            if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f') {
                break; 
            }
            cout << " -> [ERROR] Genero incorrecto. Ingrese M o F (Mayuscula o minuscula).\n";
        }

        // --- VALIDACIONES INDIVIDUALES DE RANGOS DE NOTAS ACADEMICAS (0 A 100) ---
        while (true) {
            cout << "Nota del I Parcial (0-100): "; cin >> p1; cin.ignore();
            if (p1 >= 0 && p1 <= 100) break;
            cout << " -> [ERROR] La nota debe estar en el rango de 0 a 100.\n";
        }
        while (true) {
            cout << "Nota del II Parcial (0-100): "; cin >> p2; cin.ignore();
            if (p2 >= 0 && p2 <= 100) break;
            cout << " -> [ERROR] La nota debe estar en el rango de 0 a 100.\n";
        }
        while (true) {
            cout << "Nota del III Parcial (0-100): "; cin >> p3; cin.ignore();
            if (p3 >= 0 && p3 <= 100) break;
            cout << " -> [ERROR] La nota debe estar en el rango de 0 a 100.\n";
        }

        // --- CALCULOS DE RENDIMIENTO INDIVIDUAL ---
        // Aplicacion de formula de pesos porcentuales ponderados (25%, 35%, 40%)
        double promedioFinal = (p1 * 0.25) + (p2 * 0.35) + (p3 * 0.40);
        
        // Asignacion dinamica de escala cualitativa segun rangos oficiales de rendimiento
        string ponderacion;
        if (promedioFinal >= 90 && promedioFinal <= 100) ponderacion = "Excelente";
        else if (promedioFinal >= 80 && promedioFinal < 90) ponderacion = "Muy Bueno";
        else if (promedioFinal >= 70 && promedioFinal < 80) ponderacion = "Bueno";
        else if (promedioFinal >= 60 && promedioFinal < 70) ponderacion = "Regular";
        else ponderacion = "Maleta";

        // Determinacion del estado de aprobacion institucional
        string estado;
        if (promedioFinal >= 60) {
            estado = "APROBADO";
            aprobados++; // Incrementa acumulador global de aprobados
        } else {
            estado = "REPROBADO";
            reprobados++; // Incrementa acumulador global de reprobados
        }

        // --- ALMACENAMIENTO EN VECTORES PARALELOS ---
        // Se insertan los datos validados al final de cada coleccion dinamica manteniendo los indices alineados
        nombres.push_back(nombreCompleto);
        cuentas.push_back(numCuenta);
        sexos.push_back(sexo);
        promedios.push_back(promedioFinal);
        escalas.push_back(ponderacion);
        estados.push_back(estado);

        // Actualizacion de acumuladores de control general de la seccion
        sumaPromedios += promedioFinal; 
        contadorEstudiantes++;         

        // --- IMPRESION DE LA FICHA INDIVIDUAL EN CONSOLA ---
        cout << fixed << setprecision(2); // Formateo fijo a dos cifras decimales para promedios financieros y academicos
        cout << "\n============================================================" << endl;
        cout << "|               RESUMEN ACADEMICO INDIVIDUAL               |" << endl;
        cout << "============================================================" << endl;
        cout << "  Estudiante : " << nombreCompleto << endl;
        cout << "  N. Cuenta  : " << numCuenta << "  |  Sexo: " << sexo << endl;
        cout << "  Promedio   : " << promedioFinal << " %" << endl;
        cout << "  Escala     : " << ponderacion << endl;
        cout << "  Condicion  : " << estado << endl;
        cout << "------------------------------------------------------------\n" << endl;

        // Control de ruptura o continuidad evaluando la condicion limite de 3 alumnos obligatorios
        if (contadorEstudiantes >= 3) {
            while (true) {
                cout << "Desea registrar otro estudiante? (S/N): ";
                cin >> continuar; cin.ignore(); 
                if (continuar == 'S' || continuar == 's' || continuar == 'N' || continuar == 'n') {
                    break; 
                }
                cout << " -> [ERROR] Opcion no valida. Introduzca unicamente S o N.\n";
            }
        }
    }

    // --- PROCESAMIENTO ESTADISTICO GLOBAL DE LA SECCION ---
    double promedioGeneralGlobal = sumaPromedios / contadorEstudiantes; 
    double porcentajeAprobados = ((double)aprobados / contadorEstudiantes) * 100.0; 
    double porcentajeReprobados = ((double)reprobados / contadorEstudiantes) * 100.0; 

    // -----------------------------------------------------------------
    // REPORTE GENERAL EN PANTALLA CON ALINEACION PERFECTA
    // -----------------------------------------------------------------
    cout << fixed << setprecision(2); 
    cout << "\n=========================================================================================================" << endl;
    cout << "|                               REPORTE GENERAL DE RENDIMIENTO ACADEMICO                                |" << endl;
    cout << "=========================================================================================================" << endl;
    cout << "| " << left << setw(8)  << "No." 
         << "| " << setw(25) << "Nombre Completo" 
         << "| " << setw(15) << "N. Cuenta" 
         << "| " << setw(6)  << "Sexo" 
         << "| " << setw(10) << "Promedio" 
         << "| " << setw(14) << "Escala" 
         << "| " << setw(12) << "Estado" << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;

    // Recorrido secuencial de las estructuras paralelas para la visualizacion general tabulada
    for (int i = 0; i < nombres.size(); ++i) {
        string indiceStr = "[" + to_string(i + 1) + "]";
        cout << "| " << left << setw(8)  << indiceStr
             << "| " << setw(25) << nombres[i]
             << "| " << setw(15) << cuentas[i]
             << "| " << setw(6)  << sexos[i]
             << "| " << setw(10) << promedios[i]
             << "| " << setw(14) << escalas[i]
             << "| " << setw(12) << estados[i] << "|" << endl;
    }
    cout << "=========================================================================================================" << endl;

    // -----------------------------------------------------------------
    // CUADRO ESTADISTICO GLOBAL EN CONSOLA (DISEÑO MATEMATICO ALINEADO)
    // -----------------------------------------------------------------
    // Ancho total interno disponible entre palitos de control = 62 caracteres exactos.
    cout << "\n==================================================================" << endl;
    cout << "|                    CUADRO ESTADISTICO GLOBAL                   |" << endl;
    cout << "==================================================================" << endl;
    
    cout << "| Cantidad Total de Estudiantes Ingresados  | " << left << setw(17) << contadorEstudiantes << "|" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    cout << "| Promedio General Obtenido en la Seccion   | " << left << setw(13) << promedioGeneralGlobal << " % |" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    // Para las lineas complejas calculamos la longitud del string dinamico para rellenar los espacios faltantes de forma exacta
    string filaAprobados = to_string(aprobados) + " Alumnos (" + to_string((int)porcentajeAprobados) + "%)";
    cout << "| Cantidad y Porcentaje de Aprobados        | " << left << setw(17) << filaAprobados << "|" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    string filaReprobados = to_string(reprobados) + " Alumnos (" + to_string((int)porcentajeReprobados) + "%)";
    cout << "| Cantidad y Porcentaje de Reprobados       | " << left << setw(17) << filaReprobados << "|" << endl;
    cout << "==================================================================" << endl;

    // -----------------------------------------------------------------
    // LISTADOS FILTRADOS DE ESTUDIANTES ACADEMICOS
    // -----------------------------------------------------------------
    cout << "\n==================================================================" << endl;
    cout << "|                  LISTADO DE ALUMNOS APROBADOS                  |" << endl;
    cout << "==================================================================" << endl;
    for (int i = 0; i < estados.size(); ++i) { 
        if (estados[i] == "APROBADO") {       
            cout << "  * " << nombres[i] << " (N. Cuenta: " << cuentas[i] << ")" << endl;
        }
    }

    cout << "\n==================================================================" << endl;
    cout << "|                  LISTADO DE ALUMNOS REPROBADOS                 |" << endl;
    cout << "==================================================================" << endl; 
    for (int i = 0; i < estados.size(); ++i) { 
        if (estados[i] == "REPROBADO") {      
            cout << "  * " << nombres[i] << " (N. Cuenta: " << cuentas[i] << ")" << endl;
        }
    }

    // -----------------------------------------------------------------
    // EXPORTACION AUTOMATICA AL ARCHIVO FISICO EN DISCO HARDWARE
    // -----------------------------------------------------------------
    ofstream archivo("Reporte_Estudiantes.txt"); 
    
    if (archivo.is_open()) { 
        archivo << fixed << setprecision(2); // Formato del flujo del archivo de texto
        
        // Escritura de la tabla estructurada general en el archivo de texto
        archivo << "=========================================================================================================\n";
        archivo << "|                               REPORTE GENERAL DE RENDIMIENTO ACADEMICO                                |\n";
        archivo << "=========================================================================================================\n";
        archivo << "| " << left << setw(8)  << "No." 
                << "| " << setw(25) << "Nombre Completo" 
                << "| " << setw(15) << "N. Cuenta" 
                << "| " << setw(6)  << "Sexo" 
                << "| " << setw(10) << "Promedio" 
                << "| " << setw(14) << "Escala" 
                << "| " << setw(12) << "Estado" << "|\n";
        archivo << "---------------------------------------------------------------------------------------------------------\n";

        for (int i = 0; i < nombres.size(); ++i) {
            string indiceStr = "[" + to_string(i + 1) + "]";
            archivo << "| " << left << setw(8)  << indiceStr
                    << "| " << setw(25) << nombres[i]
                    << "| " << setw(15) << cuentas[i]
                    << "| " << setw(6)  << sexos[i]
                    << "| " << setw(10) << promedios[i]
                    << "| " << setw(14) << escalas[i]
                    << "| " << setw(12) << estados[i] << "|\n";
        }
        archivo << "=========================================================================================================\n";
        
        // Escritura del Cuadro Estadistico perfectamente alineado en el archivo de disco
        archivo << "\n==================================================================\n";
        archivo << "|                    CUADRO ESTADISTICO GLOBAL                   |\n";
        archivo << "==================================================================\n";
        
        archivo << "| Cantidad Total de Estudiantes Ingresados  | " << left << setw(17) << contadorEstudiantes << "|\n";
        archivo << "------------------------------------------------------------------\n";
        
        archivo << "| Promedio General Obtenido en la Seccion   | " << left << setw(13) << promedioGeneralGlobal << " % |\n";
        archivo << "------------------------------------------------------------------\n";
        
        archivo << "| Cantidad y Porcentaje de Aprobados        | " << left << setw(17) << filaAprobados << "|\n";
        archivo << "------------------------------------------------------------------\n";
        
        archivo << "| Cantidad y Porcentaje de Reprobados       | " << left << setw(17) << filaReprobados << "|\n";
        archivo << "==================================================================\n";
        
        // Escritura complementaria de los listados ordenados dentro del reporte fisico
        archivo << "\n==================================================================\n";
        archivo << "|                  LISTADO DE ALUMNOS APROBADOS                  |\n";
        archivo << "==================================================================\n";
        for (int i = 0; i < estados.size(); ++i) { 
            if (estados[i] == "APROBADO") {       
                archivo << "  * " << nombres[i] << " (N. Cuenta: " << cuentas[i] << ")\n";
            }
        }

        archivo << "\n==================================================================\n";
        archivo << "|                  LISTADO DE ALUMNOS REPROBADOS                 |\n";
        archivo << "==================================================================\n";
        for (int i = 0; i < estados.size(); ++i) { 
            if (estados[i] == "REPROBADO") {      
                archivo << "  * " << nombres[i] << " (N. Cuenta: " << cuentas[i] << ")\n";
            }
        }
        
        archivo.close(); // Liberacion y cierre seguro del flujo de memoria asignado al archivo
        cout << "\n[INFO] Exito total! Todo el reporte se ha exportado correctamente a 'Reporte_Estudiantes.txt'." << endl;
    } else {
        cout << "\n[ERROR] El archivo de texto no pudo ser creado en el almacenamiento." << endl;
    }

    return 0; // Finalizacion correcta del programa principal
}