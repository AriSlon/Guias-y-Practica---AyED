#include <iostream>
#include "listas.hpp"

using namespace std;

//Para palabras, no me preocupo por espacios en blanco
bool esCapicua(string palabra)
{
	Nodo<char> *pila {nullptr};
	int largo = palabra.size();
	int i;

	//Ingreso los caracteres en la pila
	for (i = 0; i < largo; ++i)
		push(pila, palabra[i]);

	//compruebo si la reversa que sale de la pila es igual a la frase
	for (i = 0; i < largo && palabra[i] == pop(pila); ++i);

	//Si no son capicúa debo terminar de vaciar la pila
	while (pila != nullptr)
		pop(pila);

	//es capicúa si TODOS los caracteres coincidían, o sea, si paró por
	//no cumplir i < largo
	return i == largo;
}

//Para frases, elimino espacios en blanco para no tenerlos en cuenta
bool esCapicuaSB(string frase) //SB -> sin blancos
{
	Nodo<char> *pila {nullptr};
	int largo = frase.size();
	int i;

	//Ingreso los caracteres en la pila ignorando los espacios en blanco
	for (i = 0; i < largo; ++i)
		if (frase[i] != ' ')
			push(pila, frase[i]);

	//compruebo si la reversa que sale de la pila es igual a la frase
	for (i = 0; i < largo; ++i)
		if (frase[i] != ' ' && frase[i] != pop(pila))
			break;

	while (pila) //Si no son capicúa debo terminar de vaciar la pila
		pop(pila);

	//es capicúa si TODOS los caracteres coincidían, o sea, si paró por
	//no cumplir i < largo (no usó el break)
	return i == largo;
}

int main()
{
	string cadena;
	// ejemplo de palabras capicua: anana, neuquen, nadan, radar, reconocer, somos
	cout << "Ingrese la palabra a comprobar: ";
	cin >> cadena;

	if (esCapicua(cadena))
		cout << cadena << " es capicua" << endl;
	else
		cout << cadena << " NO es capicua" << endl;

	// Variante con frase, debo ignorar espacios. Ejemplos:
	// amad a la dama
	// amor a Roma
	// ana lava lana
	// atar a la rata
	// la ruta natural
	// luz azul
	// se verla al reves
	// somos o no somos
	// yo de todo te doy
	cout << "Ingrese la frase a comprobar: ";
	cin.get(); //elimino /n dejado por el cin>> anterior
	getline(cin, cadena); //uso getline, sino me corta en el primer espacio

	if (esCapicuaSB(cadena))
		cout << cadena << " es palindromo" << endl;
	else
		cout << cadena << " NO es palindromo" << endl;
	return 0;
}
