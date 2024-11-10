#include "TGrafo.h"
#include "TPila.h"
#include <fstream>
#include <limits>
#include <vector>
 

TGrafo:: TGrafo(int n)
{
	this->n=n; 
}


/// Matiz A 

/*
void TGrafo:: leer_matrizA()
{
	cout << "Ingresa nodos del grafo" << endl; 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
		{
			cout << "Camino de " << i+1 << " a " << j+1 << ": "<< endl; 
			cin >> matrizA [i][j]; 
		}
		cout << endl; 
	}
}

void TGrafo:: mostrar_matrizA()
{
	cout << "La matriz de adyacencia es: " << endl; 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << matrizA[i][j]<< "  "; 
			//cout << endl; 
		}
		cout << endl; 
	}
 } 
 */ 
 
 ///Matriz C (matriz de costos) 
 
 /// Modificar la matriz para que reciba 
 /* 
 	- Una linea con dos enteros N (vertices) y M (caminos) 
 	- Una linea con dos enteros (comienzo) y (final) 
 	- Una linea con un entero k (numero de caminos a calcular) 
 	- M lineas, cada una con tres enteros (origen[i], destino[i], tiempo[i]) 
 
 */ 
const int infinito = numeric_limits<int>::max();

void TGrafo::leer_matrizC(const string &filename) {
    ifstream archivo(filename); // lectura del archivo

    // Verificamos si el archivo se abre correctamente
    if (!archivo.is_open()) {
        cerr << "Error, no se puede abrir el archivo" << endl;
        return;
    }

    // Leemos la cantidad de nodos (n) y aristas (m)
    archivo >> n >> m;
    cout << "Nodos: " << n << ", Aristas: " << m << endl;

    // Verificamos que se hayan leído correctamente
    if (archivo.fail()) {
        cerr << "Error al leer los datos de nodos o aristas." << endl;
        archivo.close();
        return;
    }

    // Leemos nodos de inicio y final (no usados en este caso)
    int nodo_inicio, nodo_final;
    archivo >> nodo_inicio >> nodo_final;

    // Leemos el número de caminos a calcular (no usado directamente en la matriz de costos)
    int k;
    archivo >> k;

    // Inicializamos la matriz de costos con "infinito"
    matrizC.resize(n, vector<int>(n, infinito));

    // Imprimimos un mensaje antes de leer las aristas
    cout << "Leyendo las aristas..." << endl;

    // Variables para leer origen, destino y tiempo
    int origen, destino, tiempo;

    // Leemos las aristas: origen, destino y tiempo (costo)
    int count = 0;
    while (archivo >> origen >> destino >> tiempo) {
        cout << "Arista " << count + 1 << " -> Origen: " << origen << ", Destino: " << destino << ", Costo: " << tiempo << endl;

        origen--; // Ajustamos los índices a base 0
        destino--; // Ajustamos los índices a base 0

        // Si el tiempo es -1, lo consideramos como infinito
        matrizC[origen][destino] = (tiempo == -1) ? infinito : tiempo;

        count++;
    }

    // Verificamos que se leyeron todas las aristas
    if (count != m) {
        cerr << "Error: no se pudieron leer todas las aristas. Se leyeron " << count << " en lugar de " << m << endl;
    } else {
        cout << "Se leyeron todas las aristas correctamente." << endl;
    }

    archivo.close();

    // Llamamos a mostrar_matrizC() para imprimir la matriz resultante
    mostrar_matrizC();
}

void TGrafo::mostrar_matrizC() {
    cout << "La matriz de costos es: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrizC[i][j] == infinito) {
                cout << "00" << " "; 
            } else {
                cout << matrizC[i][j] << " "; // Mostramos el valor real de la matriz
            }
        }
        cout << endl; // Nueva línea después de cada fila
    }
    cout << "Matriz mostrada correctamente." << endl;
}

 
 
 
 /// BUSQUEDA DE PROFUNDIDAD 
 
 /*
 void TGrafo:: recorre(int nodo_inicial)
 {
 	cout << nodo_inicial << " "; 
 	visitado[nodo_inicial] = true; 
 	for(int i=0; i<n; i++)
 		if(matrizA[nodo_inicial][i]== 1 && !visitado[i])
 			recorre(i); 	
 }
 
 void TGrafo:: recorre_profundidad(int nodo_inicial)
 {
 	cout << "Recorrido en profundidad " << endl; 
 	for(int i=0; i<n; i++)
 		visitado[i] = false; 
 		recorre(nodo_inicial); 
 }

*/ 	
	
//// BUSQUEDA EN AMPLITUD GRAFOS 

/*
void TGrafo::recorre2(int nodo_inicial)
{	
	bool cola[tam]; 
	for(int i=0; i<n; i++)
	{
		cola[i] = false; 
	}
	cola[nodo_inicial]= true; 
	visitado[nodo_inicial]= true; 
	

while(true)
{
	bool aux=false; 
	
	for(int i=i; i<n; i++)
	{
		if (cola[i])
		{
			cout<< i << " "; 
			cola[i]= false; 
			
			for(int j=0; j<n; j++)
			{
				if(matrizA[i][j] == 1 && !visitado[j])
				{
					cola[j]= true; 
					visitado[j]= true; 
					aux=true; 
				}
			}
		}
	}
	if(!aux)
	{
		break; 
		}
	}
}


void TGrafo::recorre_amplitud(int nodo_inicial)
{
	cout << "Recorrido en amplitud" << endl;
	for (int i=0; i<n; i++)
	{
		visitado[i]= false; 
	 } 
	 recorre2(nodo_inicial); 
}

*/ 


void TGrafo:: Dijkstra(int nodo_inicial)
{
	// Declaraciones 
	
	bool S[n]; 
	int D[n]; 
	int P[n]; 
	int w, minimo; 
	TPila pila(n); 
	
	/// Incializamos varibales
	for(int i=0; i<n; i++)
	{
		S[i]= false; 
		D[i]= matrizC[nodo_inicial][i]; 
		P[i]= nodo_inicial; 
	}
	
	S[nodo_inicial] = true; 
	
	///Algoritmo Dijkstra 
	
	for(int i=1; i<n; i++)
	{
		minimo= infinito; 
		for(int j=0; j<n; j++)
		if(!S[j])
		{
			if(D[j]< minimo)
			{
				minimo= D[j]; 
				w=j; 
			}
		}
		
		S[w]= true; /// 
		for(int v=0; v<n; v++)
		{
			if(!S[v])
			{
				if(D[w] + matrizC[w][v] < D[v])
				{
					D[v]= D[w] + matrizC[w][v]; 
					///cambios para guardar caminos 
					P[v]= w;
				}
			}
		}
		
	}
	
	for(int i=0; i<n; i++)
	{
		if(i!=nodo_inicial)
		{
			cout << "Ruta: "; 
			int j=i; 
			pila.inserta_dato(j); 
			while(P[j] != nodo_inicial)
			{
				pila.inserta_dato(P[j]); 
				j=P[j]; 
			}
			cout << endl << nodo_inicial << endl; 
			while (!pila.pila_vacia())
				cout << (pila.devuelve_dato() +1) << endl;  /// cambiar a " " + "-" creo 
			cout << "Con costo minimo: " << D[i] << endl; 
			
		}
	}
	
	/*
	/// Mostramos vector costos minimos 
	
 	for(int i=0; i<n; i++)
	{
		cout << endl; 
		cout << "Costo minimo de: " << nodo_inicial+1 << " a " << i+1 << " es " << D[i]<< endl;  
	}
	
	/// Mostramos caminos minimos 
	cout << endl; 
		for(int i=0; i<n; i++)
	{
		cout<< P[i]+1<< " ";  
		
		///Mostrar una etiqueta de nodo incial en este caso -1 para sacarlo de la pila 
	}
	cout <<endl; 
	*/ 
}



/* 
CORRIDA DE ESCRITORIO
 	 Tengamos a D= 00 | 10| 00 | 30 |100
 	 
 	 Tnenemos 4 vertives (V) -> V= {1,2,3,4,5] 
 	 
 	 y tenenmos a s en F | F | F| F| F
 	 
 	 EMEPZAMOS CON S EN 1, ESTE SE MARCA EN VERDADERO Y AHORA s: 
 	 s en v | F | F| F| F
 	 
 	 al ser S=1  entonces 
 	 v-s = 2.3.4.5 
 	 
 	 de v-s se saca el menor (es dos en la matriz de costos) 
 	 
 	 entonces: }
 	 
 	 s =1,2 
 	 
 	 ahora queda 
 	 v-s= 3,4,5 
 	 
 	 
 	 


*/ 


 
