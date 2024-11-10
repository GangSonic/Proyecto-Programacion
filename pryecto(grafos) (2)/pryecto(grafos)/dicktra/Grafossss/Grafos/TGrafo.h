#ifndef TGRAFO_H
#define TGRAFO_H
#define tam 100

#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;


class TGrafo
{
	int n, m; 
	int origen, destino, tiempo; 
	std::vector<std::vector<int>> matrizA;
    std::vector<std::vector<int>> matrizC;; 
	int infinito= 2000000; 
	void recorre(int); 
	void recorre2(int); //para amplitud en profundidad 
	bool visitado[tam]; 
	//int matriz[tam][tam]; 
	
	public:
	TGrafo(int); 
	void leer_matrizA(); 
	void mostrar_matrizA();
	
	void leer_matrizC(const string &filename); 
	void mostrar_matrizC(); 
	void Dijkstra(int); 
	
	void recorre_profundidad(int); 
	void recorre_amplitud(int); 
	 
	//void leer_matriz(); 
	//void mostrar_matriz(); 
};

#endif
