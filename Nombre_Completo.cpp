#include <iostream>
#include <string>
#include <cctype> // Necesario para toupper
using namespace std;

int main() {
	// Solicitar el nombre completo
	cout << "Ingrese su nombre completo: ";
	string nombre_completo;
	getline(cin, nombre_completo);
	
	// Variables para almacenar nombre, apellido paterno y apellido materno
	string pini, papellido, mapellido;
	
	size_t pos1 = nombre_completo.find(' ');
	if (pos1 != string::npos) {
		// Convertir la primera letra del nombre a mayúscula
		pini += toupper(nombre_completo[0]);
		pini += nombre_completo.substr(1, pos1 - 1);
		
		size_t pos2 = nombre_completo.find(' ', pos1 + 1);
		if (pos2 != string::npos) {
			// Convertir la primera letra del apellido paterno a mayúscula
			papellido += toupper(nombre_completo[pos1 + 1]);
			papellido += nombre_completo.substr(pos1 + 2, pos2 - pos1 - 2);
			
			// Convertir la primera letra del apellido materno a mayúscula
			mapellido += toupper(nombre_completo[pos2 + 1]);
			mapellido += nombre_completo.substr(pos2 + 2);
		} else {
			papellido = nombre_completo.substr(pos1 + 1);
			mapellido = "";
		}
	} else {
		// Convertir la primera letra del nombre a mayúscula
		pini += toupper(nombre_completo[0]);
		pini += nombre_completo.substr(1);
		
		papellido = "";
		mapellido = "";
	}
	
	// Imprimir los resultados
	cout << "Nombre: " << pini << endl;
	cout << "Apellido Paterno: " << papellido << endl;
	cout << "Apellido Materno: " << mapellido << endl;
	
	return 0;
}
