#include <iostream>
#include <sstream>
#include <cctype> // Necesario para toupper
using namespace std;

// Función para calcular la suma de una cadena de números
int sumaCadena(const string& cadena) {
	size_t pos = 0;
	int suma = 0;
	
	while (pos < cadena.length()) {
		string numero_str;
		while (pos < cadena.length() && isdigit(cadena[pos])) {
			numero_str += cadena[pos];
			pos++;
			} 
			if (!numero_str.empty()){
				suma += stoi(numero_str);
		}
				pos++; 
	}
	
	
	return suma;
}

// Función para invertir el orden de las palabras en una cadena
string nombreCompleto(const string& cadena) {
	stringstream ss(cadena);
	string palabra, resultado;
	while (ss >> palabra) {
		if (!resultado.empty()) {
			resultado = palabra + " " + resultado;
		} else {
			resultado = palabra;
		}
	}
	return resultado;
}

// Función para ofuscar una cadena según las reglas dadas
string ofuscarCadena(const string& cadena) {
	string resultado;
	for (char ch : cadena) {
		switch (toupper(ch)) {
		case 'A':
			resultado += '4';
			break;
		case 'E':
			resultado += '3';
			break;
		case 'I':
			resultado += '1';
			break;
		case 'O':
			resultado += '0';
			break;
		case 'S':
			resultado += '5';
			break;
		case 'T':
			resultado += '7';
			break;
		default:
			resultado += ch;
		}
	}
	return resultado;
}

int main() {
	char opcion;
	
	do {
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Suma de una cadena" << endl;
		cout << "2. Nombre completo" << endl;
		cout << "3. Ofuscar palabra" << endl;
		cout << "S/s. Salir" << endl;
		
		cout << "Ingrese su opción: ";
		cin >> opcion;
		cin.ignore(); // Limpiar el buffer de entrada
		
		switch (opcion) {
		case '1': {
			string cadena;
			cout << "Ingrese la cadena de números: ";
			getline(cin, cadena);
			int resultado = sumaCadena(cadena);
			cout << "El resultado de la suma es: " << resultado << endl;
			break;
		}
		case '2': {
			string cadena;
			cout << "Ingrese el nombre completo: ";
			getline(cin, cadena);
			string resultado = nombreCompleto(cadena);
			cout << "El nombre completo invertido es: " << resultado << endl;
			break;
		}
		case '3': {
			string cadena;
			cout << "Ingrese la cadena a ofuscar: ";
			getline(cin, cadena);
			string resultado = ofuscarCadena(cadena);
			cout << "La cadena ofuscada es: " << resultado << endl;
			break;
		}
		case 's':
		case 'S':
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}
