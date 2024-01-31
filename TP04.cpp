/*
Titulo: Trabajo Practico #4. Ejercicio 1. 
Autor: Lino Ervin Duran Serrudo 
Descripcion: Realizar un menu: Codigo realizado a imprimir notas aleatorias de 1 - 30 puntos.   	
1. Llenar nombres, apellidos y notas de forma aleatoria. 
2. Ofuscar nombres y apellidos para llenar las contraseñas.
3. Sacar la media, el mayor y menor de todas las notas.
4. Imprimir datos.
S/s. Salir
Fecha:2024 - 01 - 31
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Variables para almacenar nombres, apellidos y notas.
string nombres[] = {"Ervin", "Diego", "Andrea", "Eddy", "Lucia", "Favio", "Rubi", "Joel", "Ana", "Enrique"};
string apellidos[] = {"Duran", "Serrudo", "Salame", "Quiroga", "Mamani", "Sanchez", "Ortiz", "Lino", "Rocha", "Cortez"};
int notas[10];  // Variable para almacenar las notas de los estudiantes.
bool datosGenerados = false;  // Variable para verificar si se han generado datos aleatorios.

// Función para generar datos aleatorios de nombres, apellidos y notas.
void generarDatosAleatorios() {
	srand(time(0));
	
	cout << "Nombre\tApellido\tNota" << endl;
	
	for (int i = 0; i < 10; ++i) {
		// Generar índices aleatorios para nombres y apellidos.
		int nombreAlea = rand() % (10 - i);
		int apellidoAlea = rand() % (10 - i);
		
		// Obtener nombre y apellido aleatorio.
		string nombre = nombres[nombreAlea];
		string apellido = apellidos[apellidoAlea];
		
		// Intercambiar elementos en los arreglos para evitar repeticiones.
		swap(nombres[nombreAlea], nombres[9 - i]);
		swap(apellidos[apellidoAlea], apellidos[9 - i]);
		
		// Generar nota aleatoria evitando el valor 0.
		int nota;
		do {
			nota = rand() % 31;
		} while (nota == 0);
		
		// Almacenar nota en el arreglo.
		notas[i] = nota;
		
		// Mostrar datos generados.
		cout << nombre << "\t" << apellido << "\t\t" << nota << endl;
	}
	
	datosGenerados = true; // Indicar que los datos han sido generados.
}

// Función para ofuscar texto según reglas dadas.
string ofuscarTexto(const string& texto) {
	string ofuscado = "";
	
	for (char c : texto) {
		// Aplicar reglas de ofuscación.
		switch (c) {
		case 'A':
		case 'a':
			ofuscado += '4';
			break;
		case 'E':
		case 'e':
			ofuscado += '3';
			break;
		case 'I':
		case 'i':
			ofuscado += '1';
			break;
		case 'O':
		case 'o':
			ofuscado += '0';
			break;
		case 'S':
		case 's':
			ofuscado += '5';
			break;
		case 'T':
		case 't':
			ofuscado += '7';
			break;
		default:
			ofuscado += c;
		}
	}
	
	return ofuscado; // Devolver texto ofuscado.
}

// Función para ofuscar nombres y apellidos y mostrar contraseñas.
void ofuscarDatos() {
	if (!datosGenerados) {
		cout << "Debes generar datos aleatorios primero (Opción 1)." << endl;
		return;
	}
	
	cout << "Contraseñas ofuscadas mismo orden (Opción 1):" << endl;
	
	for (int i = 9; i >= 0; --i) {
		// Ofuscar nombres y apellidos.
		string nombreOfuscado = ofuscarTexto(nombres[i]);
		string apellidoOfuscado = ofuscarTexto(apellidos[i]);
		
		// Mostrar contraseñas ofuscadas.
		cout << "Contraseña: " << nombreOfuscado << apellidoOfuscado << endl;
	}
}

// Función para analizar y mostrar estadísticas de notas.
void analizarNotas() {
	if (notas[0] == 0) {
		cout << "No hay datos de notas disponibles." << endl;
		return;
	}
	
	double media = 0;
	int mayor = notas[0];
	int menor = notas[0];
	int notaMayorIndice = 0;
	int notaMenorIndice = 0;
	
	// Calcular media, nota mayor y nota menor.
	for (int i = 0; i < 10; ++i) {
		media += notas[i];
		
		if (notas[i] > mayor) {
			mayor = notas[i];
			notaMayorIndice = i;
		}
		
		if (notas[i] < menor) {
			menor = notas[i];
			notaMenorIndice = i;
		}
	}
	
	media /= 10; // Calcular media.
	
	// Mostrar estadísticas.
	cout << "Media de notas = " << media << endl;
	cout << "Nota mayor = " << mayor << " del Alumno " << nombres[notaMayorIndice] << " " << apellidos[notaMayorIndice] << endl;
	cout << "Nota menor = " << menor << " del Alumno " << nombres[notaMenorIndice] << " " << apellidos[notaMenorIndice] << endl;
}

// Función para imprimir todos los datos generados.
void imprimirDatos() {
	double media = 0;
	int mayor = notas[0];
	int menor = notas[0];
	int notaMayorIndice = 0;
	int notaMenorIndice = 0;
	
	cout << "Nombre\tApellido\tNota\tContraseña" << endl;
	
	for (int i = 0; i < 10; ++i) {
		// Mostrar datos personales.
		cout << nombres[i] << "\t" << apellidos[i] << "\t\t" << notas[i] << "\t";
		
		// Ofuscar nombres y apellidos.
		string nombreOfuscado = ofuscarTexto(nombres[i]);
		string apellidoOfuscado = ofuscarTexto(apellidos[i]);
		
		// Mostrar contraseñas ofuscadas.
		cout << nombreOfuscado << apellidoOfuscado << endl;
		
		// Calcular estadísticas.
		media += notas[i];
		
		if (notas[i] > mayor) {
			mayor = notas[i];
			notaMayorIndice = i;
		}
		
		if (notas[i] < menor) {
			menor = notas[i];
			notaMenorIndice = i;
		}
	}
	
	media /= 10;  // Calcular media.
	cout << "Media de notas = " << media << endl;
	cout << "Nota mayor = " << mayor << " del Alumno " << nombres[notaMayorIndice] << " " << apellidos[notaMayorIndice] << endl;
	cout << "Nota menor = " << menor << " del Alumno " << nombres[notaMenorIndice] << " " << apellidos[notaMenorIndice] << endl;
}

// Función principal.
int main() {
	int opcion;
	
	do {
		// Mostrar menú principal.
		cout << "MENU PRINCIPAL" << endl;
		cout << "1. Llenar nombres, apellidos y notas de forma aleatoria." << endl;
		cout << "2. Ofuscar nombres y apellidos para contraseñas" << endl;
		cout << "3. Sacar la media, el mayor y menor de todas las notas" << endl;
		cout << "4. Imprimir datos" << endl;
		cout << "S/s. Salir" << endl;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		// Realizar acciones según la opción seleccionada.
		switch (opcion) {
		case 1:
			generarDatosAleatorios();
			break;
		case 2:
			ofuscarDatos();
			break;
		case 3:
			analizarNotas();
			break;
		case 4:
			imprimirDatos();
			break;
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
