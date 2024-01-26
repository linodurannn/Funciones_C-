#include <iostream>
#include <cstdlib>
#include <ctime>

// Prototipos de funciones
void generarNumeroEntre0y500(int &numero);
void generarNumeroReal(double &numero);
void generarNumerosPrimos(int N);

int main() {
	srand(time(0));
	
	char opcion;
	
	do {
		std::cout << "\nGENERANDO NUMEROS ALEATORIOS\n";
		std::cout << "(1) -- Genere al azar número entre 0-500\n";
		std::cout << "(2) -- Genere un número aleatorio real\n";
		std::cout << "(3) -- Genere N números primos\n";
		std::cout << "(s/S) -- Salir\n";
		
		std::cout << "Seleccione una opción: ";
		std::cin >> opcion;
		
		switch (opcion) {
		case '1': {
			int numeroAleatorio;
			generarNumeroEntre0y500(numeroAleatorio);
			std::cout << "Número generado entre 0 y 500: " << numeroAleatorio << "\n";
			break;
		}
		case '2': {
			double numeroRealAleatorio;
			generarNumeroReal(numeroRealAleatorio);
			std::cout << "Número real aleatorio: " << numeroRealAleatorio << "\n";
			break;
		}
		case '3': {
			int N;
			std::cout << "Ingrese la cantidad de números primos a generar: ";
			std::cin >> N;
			generarNumerosPrimos(N);
			break;
		}
		case 's':
		case 'S':
			break;
		default:
			std::cout << "Opción no válida. Inténtelo de nuevo.\n";
		}
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

void generarNumeroEntre0y500(int &numero) {
	numero = rand() % 501;
}

void generarNumeroReal(double &numero) {
	numero = (double)rand() / RAND_MAX;
}

void generarNumerosPrimos(int N) {
	int contador = 0;
	int numero = 2;
	
	while (contador < N) {
		bool esPrimo = true;
		
		for (int i = 2; i <= numero / 2; ++i) {
			if (numero % i == 0) {
				esPrimo = false;
				break;
			}
		}
		
		if (esPrimo) {
			std::cout << numero << " ";
			++contador;
		}
		
		++numero;
	}
	
	std::cout << "\n";
}
