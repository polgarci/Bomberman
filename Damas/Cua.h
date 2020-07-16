#include"Bomba.h"

using namespace std;
class Node
{
public:
	Node();
	Node *getNext() { return m_Next; }
	Bomba getActual() { return m_actual; }
	void setActual(Bomba &actual) { m_actual = actual;}
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
	~Cua() { delete[] m_Primer; delete[] m_Ultim; };

private:
	Node*m_Primer;
	Node*m_Ultim;
	int m_longitud;
};


