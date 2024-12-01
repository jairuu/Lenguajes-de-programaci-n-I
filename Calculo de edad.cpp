#include <iostream>
using namespace std;

int main() {
    int edad;

    // Se solicita la edad al usuario
    cout << "Ingresa tu edad: ";
    cin >> edad;

    // Por medio de un if se determina si es mayor o menor
    if (edad >= 18) {
        cout << "Eres mayor de edad." << endl;
    } else {
        cout << "Eres menor de edad." << endl;
    }

    return 0;
}