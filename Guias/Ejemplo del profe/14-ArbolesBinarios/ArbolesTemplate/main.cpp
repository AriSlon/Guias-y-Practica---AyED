#include <iostream>
#include "arboles.hpp"

using namespace std;

int ordentero(int a, int b) 
{
	return a - b;
}

int lexicografico(string a, string b)
{
	return a.compare(b);
}

int main()
{
	NodoAr<int>* raiz = nullptr;
	insertar(6 , raiz, ordentero);
	insertar(3 , raiz, ordentero);
	insertar(5 , raiz, ordentero);
	insertar(2 , raiz, ordentero);
	insertar(10, raiz, ordentero);
	insertar(8 , raiz, ordentero);
	insertar(14, raiz, ordentero);
	
	cout << "======= PREORDEN =======" << endl;
	preorden(raiz, ver);
	
	cout << endl << "======= POSTORDEN =======" << endl;
	postorden(raiz, ver);
	
	cout << endl << "======= INORDEN =======" << endl;
	inorden(raiz, ver);

	borrar(raiz);

	//Con string
	NodoAr<string> *raizs {nullptr};
	insertar("McLaren"s ,raizs, lexicografico);
	insertar("Aston Martin"s ,raizs, lexicografico);
	insertar("Red Bull"s ,raizs, lexicografico);
	insertar("Ferrari"s ,raizs, lexicografico);
	insertar("Mercedes-AMG"s ,raizs, lexicografico);
	insertar("Williams"s ,raizs, lexicografico);
	insertar("Alpine"s ,raizs, lexicografico);

	cout << "======= PREORDEN =======" << endl;
	preorden(raizs, ver);
	
	cout << endl << "======= POSTORDEN =======" << endl;
	postorden(raizs, ver);
	
	cout << endl << "======= INORDEN =======" << endl;
	inorden(raizs, ver);

	borrar(raizs);
	return 0;
}

