#include <iostream>
using namespace std;

int main()
{
	//Declaraciones de variables
	double numero1, numero2;

	//Se solicita la cantidad al usuario

	cout << "Escribe el primer numero: ";
	     cin >>numero1;
	cout << "Escribe el segundo numero: ";
	     cin >>numero2;

	//Operaciones

	double suma = numero1 + numero2;
	double resta = numero1 - numero2;
	double multiplicacion = numero1 * numero2;
	double division;

	//Para realizar la operacion correctamente

	if (numero2 != 0)
	{
		division = numero1 / numero2;
	} 
	else
	{
	    cout << "La división no es posible realizarse.\n";
	    division = 0;
	}
	
	// Mostrar resultados
	cout << "La suma es: " << suma << endl;
	cout << "La resta es: " << resta << endl;
	cout << "La multiplicación es: " << multiplicacion << endl;
	 if (numero2 != 0) {
        cout << "La división es: " << division << endl;
    }

		return 0;
	}