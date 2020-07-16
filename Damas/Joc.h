#pragma once

///////////////////////////////////////////////////////////////////////////
//Llibreria grafica
#include "lib/libreria.h"
///////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <conio.h>      /* getch */ 
#include <stdio.h>    
#include<windows.h>
/* time */

#include <stdlib.h>      /*rand*/
#include "Escenari.h"
#include "Menu.h"
#include "Enemics.h"
#include "Personatge.h"
#include "Moviment.h"
#include <vector>




//========================================================================
// Mida Pantalla
const int MIDAX = 1050;
const int MIDAY = 720;

//========================================================================
// Inici del taulell respecte la cantonada superior esquerre
const int INIPANTALLAX = 1;
const int INIPANTALLAY = 1;

//========================================================================
// Fi del taulell respecte la cantonada inferior dreta
const int FIPANTALLAX = 624;
const int FIPANTALLAY = 680;

const int MIDACASELLA = 30;

void joc(int opcio, int &puntuacio, int &vida,bool &trobat);

/*----- END --------------*/
const int Inici_X = 0;
const int Inici_Y = 0;
const int MUR_X = 1020;
const int MUR_Y = 600;
const int TAM_X = 30;
const int TAM_Y = 30;





