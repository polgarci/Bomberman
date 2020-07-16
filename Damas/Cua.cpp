#include "Cua.h"

using namespace std;






void Cua::afegeixBomba()
{ 
	Node *seguent; 
	seguent = new Node;
	if(esBuida()==true)
	{
		m_Primer = seguent;
		m_Ultim = seguent;
	}
	else 
	{
		m_Ultim->setNext(seguent);
		m_Ultim = seguent;
	}
	m_longitud++;
}

void Cua::EliminarBomba()
{
	Node aux;
	aux = *m_Primer->getNext();
	delete m_Primer;
	*m_Primer = aux;
	m_longitud--;
}
bool Cua::esBuida()
{
	if (m_Primer==NULL && m_Ultim==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}




}