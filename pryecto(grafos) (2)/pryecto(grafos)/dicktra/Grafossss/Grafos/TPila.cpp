#include "TPila.h"

TPila::TPila(int n)
{
	this->n=n; 
	tope=0; 
	pila=new int[n]; 
}

bool TPila::pila_vacia()
{
	return tope==0; 
}

bool TPila::pila_llena()
{
	return tope==n; 
}

void TPila::inserta_dato(int dato)
{
	if(!pila_llena())
	pila[tope++] = dato; 
	else 
	cout << "ERRORR!!!! pila llena " << endl; 

}

int TPila::devuelve_dato()
{
	int dato=-2000000; 
	if(!pila_vacia())
	{
		dato=pila[--tope]; 
	} else 
	{
		cout << "ERROR!!!! pila vacia "<< endl; 
	}
	return dato; 
}

void TPila::muestra_elementos()
{
	
	if(pila_vacia())
	{
	
	cout << "La pila esta vacia, llenala ;D" << endl; 
	
} else 
{
	cout << "Pila: " << endl; 
	for(int i=tope-1; i>=0; i--)
	{
		cout <<pila[i] << " "; 
		
	}
	 
}
}
