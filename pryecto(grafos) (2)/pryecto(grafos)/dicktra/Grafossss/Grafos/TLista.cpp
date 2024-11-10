#include "TLista.h"
 
 
TLista::TLista()
{
	cab= new TNodo(); 
	ultimo= cab->get_sig(); 
}
 
void TLista:: inserta_inicio(int dato)
{
	TNodo *p; 
	p= new TNodo (dato); 
	if(ultimo==NULL)
	{
	ultimo=p; 
	cab->set_sig(p); 
	}
	else
	{
		p->set_sig(cab->get_sig()); 
		cab->set_sig(p); 
	}
}
 
void TLista::mostrar_lista()
{
	TNodo *p; 
	
	if(p!=NULL)
	{
	p = cab->get_sig(); 
	while(p !=NULL)
	{
		cout << p->get_dato() << endl; 
		p = p->get_sig(); 
		}
		
	}else
	{
		cout << "ERROR!!!!, lista eliminada"<< endl; 
	}
		
		
}

void TLista::elimina_lista()
{
	TNodo *p; 
	p= cab;
	
	while(p!=NULL)
	{
		cab= cab->get_sig(); 
		delete p; 
		p=cab; 
		
	}
}


void TLista:: inserta_final(int dato)
{
	TNodo *p= new  TNodo (dato); 
	if(ultimo== NULL)
	{
		cab->set_sig(p); 
	}
	else
	{
		ultimo->set_sig(p); 
	}
	ultimo= p; 
}

void TLista::elimina_dato(int dato)
{
	TNodo *p= new TNodo(); 
	TNodo *q= new TNodo(); 
	q= cab; 
	p= cab->get_sig(); 
	
	while(p!= NULL && p->get_dato() != dato)
	{
		q=p; 
		p= p->get_sig();
	}
	
	q->set_sig(p->get_sig()); 
	delete p; 
	
	if(q->get_sig()== NULL)
	{
		ultimo = q; 
	}
}

void TLista::inserta_ordenado(int dato)
{
	TNodo *p = new TNodo(dato); 
	
	if(ultimo==NULL)
	{
		cab->set_sig(p); 
		//ultimo= p; 
	}
	else 
	{
		TNodo *actual = cab->get_sig(); 
		TNodo *anterior = cab; 
		
		while(actual != NULL && actual->get_dato()< dato)
		{
			//anterior = actual; 
			actual= actual->get_sig(); 
		}
		p->set_sig(actual); 
		anterior->set_sig(p); 
}
		ultimo = p; 	
	

}


int TLista::elimina_inicio()
{
	TNodo *p= cab->get_sig(); 
	TNodo *q=cab; 
	int dato= -2000000; 
	
	if (p!=NULL)
	{
		q->set_sig(p->get_sig()); 
		dato=p->get_dato(); 
	delete p; 
	}
	/*
	else 
	{ 
	cout << "la lista esta vacia" << endl; 
	}
	*/
	return dato; 
	
}
