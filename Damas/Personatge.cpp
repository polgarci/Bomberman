#include "Joc.h"

using namespace std;

void Jugador::GuardarPersonaje()//guarda els stats del personatge
{
	ofstream fitxer;
	fitxer.open("DadesPersonatje.txt");

	if (fitxer.is_open())
	{


		fitxer << m_vidas << " " << m_i << " " << m_j << " " << m_puntuacio <<" "<< m_NumBombes << endl;//es guarden la posicio, la puntuacio i les vides

		fitxer.close();
	}
}
void Jugador::CargarPersonaje()//carrega els stats del personatge
{

	ifstream fitxer;
	fitxer.open("DadesPersonatje.txt");

	if (fitxer.is_open())
	{
		fitxer >> m_vidas;//carrega la puntucio
		while (!fitxer.eof())
		{

			fitxer >> m_i;//les posicions
			fitxer >> m_j;
			fitxer >> m_puntuacio;//la puntuacio
			fitxer >> m_NumBombes;
		}
		fitxer.close();
	}



}