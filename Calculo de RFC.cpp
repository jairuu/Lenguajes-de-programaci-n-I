#include <iostream>
#include <string>
#include <cctype> // Para usar la función toupper() cuya finalidad es convertir un caracter a mayuscula

using namespace std;

// Función para encontrar la primera vocal interna de un apellido
char primeraVocal(const string& apellido) {
    for (int i = 1; i < apellido.length(); i++) {
        char c = tolower(apellido[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return toupper(c);
        }
    }
    return 'X';  // En caso de que no haya una vocal en el apellido 
}

// Función para generar el RFC
string generaRFC(const string& apellidoPaterno, const string& apellidoMaterno, const string& nombre, const string& fecha) 
{
    string rfc;
    rfc += toupper(apellidoPaterno[0]);  // Primera letra del apellido paterno
    rfc += primeraVocal(apellidoPaterno);  // Primera vocal interna del apellido paterno
    rfc += (apellidoMaterno.empty() ? 'X' : toupper(apellidoMaterno[0]));  // Primera letra del apellido materno o 'X' si no existe
    rfc += toupper(nombre[0]);  // Primera letra del nombre

    // Procesar la fecha de nacimiento en el formato DD/MM/AAAA o DD-MM-AAAA
    string year = fecha.substr(6, 4);
    string mes = fecha.substr(3, 2);
    string dia = fecha.substr(0, 2);

    // Añadir al RFC los últimos dos dígitos del año, mes y día
    rfc += year.substr(2, 2);
    rfc += mes;
    rfc += dia;

    return rfc;
}

int main() {
    string apellidoPaterno, apellidoMaterno, nombre, fecha;
    
    cout << "Ingresa tu apellido paterno: ";
    cin >> apellidoPaterno;
    cout << "Ingresa tu apellido materno: ";
    cin >> apellidoMaterno;
    cout << "Ingresa tu primer nombre: ";
    cin >> nombre;
    cout << "Ingresa tu fecha de nacimiento (DD/MM/AAAA): ";
    cin >> fecha;
    
    string rfc = generaRFC(apellidoPaterno, apellidoMaterno, nombre, fecha);
    cout << "Tu RFC es: " << rfc << endl;

    return 0;
}