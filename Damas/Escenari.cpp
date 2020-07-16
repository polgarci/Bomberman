#include "Escenari.h"
#include "Joc.h"
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;
//0 indestructibles
//1 nada
//2 destructibles 
//3 enemigos
//4 personaje
//7 PowerUP
//10 Clau
// 20 bloc que conte la clau
// 17 bloc que conte el PowerUP
//15 porta
void Escenario::GenerarMatriu()
{
	srand(time(NULL()));
	int i;int enemigo;int j,clau;
	for (i = 0; i < N_Files; i++)
	{
		if (i % 2 == 0)
		{
			enemigo = 0;
		}
		for (j = 0; j < N_Columnes; j++)
		{
			if (i == 0 || j == 0 || i == N_Files - 1 || j == N_Columnes - 1)
			{
				m_matriu[i][j] = 0;
			}
			else
			{
				if (i % 2 == 0 && j % 2 == 0)
				{
					m_matriu[i][j] = 0;

				}
				else
				{
					if ((i == 1 && j == 2) || (i == 2 && j == 1))
					{
						m_matriu[i][j] = 1;
					}
					else
					{
						if (i == 1 && j == 1)
							m_matriu[i][j] = 4;
						else
						{
							if (m_matriu[i][j]!=20 && m_matriu[i][j]!=17) {
								if (enemigo < 1 && (N_Columnes / 3) < j)
								{
									m_matriu[i][j] = rand() % 3 + 1; if (m_matriu[i][j] == 3)enemigo++;
								}
								else
								{
									m_matriu[i][j] = rand() % 2 + 1;
								}
							}

						}
					}
				}
			}
		}

	}



}
void Escenario::InicialitzarClau() {
	srand(time(NULL()));
	int i, j,P_j,P_i;
	do {
		i = rand() % ((21-1)-3+1)+3; //rand()%((max-min+1)+min)
		j = rand() % ((35 - 1) - 3 + 1) + 3;
	} while ((i % 2== 0) && (j % 2 == 0));
	m_matriu[i][j] = 20;
	int numPowerUps = rand() % (5-1+1) + 1,cont=0;
	do {
		do
		{
			P_i = rand() % ((21 - 1) - 3 + 1) + 3;
			P_j = j = rand() % ((35 - 1) - 3 + 1) + 3;
			if (m_matriu[P_i][P_j] != 20)
			{
				cont++; m_matriu[P_i][P_j] = 17;
			}

		} while ((P_i % 2 == 0) && (P_j % 2 == 0));
	} while ( cont<numPowerUps);
}

void Escenario::PintarBlocs()
{
	Sprite blocDes, blocIn, clau,porta, PowerUP;
	int i, j;
	blocDes.create("data/pared_des.png");
	blocIn.create("data/pared_nodes.png");
	clau.create("data/Clau.png");
	porta.create("data/puerta.png");
	PowerUP.create("Bomba/power1.png");
	
	for (i = 0; i < N_Files;i++)
	{
		for (j = 0; j < N_Columnes; j++)
		{
			if (m_matriu[i][j] == 0)
			{

				blocIn.draw(j*blocDes.getScaleX(), i*blocDes.getScaleY());

			}
		}
	}
	for (i = 0; i < N_Files; i++)
	{
		for (j = 0; j < N_Columnes;j++)
		{
			if (m_matriu[i][j] == 2 || m_matriu[i][j] == 20 || m_matriu[i][j] == 17)
			{

				blocDes.draw(j*blocDes.getScaleX(), i*blocDes.getScaleY());

			}
			if (m_matriu[i][j] == 10)
			{

				clau.draw(j*clau.getScaleX(), i*clau.getScaleY());

			}
			if (m_matriu[i][j] == 7) {
				PowerUP.draw(j * PowerUP.getScaleX(), i * PowerUP.getScaleY());
			}
		}
	}

	if (m_matriu[1][1] == 15) {
		porta.draw(1 * porta.getScaleX(), 1 * porta.getScaleY());
	}
	

	

	
	
}

void Escenario::InicialitzarPosicio()
{
	int files, columnes, cont = 0;
	bool trobat = false;
	for (files = 0; files < N_Files;files++)
	{
		for (columnes = 0; columnes < N_Columnes; columnes++)
		{
			if (3 == m_matriu[files][columnes])
			{
				while (cont<10 && trobat!=true)
				{
					if (Enemy[cont].getVida()==1)
					{
						trobat = true;
						Enemy[cont].setPosicioE(files, columnes);
					}
					else
					cont++;
				}
				cont++;
				trobat = false;
				
			}
		}
	}




}
void Escenario::ReiniciarEnemics()// es reinicia la vida del 10 enemics a 1
{
	for (int i = 0; i < NumEnemics; i++)
	{
		Enemy[i].setVida(1);
	}
}
void Escenario::TractarEnemic()// aquesta funcio s'encarrega del moviment aleatori dels enemics
{
	int cont, i, j;
	srand(time(NULL));// es fa una crida a la funcio d'aleatoritat
	for (cont = 0; cont< NumEnemics; cont++)
	{
		if (Enemy[cont].getVida() == 1)// es comproba que la vida del enemic no sigui 0
		{


			Enemy[cont].getPosicioE(i, j);//s'agafa la posicio del enemic


			int Move = rand() % 4 + 1;//s'assigna un valor aleatori del 1 al 4 a la variable move
			int comprovacio;
			if (Move == 1)//Moviment cap a la dreta
			{
				j++;//s'incrementa j per moure la posicio dins la matriu cap a la dreta
				comprovacio = getPosicio(j, i);
				if (comprovacio == 1 || comprovacio == 4)// es comproba que a la posicio no hi hagi res o que estigui el personatge per poguer efectuar el moviment
				{
					setPosicio(j, i, 3);//es modifica la posicio i es fica el enemic
					PintarEnemic(j, i);//es pinta el enemic
					setPosicio(j - 1, i, 1);//es modifica la posicio on estava el enemic i es fica el valor que representa buit 
				}
				else {//si no es compleix la condicio es un decrement de j per desfe el increment del principi
					j--;PintarEnemic(j, i);
				}
			}
			if (Move == 2)//Moviment cap a la esquerra
			{
				j--;//es decrementa j per moure un posicio dins la matriu cap a l'esquerra
				comprovacio = getPosicio(j, i);
				if (comprovacio == 1 || comprovacio == 4)// es comproba que a la posicio no hi hagi res o que estigui el personatge per poguer efectuar el moviment
				{
					setPosicio(j, i, 3);//es modifica la posicio i es fica el valor que correspon al enemic
					PintarEnemic(j, i);// es pinta el sprite del enemic
					setPosicio(j + 1, i, 1);//es modifica la posicio on estava el enemic i es fica el valor que representa buit 
				}
				else
				{
					j++;//si no es compleix la condicio es un decrement de j per desfe el increment del principi
					PintarEnemic(j, i);
				}
			}
			if (Move == 3)//Moviment cap a la abaix
			{
				i++;// es fa un decrement de i per moure una posicio cap abaix en la matriu
				comprovacio = getPosicio(j, i);
				if (comprovacio == 1 || comprovacio == 4)// es comproba que a la posicio no hi hagi res o que estigui el personatge per poguer efectuar el moviment
				{
					setPosicio(j, i, 3);//es modifica la posicio i es fica el valor corresponent al enemic
					PintarEnemic(j, i);// es pinta el sprite del enemic
					setPosicio(j, i - 1, 1);//es modifica la posicio on estava el enemic i es fica el valor que representa buit 
				}
				else
				{//si no es compleix la condicio es un decrement de j per desfe el increment del principi
					i--;
					PintarEnemic(j, i);
				}
			}
			if (Move == 4)//Moviment cap adalt
			{
				i--;
				comprovacio = getPosicio(j, i);
				if (comprovacio == 1 || comprovacio == 4)// es comproba que a la posicio no hi hagi res o que estigui el personatge per poguer efectuar el moviment
				{
					setPosicio(j, i, 3);// es modifica la posicio i es fica el valor corresponent al enemic
					PintarEnemic(j, i);// es pinta el sprite del enemic
					setPosicio(j, i + 1, 1);//es modifica la posicio on estava el enemic i es fica el valor que representa buit 
				}
				else
				{//si no es compleix la condicio es un decrement de j per desfe el increment del principi
					i++;
					PintarEnemic(j, i);
				}
			}


			Enemy[cont].setPosicioE(i, j);/*despres d'haver efectuat les operacions anterior
										  es modifica la posicio del enemic nº "cont" */
		}
	}

}





void Escenario::PintarExplosions(int Bomb_i, int Bomb_j, int nivel)//es passa com la posicio on ha estat deixada la bomba
{

	Centre.draw(Bomb_j * 30, Bomb_i * 30);//a la posicio on ha estat deixada la bomba es dibuixa el sprite corresponent al centre de l'explosio


	if (getPosicio(Bomb_j - 1, Bomb_i) != 0)//es mira que la posicio a la esquerra del centre no sigui un bloc indestructible
	{
		for (int j = Bomb_j - 1; j > Bomb_j - (2 + nivel) && getPosicio(j, Bomb_i) != 0; j--) {/*es fa un recorregut a partir de la posicio anterior
																							   si compleix la condicio, i es va mirant si el bloc que estroba no sigui indestructible
																							   fins la posicio que es troba a dos posicions cap a l'esquerra del centre més el nivell
																							   ja que depenen del nivell les explosions tindran mes rang*/
			Lateral.draw(j * 30, (Bomb_i) * 30);//es dibuixa el sprite corresponent al lateral de l'explosio

		}
		if (getPosicio(Bomb_j - (2 + nivel), Bomb_i) != 0)//es mira que en el limit de l'explosio no hi hagi un bloc indestructible
			Esquerra.draw((Bomb_j - (2 + nivel)) * 30, Bomb_i * 30);//si es aixi es pinta el spirte corresponent al limit de l'explosio esquerra
	}

	if (getPosicio(Bomb_j + 1, Bomb_i) != 0)//es mira que la posicio a la dreta del centre no hi hagi un bloc indestructible
	{
		for (int j = Bomb_j + 1; j < Bomb_j + (2 + nivel) && getPosicio(j, Bomb_i) != 0; j++) {/*es fa un recorregut a partir de la posicio anterior
																							   si compleix la condicio, i es va mirant si el bloc que estroba no sigui indestructible
																							   fins la posicio que es troba a dos posicions cap a la dreta del centre més el nivell
																							   ja que depenen del nivell les explosions tindran mes rang*/
			Lateral.draw(j * 30, (Bomb_i) * 30);//es dibuixa el sprite corresponent al lateral de l'explosio

		}
		if (getPosicio(Bomb_j + (2 + nivel), Bomb_i) != 0)//es comproba que en el limit dret de l'explosio no hi hagi un bloc indestructible
			Dreta.draw((Bomb_j + (2 + nivel)) * 30, Bomb_i * 30);//si es aixi el pinta el sprite corresponent al limit de l'explosio dreta
	}

	if (getPosicio(Bomb_j, Bomb_i + 1) != 0)//es comprobar que en la posicio inferior al centre no hi hagi un bloc indestructible
	{
		for (int i = Bomb_i + 1; i < Bomb_i + (2 + nivel) && getPosicio(Bomb_j, i) != 0;i++) {/*es fa un recorregut a partir de la posicio anterior
																							  si compleix la condicio, i es va mirant si el bloc que es troba no sigui indestructible
																							  fins la posicio que es troba a dos posicions inferior respecte del centre més el nivell
																							  ja que depenen del nivell les explosions tindran mes rang*/
			Vertical.draw(Bomb_j * 30, i * 30);//es pinta el sprite corresponent al vertical de l'explosio

		}
		if (getPosicio(Bomb_j, Bomb_i + (2 + nivel)) != 0)//es comproba que en el limit inferior de l'explosio no hi hagi un bloc indestrucitible
			Inferior.draw(Bomb_j * 30, (Bomb_i + (2 + nivel)) * 30);// si es compleix la condicio es dibuixara el sprite del limit inferior de l'explosio
	}
	if (getPosicio(Bomb_j, Bomb_i - 1) != 0)//es comproba que en la posicio superior al centre no hi hagi un bloc indestructible
	{
		for (int i = Bomb_i - 1; i > Bomb_i - (2 + nivel) && getPosicio(Bomb_j, i) != 0; i--) {/*es fa un recorregut a partir de la posicio anterior
																							   si compleix la condicio, i es va mirant si el bloc que es troba no sigui indestructible
																							   fins la posicio que es troba a dos posicions superior respecte del centre més el nivell
																							   ja que depenen del nivell les explosions tindran mes rang*/
			Vertical.draw(Bomb_j * 30, i * 30);//es pinta el sprite corresponent al vertical de l'explosio

		}
		if (getPosicio(Bomb_j, Bomb_i - (2 + nivel)) != 0)// es comproba que el limit superior de l'explosio no hi hagi un bloc indestructible
			Superior.draw(Bomb_j * 30, (Bomb_i - (2 + nivel)) * 30);// si es aixi es pinta el sprite corresponent al limit superior de l'explosio
	}

}

void Escenario::GuardarPartida(const int &nivel, const string& fitxer)// en aquesta funcio es guarda el estat d'una partida
{

	ofstream file;//fitxer mode escriptura
	file.open(fitxer);

	if (file.is_open())
	{
		file << nivel << endl;;//es guarda el nivell
		for (int i = 0; i < NumEnemics; i++)
		{
			file << Enemy[i].getVida() << " ";//els enemics que hi han
		}
		file << endl;
		for (int i = 0;N_Files > i;i++)
		{
			for (int j = 0;j < N_Columnes;j++)
			{
				file << m_matriu[i][j] << " ";//i es guarda la matriu sencera
			}
			file << endl;
		}


		file.close();
	}
}

bool Escenario::CarregarPartida(int &nivel, const string& fiter)//aquesta funcio s'encarrega de carregar el estat d'una partida
{

	ifstream fitxer;//fitxer mode lectura
	int valor;
	fitxer.open(fiter);
	char comprobant;
	if (fitxer.is_open())
	{

		fitxer >> nivel;
		while (!fitxer.eof())
		{


			for (int m = 0; m < NumEnemics; m++)
			{
				fitxer >> valor;
				Enemy[m].setVida(valor);//es llegeix la vida dels enemics de manera que es sabra quins enemics encara continuaven a la partida


			}
			for (int i = 0; i < N_Files; i++)
			{
				for (int j = 0; j < N_Columnes; j++)
				{
					fitxer >> m_matriu[i][j];//i es llegeix tots els valors de la matriu per poder restaura el estat de la partida

				}

			}


		}
		fitxer.close();

	}
	else return false;
	return true;
}
void Escenario::PintarPersonatge(int j, int i)//es pinta un sprite o un altre segons la tecla polsada
{
	if (m_pw == true && m_ps == false && m_pd == false && m_pa == false) {
		S_Persoar.draw(j * 30, i * 30);
	}
	if (m_pw == false && m_ps == true && m_pd == false && m_pa == false) {
		S_Perso.draw(j * 30, i * 30);
	}
	if (m_pw == false && m_ps == false && m_pd == true && m_pa == false) {
		S_Persode.draw(j * 30, i * 30);
	}
	if (m_pw == false && m_ps == false && m_pd == false && m_pa == true) {
		S_Persoiz.draw(j * 30, i * 30);
	}
	if (m_pw == false && m_ps == false && m_pd == false && m_pa == false) {
		S_Perso.draw(j * 30, i * 30);
	}
}



	
