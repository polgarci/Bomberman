#include <iostream>
#include <fstream>

using namespace std;
#pragma once
typedef struct
{
	string nombre="---------";
	int puntuacio=00000;
}Puntuacio;

void CargarRanking(Puntuacio Top10[]);
void GestionarPuntuacio(Puntuacio Top10[], int Punts);
void GuardarRanking(Puntuacio Top10[]);

void Menu();
//Apartir d'aqui aniran les funcions alternatives del menu, com es la dificultat i les puntuacions