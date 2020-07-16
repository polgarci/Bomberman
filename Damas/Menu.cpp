#include"Menu.h"

#include <string>
using namespace std;

#include"Menu.h"

#include <string>
using namespace std;

void Menu()
{
	cout << "----------Menu----------" << endl;
	cout << "1. Jugar" << endl;
	cout << "2. Carregar Partida" << endl;
	cout << "3. Puntuacions" << endl;
	cout << "4. Reproduir partida" << endl;
	cout << "5. Sortir" << endl;


}

void GuardarRanking(Puntuacio Top10[])//s'encarrega de guardar les 10 millors puntuacions
{
	ofstream file;//es declara un fitxer en mode escriptura
	file.open("Puntuacions.txt");//s'obre el fitxer on es guardaran les puntuacions

	if (file.is_open())
	{
		for (int i = 0; i < 10; i++)
			file << Top10[i].nombre << " " << Top10[i].puntuacio << endl;//es fa un recorregut del array top10 i es guarda cada puntuacio en una linea del fitxer
		file.close();
	}


}

void CargarRanking(Puntuacio Top10[])
{
	ifstream file;//es declara el fitxer en mode lectura
	file.open("Puntuacions.txt");//s'obre el fitxer on estan guardades les puntuacions

	if (file.is_open())
	{
		if (!file.eof())
		{
			for (int i = 0; i < 10; i++)
				file >> Top10[i].nombre >> Top10[i].puntuacio;/*es fa una lectura de les puntuacions i es guarden al array TOP
															  10 per despres mostrarse per pantalla*/
		}
		file.close();
	}


}


void GestionarPuntuacio(Puntuacio Top10[], int Punts)/*Aquesta funcio s'encarrega de gestionar les puntuacions
													 de manera que nomes quedin les 10 millors*/
{
	int i = 0;
	bool trobat = false;

	while (i < 10 && trobat != true)
	{
		if (Punts > Top10[i].puntuacio)/*es comproba si la puntuacio donada es mes gran respecte la que esta guardada en el array
									   en la posicio i*/
		{
			for (int j = 9; j > i; j--)/*es fa el recorregut del array top 10 començant per l'ultim element ja que
									   el array guarda les puntuacions de manera descendent fins arribar al index i
									   que correspon a la posicio on la puntuacio ha estat mes gran a la donada,
									   i es van desplaçant les puntuacions fins eliminar la menor puntuacio*/
			{
				Top10[j].nombre = Top10[j - 1].nombre;
				Top10[j].puntuacio = Top10[j - 1].puntuacio;
			}
			cout << " La teva puntuacio es : " << Punts << endl;
			Top10[i].puntuacio = Punts;//es guarda la puntuacio donada a la posicio que li pertoca
			cout << " Escriu el teu nom d'usuari: "; cin >> Top10[i].nombre;//i el nom tambe
			trobat = true;//el boolea trobat s'assigna true per sortir del bucle
		}
		else i++;
	}
	GuardarRanking(Top10);//es crida a la funcio guardarRanking per guardar el top10 actualitzat en el fitxer

}