#ifndef TLISTA_H
#define TLISTA_H
 
#include <iostream>
#include "TNodo.h"
using namespace std;
 
class TLista
{
	TNodo *cab, *ultimo; 
	public:
		TLista(); 
		void inserta_inicio(int); 
		void inserta_final(int); 
		void inserta_ordenado(int); 
		void mostrar_lista(); 
		void elimina_dato(int dato); 
		void elimina_lista(); 
		
		int elimina_inicio(); 
};
 
#endif