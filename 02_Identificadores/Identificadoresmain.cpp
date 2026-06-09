 #include <iostream>
 #include <string>

    int main() {
        int entero = 10;
        float flotante = 3.14;
        double doble = 2.71828;
        char caracter = 'A';
        bool booleano = true;
        long enteroLargo = 1000000;
        short enteroCorto = 100;
        unsigned int sinSigno = 50;
        //wchar_t caracterAncho = L'B';
        // std::string texto = "Hola, mundo!";

        std::cout << "Tipos de variables en C++ con un ejemplo: \n";
        std::cout << "int: " << entero << "\n";
        std::cout << "float: " << flotante << "\n";
        std::cout << "double: " << doble << "\n";
        std::cout << "char: " << caracter << "\n";
        std::cout << "bool: " << booleano << "\n";
        std::cout << "long: " << enteroLargo << "\n";
        std::cout << "short: " << enteroCorto << "\n";
        std::cout << "unsigned int: " << sinSigno << "\n";
        //std::cout << "wchar_t: " << caracterAncho << "\n";


        return 0;
    }