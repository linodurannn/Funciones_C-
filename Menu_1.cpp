/*
Titulo: Trabajo Practico #2. Ejercicio 1. 
Autor: Lino Ervin Duran Serrudo 
Descripcion: Generar un programa con el uso de variables globales para realizar el siguiente menu y
submenu:
		MENU PRINCIPAL:
		1. Operaciones con Números.
		2. Concatenar 2 cadenas.
		S/s. Salir
		SUBMENU OP NUMEROS:
		1. Suma de 2 números.
		2. División de 2 números.
		M/m. Volver al Menu principal.
Fecha:2024 - 01 - 26
*/
#include <iostream>
using namespace std;

// Variables para los números.
double num1 = 0;
double num2 = 0;

// Variables para las cadenas.
string cadena1 = "";
string cadena2 = "";

// Prototipos de funciones
void menuNumerico();  // Declarar el prototipo de la función para el submenú de operaciones numéricas.
void sumaNumeros();  // Declarar el prototipo de la función para sumar dos números.
void divisionNumeros();  // Declarar el prototipo de la función para dividir dos números.
void concatenarCadenas();  // Declarar el prototipo de la función para concatenar dos cadenas.

// Función Principal.
int main() {
	char opcion;
	
	// Bucle del menú principal.
	do {
		// Mostrar opciones del menú principal.
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Operaciones con Números:" << endl;
		cout << "2. Concatenar Cadenas:" << endl;
		cout << "S/s. Salir" << endl;
		
		// Solicitar la elección del usuario.
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		// Procesar la elección del usuario.
		switch (opcion) {
		case '1':
			menuNumerico();
			break;
		case '2':
			concatenarCadenas();
			break;
		case 's':
		case 'S':
			break;
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

// Submenú para Operaciones Numéricas.
void menuNumerico() {
	char opcion;
	
	// Bucle del submenú de operaciones numéricas.
	do {
		// Mostrar submenú para operaciones numéricas.
		cout << "Operaciones Numéricas" << endl;
		cout << "1. Suma de 2 números:" << endl;
		cout << "2. División de 2 números:" << endl;
		cout << "M/m. Volver al Menú principal" << endl;
		
		// Solicitar la elección del usuario.
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		// Procesar la elección del usuario.
		switch (opcion) {
		case '1':
			cout << "Ingrese el primer número: ";
			cin >> num1;
			cout << "Ingrese el segundo número: ";
			cin >> num2;
			sumaNumeros();
			break;
		case '2':
			cout << "Ingrese el primer número: ";
			cin >> num1;
			cout << "Ingrese el segundo número: ";
			cin >> num2;
			divisionNumeros();
			break;
		case 'm':
		case 'M':
			break;
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
	} while (opcion != 'm' && opcion != 'M');
}

// Función para realizar la suma.
void sumaNumeros() {
	double resultado = num1 + num2;
	cout << "La suma de " << num1 << " y " << num2 << " es: " << resultado << endl;
}

// Función para realizar la división.
void divisionNumeros() {
	if (num2 != 0) {
		double resultado = num1 / num2;
		cout << "La división de " << num1 << " entre " << num2 << " es: " << resultado << endl;
	} else {
		cout << "No se puede dividir entre cero." << endl;
	}
}

// Función para concatenar cadenas.
void concatenarCadenas() {
	cout << "Ingrese la primera cadena: ";
	cin >> cadena1;
	cout << "Ingrese la segunda cadena: ";
	cin >> cadena2;
	
	string resultado = cadena1 + " " + cadena2;
	cout << "La concatenación de las cadenas es: " << resultado << endl;
}
