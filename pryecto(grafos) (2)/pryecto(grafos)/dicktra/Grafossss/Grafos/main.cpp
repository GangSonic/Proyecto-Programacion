#include <iostream>
#include "TGrafo.h"
#include <fstream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,m; 
	cout << "Escribe los NODOS del grafo: " << endl; 
	
	
	
	//cout << n; 
 

	/// DECLARACIONES PARA DIKSTRA 
	TGrafo grafo(n); 
	grafo.leer_matrizC("prueba2.txt"); 
		
	
	/*

	grafo.Dijkstra(0); 
	*/ 
	
	
	//grafo.recorre_profundidad(0); 
	//grafo.recorre_amplitud(0); 
	return 0;
}
