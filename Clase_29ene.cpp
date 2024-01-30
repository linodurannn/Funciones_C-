#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char caracter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int numero[10];
char c[10];

// UTILIZAR FUNCIONES.
// Función para generar un carácter aleatorio.
char generarCaracter()
{
	return caracter[rand() % sizeof(caracter) / sizeof(caracter[0])];
}

// Función para generar un número aleatorio.
int generarNumero()
{
	return rand() % 51;
}

// Función que verifica si un número ya ha sido generado.
bool numeroRepetido(int num, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (numero[i] == num)
		{
			return true;
		}
	}
	return false;
}

// Función para imprimir los datos generados. 
void imprimir()
{
	cout << "CAR\tNUM" << endl;
	for (int i = 0; i < 10; i++)
		cout << c[i] << "\t" << numero[i] << endl;
}

// Función para generar datos sin números repetidos. 
void generarDatos()
{
	for (int i = 0; i < 10; i++)
	{
		int num;
		do
		{
			num = generarNumero();
		} while (numeroRepetido(num, i));
		
		numero[i] = num;
		c[i] = generarCaracter();
	}
}

int main()
{
	srand(time(0)); // Semilla para la generación de números aleatorios basada en el tiempo actual. 
	generarDatos();
	imprimir();
	return 0;
}
