/*
Titulo: Trabajo Practico #3. Ejercicio 1. 
Autor: Lino Ervin Duran Serrudo 
Descripcion: Realizar un menu con funciones.
Fecha:2024 - 01 - 229
*/
// Incluir las bibliotecas necesarias.
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;

// Función para calcular la suma de una cadena de números.
int sumarCadena(const string& cadena) {
	// Inicializa variables.
	size_t pos = 0;
	int suma = 0;
	
	while (pos < cadena.length()) {
		// Inicializa una cadena para almacenar el número.
		string numStr;
		
		// Extrae los dígitos de la cadena y los acumula en numStr.
		while (pos < cadena.length() && isdigit(cadena[pos])) {
			numStr += cadena[pos];
			pos++;
		}
		
		// Si numStr no está vacío, convierte y suma el número a la suma total.
		if (!numStr.empty()) {
			suma += stoi(numStr);
		}
		
		// Avanza al siguiente carácter.
		pos++;
	}
	return suma;
}

// Función para invertir el orden de las palabras en una cadena
string invertirNombre(const string& cadena) {
	// Inicializa un flujo de cadena.
	stringstream ss(cadena);
	string palabra, resultado;
	
	// Tokeniza la cadena en palabras y las invierte
	while (ss >> palabra) {
		palabra[0] = toupper(palabra[0]);
		resultado = palabra + " " + resultado;
	}
	return resultado;
}

// Función para ofuscar una cadena.
string ofuscarCadena(const string& cadena) {
	// Inicializa la cadena de resultado.
	string resultado;
	
	// Itera a través de cada carácter de la cadena.
	for (char ch : cadena) {
		// Reemplaza caracteres específicos con números.
		switch (toupper(ch)) {
		case 'A':
		case 'a':
			resultado += '4';
			break;
		case 'E':
		case 'e':
			resultado += '3';
			break;
		case 'I':
		case 'i':
			resultado += '1';
			break;
		case 'O':
		case 'o':
			resultado += '0';
			break;
		case 'S':
		case 's':
			resultado += '5';
			break;
		case 'T':
		case 't':
			resultado += '7';
			break;
		default:
			resultado += ch;
		}
	}
	return resultado;
}

// Función principal del programa
int main() {
	// Declaración de variables
	char opcion;
	
	// Bucle principal del programa
	do {
		// Muestra el menú principal
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Suma de una cadena:" << endl;
		cout << "2. Nombre Completo:" << endl;
		cout << "3. Ofuscar cadena:" << endl;
		cout << "S/s. Salir." << endl;
		
		cout << "Elija una opción: ";
		cin >> opcion;
		cin.ignore(); 
		
		switch (opcion) {
		case '1': {
			string cadena;
			cout << "Ingrese una cadena de números: ";
			getline(cin, cadena);
			
			// Calcula y muestra el resultado de la suma
			int resultado = sumarCadena(cadena);
			cout << "Resultado de la suma: " << resultado << endl;
			break;
		}
		case '2': {
			string cadena;
			cout << "Ingrese nombre completo: ";
			getline(cin, cadena);
			
			// Invierte y muestra el nombre
			string resultado = invertirNombre(cadena);
			cout << "Nombre invertido: " << resultado << endl;
			break;
		}
		case '3': {
			string cadena;
			cout << "Ingrese cadena a ofuscar: ";
			getline(cin, cadena);
			
			// Ofusca la cadena y muestra el resultado
			string resultado = ofuscarCadena(cadena);
			cout << "Cadena ofuscada: " << resultado << endl;
			break;
		}
		case 's':
		case 'S':
			// Sale del programa si el usuario elige salir.
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Ingrese opción correcta." << endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	// Retorna 0 para indicar una ejecución exitosa
	return 0;
}
