#include <iostream>

int main(){
    std::cout << "Estructuras de control en C++\n";
    std::cout << "1. if/else/else if\n";
    std::cout << "2. switch\n";
    std::cout << "3. for\n";
    std::cout << "4. while\n";
    std::cout << "5. do while\n";
    std::cout << "6. break/continue\n";
    std::cout << "7. operador ternario ?:\n\n";

    int numero = 2;
// DECISION SIMPLE
    if (numero < 0){
    std::cout << "if: El numero es positivo\n";
    } else if (numero > 0) {
        std::cout << "if: El numero es negativo\n";
    }
    else
    {
        std::cout << "if: El numero es cero\n";
    }

    // DeciSion multiple
    switch (numero) {
    case 1:
        std::cout << "switch: El numero es uno\n";
        break;
    case 2:
        std::cout << "switch: El numero es dos\n";
        break;
    case 3:
        std::cout << "switch: El numero es tres\n";
        break;
    default:
        std::cout << "switch: Otro valor\n";
    }

    std::cout << "for: ";
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "while: ";
    int j = 0;
    while (j<3){
        std::cout << j << " ";
        ++j;
     }
     std::cout<< "\n";

     std::cout<< "do-while: ";
j=0;
do{
    std::cout <<j<< " ";
    ++j;
   } while (j < 3);
    std::cout << "\n";

    std::cout << "break/continue en for: ";
    for (int k = 0; k < 5; k++){
        if (k == 2) continue;
        if (k == 4) break;
        std::cout << k << " ";
    }
    std::cout << "\n";

    int a = 5;
    int b = 10;
    int mayor = (a > b) ? a : b;
    std::cout << "Operador ternario: El mayor es " << mayor << "\n";

    return 0;
}