#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	// Concatenando la cadena de una variable. 
	string Lyu;
	Lyu = "I love C++";
	cout << "La cadena es: " + Lyu << endl;
	cout << "La longitud de la cadena es: " << Lyu.length() << endl;
	// Si el valor de retorno es 0, significa que la cadena no esta, vacia. 
	cout << "¿Está¡ vacío?" << Lyu.empty() << endl << endl;
	Lyu.append("!"); // Agrega uno despues de la cadena!
	cout << "La cadena modificada es: " << Lyu << endl << endl;
	string Lyu_2;
	Lyu_2 = "I love too";
	Lyu.swap(Lyu_2); // Intercambio de datos de cadenas. 
	cout <<"Cambie la cadena modificada como: " <<Lyu << endl << endl;
	
	int site;
	site = Lyu.find('l',0);  //Encuentra la posicion donde aparece l desde 0 y regresar. 
	cout << "La posicion donde aparece l en la cadena es: " << site << endl; 
	site = Lyu.find("oo",0); //Encuentra la posicion donde aparece oo desde 0 y regresar. 
	cout <<"La posicion donde aparece oo en la cadena es: " << site << endl;
	site = 0; // Recorrer y buscar todas las posiciones o. 
	do
{
		site = Lyu.find ('o', site);
		if (site == -1)
			cout << "Busqueda completada, no hay otros elementos" << endl;
		else
			cout << "La posicion donde aparece o en la cadena es:" <<site << endl;
		site++;
	} while (site !=0);
	//  a - 4
	// e - 3
	// i - 1
	// o - 0
	// u - 5
	
	getchar();
	return 0;
}
