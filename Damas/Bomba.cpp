#pragma once
#include "Bomba.h"

using namespace std;


void Cua::afegeixBomba()//aquesta funcio s'encarrega de afegir una bomba a la cua
{
	Node *seguent;//es declar un node següent
	seguent = new Node;//es declara com a nou
	if (esBuida() == true)/*es comproba si la cua esta buida
						  si es aixi s'assigna m_primer i m_ultim a seguent ja que nomes hi haura
						  un element a la cua*/
	{
		m_Primer = seguent;
		m_Ultim = seguent;
	}
	else//si ja hi ha un element a la cua
	{
		m_Ultim->setNext(seguent);//m_ultim es cambia a següent que es el nou node
		m_Ultim = seguent;//m_ultim s'aasigna a seguent
		m_Ultim->setNext(NULL);//m_ultim es canvia i apuntara a una direccio de memoria buida
	}
	m_longitud++;//s'incrementa la longitud de la cua
}

void Cua::EliminarBomba()//s'encarrega d'eliminar una bomba de la cua
{

	if (m_longitud>1)//es comproba que la longitud sigui mes gran que 1
	{
		Node aux;//es declara un node auxiliar
		aux = *m_Primer->getNext();//assignem el auxiliar al següent del elemnet primer que es el que s'eliminara
		*m_Primer = aux;//assignem el auxiliar al m_primer per que aixi el primer element apunti al següent
		m_longitud--;//es redueix la dimensio de la cua
	}
	else
	{//si nomes hi ha un element a la cua

		m_Primer = NULL;//s'assigna m_primer a NULL
		m_Ultim = NULL;//s'assigna m_ultim a NULL

		m_longitud--;//es redueix la dimensio de la cua i queda buida
	}

}
bool Cua::esBuida()// aquesta funcio comproba si la cua es buida retorn true si ho esta i false si no ho esta
{
	if (m_Primer == NULL && m_Ultim == NULL)//es comproba que m_primer i m_ultim no apunti a cap direccio de memoria
	{
		return true;
	}
	else
	{
		return false;
	}




}