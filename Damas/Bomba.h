#pragma once
#include "Joc.h"

using namespace std;




class Bomba
{
public:
	Bomba() { m_contador = 0; m_explota = false; m_duracio = false; m_contadorExplosio = 0; }
	int getBomba_i() const { return m_Bomb_i; } 
	int getBomba_j() const { return m_Bomb_j; } 
	void setBomba_i(const int &i)  { m_Bomb_i=i; }
	void setBomba_j(const int& j)  { m_Bomb_j=j; }
	int getContador() const { return m_contador; }
	bool getDuracio() const { return m_duracio; }
	void setContador(const int &contador) { m_contador = contador; }
	void setDuracio(const bool &duracio) { m_duracio = duracio; }
	int getExplosio() const { return m_explota; }
	void setExplocio(bool explota) { m_explota = explota; };
	void setContadorExplocio(const int &ContadorExplosio) { m_contadorExplosio = ContadorExplosio; }
	int getContadorExplocio()const { return m_contadorExplosio; }

private:
	int m_contador, m_contadorExplosio;
	int m_Bomb_i;
	int m_Bomb_j;
	bool m_explota,m_duracio;
	
	
};



class Node
{
public:
	Node() { m_Next = NULL; };
	Node *getNext() { return m_Next; }
	Bomba getActual() { return m_actual; }
	void setActual(Bomba &actual) { m_actual = actual; }
	void setNext(Node *next) { m_Next = next; }


private:
	Node*m_Next;
	Bomba m_actual;
};



class Cua
{
public:
	Cua() { m_Primer = NULL; m_Ultim = NULL; m_longitud = 0; };
	void afegeixBomba();
	void EliminarBomba();
	Node &getPrimer() { return *m_Primer; }
	Node &getUltim() { return *m_Ultim; }
	bool esBuida();
	int getsize() { return m_longitud; }
	
private:
	Node*m_Primer;
	Node*m_Ultim;
	int m_longitud;
};
