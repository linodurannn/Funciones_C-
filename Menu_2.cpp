/*
Titulo: Trabajo Practico #2. Ejercicio 2. 
Autor: Lino Ervin Duran Serrudo 
Descripcion: Realizar un programa con funciones y parámetros por referencia para que realice las siguientes
tareas.
		GENERANDO NÚMEROS ALEATORIOS
		1. Genere al azar numero entre 0-500.
		2. Genere un numero aleatorio real.
		3. Genere N números primos.
		S/s. Salir.
Fecha:2024 - 01 - 26
*/
#include <iostream> // Incluye la biblioteca para entrada/salida estándar.
#include <cstdlib> // Incluye la biblioteca para funciones generales de C++.
#include <ctime> // Incluye la biblioteca para funciones relacionadas con el tiempo.
#include <vector> // Incluye la biblioteca para el uso de vectores.
#include <algorithm> // Incluye la biblioteca para algoritmos estándar.
#include <cmath> // Incluye la biblioteca para funciones matemáticas.

using namespace std; // Utiliza el espacio de nombres para evitar el uso de std. 

// Declaración de funciones.
void gen_Num_0y500(int &numero);
void gen_Num_Real(double &numero);
void gen_Num_Primos(int cantidad);
bool esPrimo(int num);

// Función principal
int main() {
	srand(time(0)); // Inicializa la semilla del generador de números aleatorios con el tiempo actual.
	
	char opcion; // Variable para almacenar la opción del usuario.
	
	do {
		cout << "GENERADOR DE NUMEROS ALEATORIOS" << endl; // Muestra de mensajes.
		cout << "1. Número aleatorio entre 0 y 500: " << endl;
		cout << "2. Número aleatorio real: " << endl;
		cout << "3. Números primos: " << endl;
		cout << "S/s. Salir" << endl;
		
		cout << "Seleccione una opción: "; // Solicita la elección del usuario.
		cin >> opcion; // Lee la opción.
		
		switch (opcion) {
		case '1': {
			int numero; // Variable para el número aleatorio.
			gen_Num_0y500(numero); // Genera y muestra el número aleatorio.
			cout << "Número aleatorio: " << numero << endl;
			break;
		}
		case '2': {
			double numeroReal; // Variable para el número real aleatorio.
			gen_Num_Real(numeroReal); // Genera y muestra el número real aleatorio.
			cout << "Número real aleatorio: " << numeroReal << endl;
			break;
		}
		case '3': {
			int cantidad; // Variable para la cantidad de números primos.
			cout << "Cantidad de números primos: ";
			cin >> cantidad; // Lee la cantidad.
			gen_Num_Primos(cantidad); // Genera y muestra números primos.
			break;
		}
		case 's':
		case 'S':
			break; // Sale del bucle si la opción es 's' o 'S'.
		default:
			cout << "Opción no válida. Intente de nuevo." << endl; // Muestra un mensaje de error.
		}
	} while (opcion != 's' && opcion != 'S'); // Repite mientras no sea 's' o 'S'.
	
	return 0; // Retorna 0 para indicar una ejecución exitosa.
}

// Función para generar un número aleatorio entre 0 y 500
void gen_Num_0y500(int &numero) {
	numero = rand() % 501; // Genera un número aleatorio y lo asigna.
}

// Función para generar un número real aleatorio entre 0 y 1
void gen_Num_Real(double &numero) {
	numero = (double)rand() / RAND_MAX; // Genera un número real aleatorio y lo asigna.
}

// Función para generar una cantidad específica de números primos aleatorios
void gen_Num_Primos(int cantidad) {
	vector<int> primos; // Vector para almacenar los números primos.
	int numero = 2; // Inicia con el primer número primo.
	
	while (primos.size() < cantidad) {
		if (esPrimo(numero)) { // Verifica si el número actual es primo.
			primos.push_back(numero); // Si es primo, lo agrega al vector.
		}
		
		++numero; // Avanza al siguiente número.
	}
	
	random_shuffle(primos.begin(), primos.end()); // Mezcla los números primos en el vector.
	
	cout << "Números primos aleatorios: ";
	for (int primo : primos) {
		cout << primo << " "; // Muestra los números primos aleatorios.
	}
	
	cout << endl;
}

// Función para verificar si un número es primo
bool esPrimo(int num) {
	if (num < 2) {
		return false; // Los números menores a 2 no son primos.
	}
	
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			return false; // Si es divisible por algún número en el rango, no es primo.
		}
	}
	
	return true; // Si no tiene divisores, es primo.
}
