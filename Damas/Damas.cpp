//Definicio necesaria per poder incloure la llibreria i que trobi el main
#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;
#define SDL_MAIN_HANDLED

#include <windows.h>
#include "Joc.h" //Aquest inclou llibreria grafica
#include <conio.h>      /* getch */ 


//Arguments necesaris per poder incloure la llibreria i que trobi el main
void main(int argc, char* argv[])
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	
	Puntuacio Top10[10];
	int puntuacio = NULL, vidas = NULL;
	///////////////////////////////////////////////////////////////////////////
	char valore,valor='o';
	bool trobat;
	do
	{
		
		system("cls");
		Menu();cout << endl;
		cin >> valore;
		switch (valore)
		{
		case '1': {joc(1, puntuacio, vidas,trobat); system("cls");
			if (puntuacio != NULL)
			{
				int Punts = puntuacio + (10 * vidas);CargarRanking(Top10); GestionarPuntuacio(Top10, Punts);
			}
				
		}break;
		case '2':  joc(3, puntuacio, vidas,trobat); system("cls");
			if (puntuacio != NULL&&trobat!=false)
			{
				int Punts = puntuacio + (10 * vidas);
				CargarRanking(Top10); GestionarPuntuacio(Top10, Punts);
			}
			if(trobat==false) { cout << "Error: No hi ha cap partida guardada" << endl; system("pause"); }
			
			break;
		case '3': system("cls"); CargarRanking(Top10); 
			cout << " ------------Puntuacions------------" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << "         " << Top10[i].nombre << " ---- " << Top10[i].puntuacio << endl;
			}
			;system("pause");break;
		case '4': system("cls"); joc(4, puntuacio, vidas, trobat); system("cls");if (trobat == false) { cout << "Error: Repeticio inexistent" << endl;}
	             system("pause");break;
		case '5': system("cls"); cout << "Estas segur de sortir?(Sortir-S    Continuar-Prem qualsevol tecla)";cout << endl; cin >> valor;break;
 
		}
		valore = NULL;
	} while (valor!='S' && valor!= 's');
	


	//Instruccio necesaria per poder incloure la llibreria i que trobi el main
	SDL_Quit();
	///////////////////////////////////////////////////////////////////////////

}

