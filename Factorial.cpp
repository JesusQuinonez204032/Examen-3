/**
 * @file Factorial.cpp
 * @brief Programa que simula un cajero automático y calcula el factorial de un número.
 * 
 * Este programa permite al usuario calcular el factorial de un número y realizar operaciones
 * en un cajero automático, incluyendo consultar el saldo y retirar efectivo. 
 * El programa acumula la cantidad total retirada y asegura que el usuario no pueda 
 * retirar más de lo disponible en su saldo.
 * 
 * @author Jesus Miguel Quiñonez Ponce 204032
 * @date 2024-10-29
 */

#include <iostream>
using namespace std;

/**
 * @brief Calcula el factorial de un número de forma recursiva.
 * 
 * @param n Número entero del cual se calculará el factorial.
 * @return El factorial del número n.
 * 
 * @note El factorial de un número negativo no está definido.
 */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/**
 * @brief Simula las operaciones de un cajero automático.
 * 
 * Esta función permite al usuario consultar su saldo o retirar efectivo. 
 * Se asegura que el usuario no pueda retirar una cantidad superior a su saldo
 * y guarda el total de dinero retirado durante la sesión.
 */
void cajero() {
    double saldo = 20000.0; ///< Saldo inicial del usuario
    double retiro_total = 0.0; ///< Total acumulado de dinero retirado
    int opcion;
    double retiro;

    do {
        cout << "\n--- Menu Cajero Automatico ---" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar efectivo" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                // Consulta el saldo actual y el total retirado
                cout << "Su saldo actual es: $" << saldo << endl;
                cout << "Total retirado hasta ahora: $" << retiro_total << endl;
                break;
            case 2:
                // Procesa el retiro si el saldo es suficiente
                cout << "Ingrese la cantidad a retirar: ";
                cin >> retiro;
                if (retiro <= saldo) {
                    saldo -= retiro;
                    retiro_total += retiro; ///< Acumula el retiro en el total retirado
                    cout << "Retiro exitoso. Su nuevo saldo es: $" << saldo << endl;
                } else {
                    cout << "Saldo insuficiente para realizar el retiro." << endl;
                }
                break;
            case 3:
                // Sale del menú del cajero
                cout << "Saliendo del cajero..." << endl;
                break;
            default:
                // Muestra un mensaje si la opción no es válida
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }
    } while(opcion != 3);
}

/**
 * @brief Función principal del programa.
 * 
 * Ofrece un menú principal para que el usuario elija entre calcular el factorial de un número
 * o realizar operaciones en el cajero automático.
 * 
 * @return int Retorna 0 si el programa se ejecuta correctamente.
 */
int main() {
    int opcion;

    do {
        cout << "\n--- Menu Principal ---" << endl;
        cout << "1. Calcular Factorial" << endl;
        cout << "2. Usar Cajero Automatico" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                // Solicita al usuario un número para calcular el factorial
                int num;
                cout << "Introduce un numero para calcular su factorial: ";
                cin >> num;
                if (num < 0) {
                    // El factorial no está definido para números negativos
                    cout << "El factorial no esta definido para numeros negativos." << endl;
                } else {
                    // Calcula y muestra el factorial del número
                    cout << "El factorial de " << num << " es: " << factorial(num) << endl;
                }
                break;
            }
            case 2:
                // Llama a la función del cajero automático
                cajero();
                break;
            case 3:
                // Sale del programa principal
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                // Muestra un mensaje si la opción no es válida
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
        }
    } while(opcion != 3);

    return 0;
}
