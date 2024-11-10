#ifndef TPILA_H
#define TPILA_H
#include <iostream>
using namespace std; 


class TPila
{
	int *pila; 
	int n, tope; 
	
	public: 
	TPila(int);
	bool pila_vacia(); 
	bool pila_llena(); 
	void inserta_dato(int); 
	int devuelve_dato(); 
	void muestra_elementos(); 
	
};

#endif