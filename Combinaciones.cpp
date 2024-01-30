#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string frutas[] = {"Manzana", "Banana", "Naranja", "Fresa", "Kiwi", "Mango", "Pera", "Uva", "Melon", "Papaya"};
string preparados[] = {"Jugo", "Ensalada", "Frape", "Tarta", "Helado", "Mermelada", "Batido", "Asado", "Coctel", "Crudo"};
string fruta[5];
string preparado[5];

int generarNumeroAleatorio(int max)
{
	return rand() % max;
}

void generar()
{
	for (int i = 0; i < 5; i++)
	{
		fruta[i] = frutas[generarNumeroAleatorio(10)];
		preparado[i] = preparados[generarNumeroAleatorio(10)];
	}
}

void imprimir()
{
	cout << "MENU DE PRODUCTOS:" << endl;
	for (int i = 0; i < 5; i++)
		cout << preparado[i] << " de " << fruta[i] << endl;
}

int main()
{
	srand(time(0)); // Semilla para la generación de números aleatorios basada en el tiempo actual
	generar();
	imprimir();
	return 0;
}
