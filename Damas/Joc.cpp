#include "Joc.h"

#include "Bomba.h"
#define TECLA_ESTESA 224


///-------------------DESTRUCCIO NOMES DE BLOCS CAP ABAIX----------------//
void DestruccioBlocsAbaix(int i, int j, Escenario &mapa, Jugador &Personatje, const int &nivel) {
	int i_RadioBomba, Ene_i, Ene_j, cont = 0, puntuacio = Personatje.getPuntuacio();
	bool trobat = false;
	int resultat = mapa.getPosicio(j, i);
	for (i_RadioBomba = i; i_RadioBomba <= i + (2 + nivel) && resultat != 0; i_RadioBomba++)
	{
		resultat = mapa.getPosicio(j, i_RadioBomba);
		if (resultat == 2) {//destruccio dels blocs
			puntuacio = Personatje.getPuntuacio();//s'agafa la puntuacio
			puntuacio += (1 * nivel);//s'incrementa la puntuacio cada cop que es destrueix un bloc
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j, i_RadioBomba, 1);//s'esborra el bloc del mapa
			
		}
		if (resultat == 3) {//destruccio enemics
			puntuacio = Personatje.getPuntuacio();//s'agafa la puntuacio
			puntuacio += (2 * nivel);//s'incrementa la puntuacio el doble respecte al blocs i depen del nivell
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j, i_RadioBomba, 1);//es cambia el valor de la posicio en la matriu
			while (cont<10 && trobat != true)/*s'anira comprovant quin dels 10 enemics es el que es troba dins el rang de la bomba
											 i si es troba que s'inicialitza amb un boolea a false*/
			{
				mapa.getPosicio1(Ene_i, Ene_j, cont);

				if (Ene_i == i_RadioBomba && Ene_j == j) {//es mira que el enemic estigui en el rang de la bomba
					trobat = true;//si es aixi es modifica el boolea
					mapa.EliminarEnemy(cont);//i s'elimina el enemic corresponent marcat amb un index que es el cont
				}
				else
				{
					cont++;//si no es compleix les condicions es passa al següent enemic
				}
			}
			trobat = false;
		}
		if (resultat == 4) {//destruccio del personatge
			mapa.setPosicio(j, i_RadioBomba, 1);//si es compleix la condicio anterior es modifica el valor de la posicio per esborrar el personatge
			int vidas = Personatje.getVidas();//s'agafa les vides del personatge
			Personatje.setVidas(vidas - 1);//es resta una vida
			mapa.setPosicio(1, 1, 4);//es modifica la matriu per inicialitzar el personatge al punt d'inici 1,1
			Personatje.setPosicioP(1, 1);//es modifica la posicio del personatge
		}
		if (resultat == 20) {/*si el resultat es igual a 20 es modifica la matriu i es fica un 10 a la posicio
							 que marcara a on es dibuixara la clau*/
			mapa.setPosicio(j, i_RadioBomba, 10);
		}
		if (resultat == 17) {/*si el resultat es igual a 17 es modifica la matriu i es fica un 7 a la posicio
							  que marcara a on es dibuixara el power up*/
			mapa.setPosicio(j, i_RadioBomba, 7);
		}
	}
}


//-------------------DESTRUCCIO NOMES DE BLOCS CAP ADALT----------------//
void DestruccioBlocsAdalt(int i, int j, Escenario &mapa, Jugador &Personatje, const int &nivel) {
	int i_RadioBomba, Ene_i, Ene_j, cont = 0, puntuacio = Personatje.getPuntuacio();
	bool trobat = false;
	int resultat = mapa.getPosicio(j, i);
	for (i_RadioBomba = i; i_RadioBomba >= i - (2 + nivel) && resultat != 0; i_RadioBomba--) {
		resultat = mapa.getPosicio(j, i_RadioBomba);
		if (resultat == 2) {//destruccio dels blocs
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (1 * nivel);
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j, i_RadioBomba, 1);
		}
		if (resultat == 20) {//si el resultat es 20
			mapa.setPosicio(j, i_RadioBomba, 10);//es modifica el valor a la posicio per dibuixar la clau

		}
		if (resultat == 17) {/*si el resultat es igual a 17 es modifica la matriu i es fica un 7 a la posicio
							 que marcara a on es dibuixara el power up*/
			mapa.setPosicio(j, i_RadioBomba, 7);
		}
		if (resultat == 3) {//destruccio dels enemics
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (2 * nivel);
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j, i_RadioBomba, 1);
			while (cont<10 && trobat != true)//es va mirant quin es l'enemic afectat per l'explosio
			{
				mapa.getPosicio1(Ene_i, Ene_j, cont);

				if (Ene_i == i_RadioBomba && Ene_j == j) {//si la posicio del enemic "cont" esta dins del rang de la bomba 
					trobat = true;//el boolea es passa true i es surt del bucle
					mapa.EliminarEnemy(cont);//i s'elimina el enemic que pertoca
				}
				else
				{
					cont++;
				}
			}
			trobat = false;
		}
		if (resultat == 4)//destruccio del personatge
		{
			mapa.setPosicio(j, i_RadioBomba, 1);//es canvia el valor de la posicio per esborrar el personatge
			int vidas = Personatje.getVidas();
			Personatje.setVidas(vidas - 1);//es resta la vida al personatge
			mapa.setPosicio(1, 1, 4);//es canvia el valor de la posicio inicial per dibuixar el personatge
			Personatje.setPosicioP(1, 1);//es canvia la posicio del personatge a la inicial

		}
	}

}
//-------------------DESTRUCCIO NOMES DE BLOCS CAP A LA ESQUERRA----------------//
void DestruccioBlocsEsquerra(int i, int j, Escenario &mapa, Jugador &Personatje, const int &nivel) {
	int j_RadiBomba, Ene_i, Ene_j, cont = 0, puntuacio = Personatje.getPuntuacio();
	bool trobat = false;
	int resultat = mapa.getPosicio(j, i);
	for (j_RadiBomba = j; j_RadiBomba >= j - (2 + nivel) && resultat != 0; j_RadiBomba--)
	{
		resultat = mapa.getPosicio(j_RadiBomba, i);
		if (resultat == 2) {//destruccio de blocs
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (1 * nivel);//s'incrementa la puntuacio
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j_RadiBomba, i, 1);
		}
		if (resultat == 20) {//si el resultat es igual a 20
			mapa.setPosicio(j_RadiBomba, i, 10);//es canvia el valor a la posicio per el valor que correspon a la clau
		}
		if (resultat == 17) {/*si el resultat es igual a 17 es modifica la matriu i es fica un 7 a la posicio
							 que marcara a on es dibuixara el power up*/
			mapa.setPosicio(j_RadiBomba, i, 7);
		}
		if (resultat == 3)//destruccio dels enemics
		{
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (2 * nivel);//s'incrementa la puntuacio
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j_RadiBomba, i, 1);
			while (cont<10 && trobat != true)//es va mirant quin es l'enemic afectat per la bomba
			{
				mapa.getPosicio1(Ene_i, Ene_j, cont);

				if (Ene_i == i && Ene_j == j_RadiBomba) {/*si el enemic que es tracta esta dins el rang de
														 la bomba el boolea passa a true per su¡ortir del bucle i
														 s'elimina el enemic nº "cont"*/
					trobat = true;
					mapa.EliminarEnemy(cont);
				}
				else
				{
					cont++;
				}
				

			}
			trobat = false;
		}
		if (resultat == 4)//destruccio del personatge
		{
			mapa.setPosicio(j_RadiBomba, i, 1);//es canvia el valor de la posicio per esborrar el personatge
			int vidas = Personatje.getVidas();
			Personatje.setVidas(vidas - 1);//es resta una vida
			mapa.setPosicio(1, 1, 4);//es canvia el valor a la posicio 1,1 per poder pintar el personatge
			Personatje.setPosicioP(1, 1);//es canvia la posicio del personatge a la posicio inicial

		}
	}

}

//-------------------DESTRUCCIO NOMES DE BLOCS CAP A LA DRETA----------------//
void DestruccioBlocsDreta(int i, int j, Escenario &mapa, Jugador &Personatje, const int &nivel) {
	int j_RadiBomba, Ene_i, Ene_j, cont = 0, puntuacio = Personatje.getPuntuacio();
	bool trobat = false;
	int resultat = mapa.getPosicio(j, i);
	for (j_RadiBomba = j; j_RadiBomba <= j + (2 + nivel) && resultat != 0; j_RadiBomba++) {
		resultat = mapa.getPosicio(j_RadiBomba, i);
		if (resultat == 2) {//destruccio de blocs
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (1 * nivel);//s'incrementa la puntuacio
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j_RadiBomba, i, 1);
		

		}
		if (resultat == 20) {//si el resultat es igual a 20
			mapa.setPosicio(j_RadiBomba, i, 10);//es canvia el valor de la posicio per el valor que correspon al de la clau per poder pintar 
		}
		if (resultat == 17) {/*si el resultat es igual a 17 es modifica la matriu i es fica un 7 a la posicio
							 que marcara a on es dibuixara el power up*/
			mapa.setPosicio(j_RadiBomba, i, 7);
		}
		if (resultat == 3)//destruccio d'enemics
		{
			puntuacio = Personatje.getPuntuacio();
			puntuacio += (2 * nivel);//s'incrementa la puntuacio
			Personatje.setPuntuacio(puntuacio);
			mapa.setPosicio(j_RadiBomba, i, 1);
			while (cont<10 && trobat != true)/*es va mirant quin es el enemic que
											 es troba dins del rang de l'explosio*/
			{
				mapa.getPosicio1(Ene_i, Ene_j, cont);

				if (Ene_i == i && Ene_j == j_RadiBomba) {/*si el enemic "cont" esta dins del rang
														 de la bomba el boolea passa a true per sortir del bucle
														 i es fa la crida per eliminar al enemic*/
					trobat = true;
					mapa.EliminarEnemy(cont);
				}
				else
				{
					cont++;
				}
			}
			trobat = false;
		}
		if (resultat == 4)//destruccio del personatge
		{
			mapa.setPosicio(j_RadiBomba, i, 1);//es canvia el valor de la posicio per poder borrar el personatge
			int vidas = Personatje.getVidas();
			Personatje.setVidas(vidas - 1);//es resta una vida al personatge
			mapa.setPosicio(1, 1, 4);//es canvia el valor de la posicio inicial al valor corresponent a personatge
			Personatje.setPosicioP(1, 1);//es canvia la posicio del personatge a la inicial

		}
	}

}void ContadorBomba(Escenario &mapa, vector<Bomba> &Bomb, Jugador &Personatje, const int &nivel, const int &opcio, Cua &BombesExtra) {
	int index;
	//s'agafa el tamany del array dinamic que te el numero de powerups agafats
	Personatje.setNumBombes(Bomb.size()+BombesExtra.getsize());
	int numbombes = Bomb.size();
	for (index = 0; index < numbombes; index++)/*es mira que el index sigui menor a numbombes ja que
											   aquestes bombes que es tracten son les que venen donades per
											   defecte i son 2*/
	{

		int j = Bomb[index].getBomba_j();
		int i = Bomb[index].getBomba_i();


		if (Bomb[index].getDuracio() == true)/*si la duracio es igual a true
											 que aquest atribut s'ha modificat en comprobarSpace*/
		{
			Personatje.setNumBombes(Personatje.getNumBombes() - 1);
			int contador = Bomb[index].getContador();//s'agafa el contador
			Bomb[index].setContador(contador + 1);//i es va incrementant
			mapa.PintarBomba(j, i);//mentres el contador sigui menor a 400 es pintaran les bombes que es el temps que triguen a explotar
			if (contador >= 400)//quan el contador es mes gran a 400 es destrueixen els blocs i  es canvia Explosio a true
			{
				DestruccioBlocsAbaix(i, j, mapa, Personatje, nivel);
				DestruccioBlocsAdalt(i, j, mapa, Personatje, nivel);
				DestruccioBlocsEsquerra(i, j, mapa, Personatje, nivel);
				DestruccioBlocsDreta(i, j, mapa, Personatje, nivel);

				Bomb[index].setExplocio(true);


			}

		}
		if (Bomb[index].getExplosio() == true)//quan la Explosio de la bomba "Index" es true
		{
			int contador = Bomb[index].getContador();//s'agafa el contador


			if (contador <= 550)//i mentres sigui menor a 550 es pintaran les explosions
			{
				mapa.PintarExplosions(i, j, nivel);
			}
			else
			{//quan el contador es mes gran a 550
				Bomb[index].setExplocio(false);//es modifiquen els atribut per finalitzar la explosio
				Bomb[index].setDuracio(false);
				contador = 0;
				Bomb[index].setContador(contador);

				if (numbombes>2)//si el index es major a 2 s'inicialitzara l'explosio de les bombes extres en primer lloc
				{
					Bomb.pop_back();//s'eliminara el ultim element del array dinamic
					Bomb.resize(numbombes-1);//es redimensionara el array dinamic amb un element menys
					numbombes = Bomb.size();//numbombes extres sera igual a al tamany del array dinamic de bombes
				}
			}
		}

	}


}
//Comprovacio del xoc del jugador amb enemic
bool ComprovacioXoc(Jugador &Personaje, Escenario &mapa)
{
	int i, j, vida;

	Personaje.getPosicioP(i, j);

	if (mapa.getPosicio(j, i) == 3)
	{
		Personaje.setPosicioP(1, 1);
		vida = Personaje.getVidas();
		Personaje.setVidas(vida - 1);
		return true;
	}
	else
	{
		return false;
	}

}
//Moviment del Personatge
void MovimentPersonatge(int &j, int &i, Escenario &mapa, Jugador &Personaje, Moviment &Mov, const int &tecla, Cua &BombesExtra, const int &opcio)
{
	bool premut = false;
	bool pw = false, ps = false, pa = false, pd = false;
	//Moviment cap abaix
	if ((opcio!=4 &&(Keyboard_GetKeyTrg(KEYBOARD_DOWN) || Keyboard_GetKeyTrg(KEYBOARD_S) || Keyboard_GetKeyTrg(KEYBOARD_s))) || (opcio==4 && (tecla == KEYBOARD_DOWN)))
	{

		int resultat;

		if (ComprovacioXoc(Personaje, mapa) == false)//es comproba que el personatge no s'hagi xocat amb cap enemic
		{

			i++;
			resultat = mapa.getPosicio(j, i);
			if (resultat == 1 || resultat == 3 || resultat == 10 || resultat == 15 || resultat == 7)//comprovem si tenim espai buit ,enemic,clau o powerup
			{
				premut = true;//el boolea passa true
				Mov.GuardarTecla(KEYBOARD_DOWN);//es crida a la funcia guardar tecla
				if (resultat == 3)//si la posicio nova te valor igual 3 vol dir que hi ha un enemic
				{
					mapa.setPosicio(1, 1, 4);//es canvia la posicio del personatge a la posicio inicial 1,1
					mapa.setPosicio(j, i - 1, 1);//i la posicio on estava el personatge queda lliure amb un 1
				}

				else if (resultat == 1)//si el resultat es 1 vol dir que no hi ha res i el moviment s'efectua sense cap problema
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i - 1, 1);
					ps = true;//es posa la variable de polsar abaix en true per a comprobació a l'hora de pintar
				}
				else if (resultat == 10)//si el resulat es 10 vol dir que esta la clau
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i - 1, 1);
					Personaje.setagafat(true);// de manera que el personatge agafa la clau i es canvia el atribut agafat per que aixi pugui apareixer la porta
					ps = true;
				}
				else if (resultat == 7) {//si el resultat es 7 vol dir que s'ha agafat un powerup
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i - 1, 1);
					BombesExtra.afegeixBomba();//s'afageix una bomba extra a la cua 
					ps = true;
				}
				else {//si no es compleix cap condicio anterior vol dir que el personatge esta a la porta i passara al següent nivell
					  //modificant el atribut pasat a true
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i - 1, 1);
					Personaje.setpasat(true);
				}
				mapa.setpa(pa);//es pasen tots les variables de comprobació de la polsació a les variables de polsació de la clase escenari
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
			}

			else
			{
				ps = true;
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
				i--;
			}
		}
	}//Moviment cap a la dreta
	if ((opcio!=4 && (Keyboard_GetKeyTrg(KEYBOARD_RIGHT) || Keyboard_GetKeyTrg(KEYBOARD_d) || Keyboard_GetKeyTrg(KEYBOARD_D))) || (opcio==4 && tecla == KEYBOARD_RIGHT))
	{
		int resultat;



		if (ComprovacioXoc(Personaje, mapa) == false)
		{

			j++;
			resultat = mapa.getPosicio(j, i);
			if (resultat == 1 || resultat == 3 || resultat == 10 || resultat == 15 || resultat == 7)//comprovem si tenim espai buit ,enemic,clau o powerup
			{
				premut = true;
				Mov.GuardarTecla(KEYBOARD_RIGHT);
				if (resultat == 3)
				{
					mapa.setPosicio(1, 1, 4);
					mapa.setPosicio(j - 1, i, 1);
				}
				else if (resultat == 1)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j - 1, i, 1);
					pd = true;
				}
				else if (resultat == 10)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j - 1, i, 1);
					Personaje.setagafat(true);
					pd = true;
				}
				else if (resultat == 7) {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j - 1, i, 1);
					BombesExtra.afegeixBomba();
					pd = true;
				}
				else {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j - 1, i, 1);
					Personaje.setpasat(true);
				}
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
			}

			else
			{
				pd = true;
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
				j--;
			}
		}
	}//Moviment cap adalt
	if ((opcio != 4 && (Keyboard_GetKeyTrg(KEYBOARD_UP) || Keyboard_GetKeyTrg(KEYBOARD_w) || Keyboard_GetKeyTrg(KEYBOARD_W))) || (opcio == 4 && tecla == KEYBOARD_UP))
	{
		int resultat;


		if (ComprovacioXoc(Personaje, mapa) == false)
		{


			i--;
			resultat = mapa.getPosicio(j, i);
			if (resultat == 1 || resultat == 3 || resultat == 10 || resultat == 15 || resultat == 7)//comprovem si tenim espai buit ,enemic o clau
			{
				premut = true;
				Mov.GuardarTecla(KEYBOARD_UP);
				if (resultat == 3)
				{
					mapa.setPosicio(1, 1, 4);
					mapa.setPosicio(j, i + 1, 1);
				}
				else if (resultat == 1)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i + 1, 1);
					pw = true;
				}
				else if (resultat == 10)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i + 1, 1);
					Personaje.setagafat(true);
					pw = true;
				}
				else if (resultat == 7) {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i + 1, 1);
					BombesExtra.afegeixBomba();
					pw = true;

				}
				else {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j, i + 1, 1);
					Personaje.setpasat(true);
				}
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
			}


			else
			{
				pw = true;
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
				i++;
			}
		}
	}//Moviment cap a l'esquerra
	if ((opcio != 4 && (Keyboard_GetKeyTrg(KEYBOARD_LEFT) || Keyboard_GetKeyTrg(KEYBOARD_a) || Keyboard_GetKeyTrg(KEYBOARD_A))) ||( opcio == 4 && tecla == KEYBOARD_LEFT))
	{
		int resultat;

		if (ComprovacioXoc(Personaje, mapa) == false)
		{

			j--;
			resultat = mapa.getPosicio(j, i);
			if (resultat == 1 || resultat == 3 || resultat == 10 || resultat == 15 || resultat == 7)//comprovem si tenim espai buit ,enemic o clau
			{
				premut = true;
				Mov.GuardarTecla(KEYBOARD_LEFT);
				if (resultat == 3)
				{
					mapa.setPosicio(1, 1, 4);
					mapa.setPosicio(j + 1, i, 1);
				}
				else if (resultat == 1)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j + 1, i, 1);
					pa = true;
				}
				else if (resultat == 10)
				{
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j + 1, i, 1);
					Personaje.setagafat(true);
					pa = true;
				}
				else if (resultat == 7) {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j + 1, i, 1);
					BombesExtra.afegeixBomba();
					pa = true;
				}
				else {
					mapa.setPosicio(j, i, 4);
					mapa.setPosicio(j + 1, i, 1);
					Personaje.setpasat(true);
				}
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);

			}

			else
			{
				j++;
				pa = true;
				mapa.setpa(pa);
				mapa.setpd(pd);
				mapa.setps(ps);
				mapa.setpw(pw);
			}
		}
	}


	if ((opcio != 4 && Keyboard_GetKeyTrg(KEYBOARD_SPACE)) || (opcio == 4 && tecla == KEYBOARD_SPACE))//Comprobem que hem polsat l'espai
	{
		Mov.GuardarTecla(KEYBOARD_SPACE); //es crida a la funció guardar tecla
		mapa.getPosicio(j, i);	//s'obté la posició en la que esta el personatje actualment
		mapa.PintarBomba(j, i);//es crida a pintarBomba per pintar la bomba

	}
	if (premut == false)	//es comproba que no s'ha polsat cap tecla
	{
		Mov.GuardarTecla(NULL);//guardem un NULL ja que no hem premut cap tecla
	}

}
void PintarVides(Jugador Personaje, Sprite &vida)
{

	for (int i = 1; i < Personaje.getVidas() + 1; i++)//es fa un bucle per pintar les diferents vides en diferents posicions segons i
	{
		vida.draw(24 * i, 670);
	}
}

void PintarGameOver(const int vides, Screen &jocLib)
{
	Sprite GameOver;
	GameOver.create("data/gameover.png");
	if (vides == 0)	//comprovem si no tenim vides
	{
		GameOver.draw(250, 110); //pintem l'sprite GAMEOVER en el centre de la pantalla
		jocLib.update();//actualitzem la pantalla
		Sleep(2000);//fem una pausa per a que es quedi el gameover una estona
	}
}

void ComprobarSpace(vector <Bomba> &Bomb, const int &Per_i, const int& Per_j, const int& tecla, Cua &BombesExtra)/*aquesta funcio s'encarrega de
																												 comprobar si s'ha premut el space i
																												 canviar els valors dels atributs de la
																												 bomba per poder realitzar l'explosio
																												 en la funcio contadorBomba per que les
																												 explosions es facin en ordre i respectant
																												 el temps d'explosio*/
{
	int i = 0;
	bool trobat = false;
	if (Keyboard_GetKeyTrg(KEYBOARD_SPACE) || tecla == KEYBOARD_SPACE)//es comproba si s'ha premut el space
	{
		if (BombesExtra.esBuida() == true) //es mira que la cua de Bombesextres esta buida
		{
			while (i < 2 && trobat != true)// si es compleix la condicio es posa un limit a 2 bombes que poden ficar-se
			{

				if (Bomb[i].getDuracio() != true)//es comproba que la duracio sigui false
				{
					Bomb[i].setDuracio(true);//es canvia la duracio a true per despres poder inicialitzar el contador de l'explosio
					Bomb[i].setBomba_i(Per_i);//es canvia la posicio de la bomba la posicio donada
					Bomb[i].setBomba_j(Per_j);
					trobat = true;//i el boolea passa a true per poder sortir del bucle
				}
				else
					i++;
			}
		}
		else
		{//si la cua de bombes extres no esta buida es fa el següent
			int indexBombes = Bomb.size() + 1;//es declara un int amb el valor de la longitud de la cua+1
			Bomba BombaEx = BombesExtra.getPrimer().getActual();/*es declara una nova bomba que correspondra a la
																primera bomba de la cua */
			BombaEx.setBomba_i(Per_i);//es canvia la posicio de la bomba per la posicio donada
			BombaEx.setBomba_j(Per_j);
			BombaEx.setDuracio(true);//es canvia la duracio de la bomba per inicialitzar el contadorBomba amb aquesta bomba
			BombesExtra.EliminarBomba();//s'elimina la bomba de la cua
			Bomb.resize(indexBombes);//es redimensiona el array dinamic amb el valor de la longitud de la cua+1
			Bomb[indexBombes - 1] = BombaEx;//l'objecte bomba es fica a la posicio corresponent dins l'array dinamic de bombes+
											/*en conclusio es tracta de pasar totes les bombes de la cua un array dinamic per poder treballar amb aquest array a la
											funcio contadorBomba*/
		}
		i = 0;
		trobat = false;
	}
}

//Puntucaion
void PintarPuntuacio(const int &Nombre, const int &posi, const int &posj)
{
	int punts;
	Sprite numero_0, numero_1, numero_2, numero_3, numero_4, numero_5, numero_6, numero_7, numero_8, numero_9;//Creem un sprite per a cada numero
	numero_0.create("data/0.png");
	numero_1.create("data/1.png");
	numero_2.create("data/2.png");
	numero_3.create("data/3.png");
	numero_4.create("data/4.png");
	numero_5.create("data/5.png");
	numero_6.create("data/6.png");
	numero_7.create("data/7.png");
	numero_8.create("data/8.png");
	numero_9.create("data/9.png");
	for (int i = 1; i <= 1000; i *= 10) //fem un for fins a 1000 per indicar que tenim 4 numeros. El bucle anira aumentant de 10 en 10;
	{

		punts = Nombre / i;
		if (punts % 10 == 0)
		{
			if (i == 1)
				numero_0.draw(posj, posi);
			else if (i == 10)
				numero_0.draw(posj - 50, posi);
			else if (i == 100)
				numero_0.draw(posj - 100, posi);
			else if (i == 100)
				numero_0.draw(posj - 150, posi);
		}
		else if ((punts - 1) % 10 == 0)
		{
			if (i == 1)
				numero_1.draw(posj, posi);
			else if (i == 10)
				numero_1.draw(posj - 50, posi);
			else if (i == 100)
				numero_1.draw(posj - 100, posi);
			else if (i == 1000)
				numero_1.draw(posj - 150, posi);
		}
		else if ((punts - 2) % 10 == 0)
		{
			if (i == 1)
				numero_2.draw(posj, posi);
			else if (i == 10)
				numero_2.draw(posj - 50, posi);
			else if (i == 100)
				numero_2.draw(posj - 100, posi);
			else if (i == 1000)
				numero_2.draw(posj - 150, posi);
		}
		else if ((punts - 3) % 10 == 0)
		{
			if (i == 1)
				numero_3.draw(posj, posi);
			else if (i == 10)
				numero_3.draw(posj - 50, posi);
			else if (i == 100)
				numero_3.draw(posj - 100, posi);
			else if (i == 1000)
				numero_3.draw(posj - 150, posi);
		}
		else if ((punts - 4) % 10 == 0)
		{
			if (i == 1)
				numero_4.draw(posj, posi);
			else if (i == 10)
				numero_4.draw(posj - 50, posi);
			else if (i == 100)
				numero_4.draw(posj - 100, posi);
			else if (i == 1000)
				numero_4.draw(posj - 150, posi);
		}
		else if ((punts - 5) % 10 == 0)
		{
			if (i == 1)
				numero_5.draw(posj, posi);
			else if (i == 10)
				numero_5.draw(posj - 50, posi);
			else if (i == 100)
				numero_5.draw(posj - 100, posi);
			else if (i == 1000)
				numero_5.draw(posj - 150, posi);
		}
		else if ((punts - 6) % 10 == 0)
		{
			if (i == 1)
				numero_6.draw(posj, posi);
			else if (i == 10)
				numero_6.draw(posj - 50, posi);
			else if (i == 100)
				numero_6.draw(posj - 100, posi);
			else if (i == 1000)
				numero_6.draw(posj - 150, posi);
		}
		else if ((punts - 7) % 10 == 0)
		{
			if (i == 1)
				numero_7.draw(posj, posi);
			else if (i == 10)
				numero_7.draw(posj - 50, posi);
			else if (i == 100)
				numero_7.draw(posj - 100, posi);
			else if (i == 1000)
				numero_7.draw(posj - 150, posi);
		}
		else if ((punts - 8) % 10 == 0)
		{
			if (i == 1)
				numero_8.draw(posj, posi);
			else if (i == 10)
				numero_8.draw(posj - 50, posi);
			else if (i == 100)
				numero_8.draw(posj - 100, posi);
			else if (i == 1000)
				numero_8.draw(posj - 150, posi);
		}
		else if ((punts - 9) % 10 == 0)
		{
			if (i == 1)
				numero_9.draw(posj, posi);
			else if (i == 10)
				numero_9.draw(posj - 50, posi);
			else if (i == 100)
				numero_9.draw(posj - 100, posi);
			else if (i == 1000)
				numero_9.draw(posj - 150, posi);
		}
	}
}
void GuardarPosicionsEnemics(Escenario &mapa, Moviment &Mov)
{
	int i, j;
	Punt p;
	for (int m = 0; m < NumEnemics; m++)
	{
		mapa.getPosicio1(i, j, m);
		p.set_i(i);
		p.set_j(j);
		p.set_index(m);
		Mov.GuardarMovEnemic(p);
	}



}

//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc(int opcio, int &puntuacio, int &vidas, bool &trobat)
{

	// ********************************************
	// Inicialització de la part gràfica del joc
	// *******************************************
	//Inicialitza Part grafica
	Screen jocLib(MIDAX, MIDAY);

	//Mostrem finestra
	jocLib.show();
	int nivel = 1, tecla;
	Moviment Mov, Mov2, aux, aux2;
	Jugador Personaje;
	Sprite fons;
	Escenario mapa;
	vector <Bomba> Bomb;
	Bomb.resize(2);
	Sprite VIII;
	Cua BombesExtra;
	bool repeticio;
	int indice;
	int indexMov;
	int contadorEnemics;
	int Per_i, Per_j, Ene_i, Ene_j;
	fons.create("data/Fondo.png");
	VIII.create("data/vides.png");



	if (opcio == 1)//Comprobem si la opció indicada es la 1 o sigui jugar una nova partida
	{
		//Borrem els arxius de la repeticio anterior per a que no interfereixin amb els nous
		remove("Matrius/nivell_1.txt");
		remove("Matrius/nivell_1_Moviments.txt");
		remove("Matrius/nivell_2.txt");
		remove("Matrius/nivell_2_Moviments.txt");
		remove("Matrius/nivell_3.txt");
		remove("Matrius/nivell_3_Moviments.txt");
		remove("Matrius/nivell_4.txt");
		remove("Matrius/nivell_4_Moviments.txt");
		remove("Matrius/nivell_5.txt");
		remove("Matrius/nivell_5_Moviments.txt");
		mapa.InicialitzarClau();//inicialitzem una posició de la clau aleatoria al mapa
		mapa.GenerarMatriu(); //generem una matriu on estan tan els enemics com els blocs destruibles i indestructibles
		Personaje.setVidas(3);//generem que el personatje inicii amb 3 vides
		mapa.GuardarPartida(nivel, "Matrius/nivell_1.txt");//Cridem a Guardar partida per guardar la matriu i el nivell de la partida iniciada
		trobat = true;
	}
	else//sino
	{
		if (opcio == 3)//comprovem si es la opció 3 o sigui carregar partida
		{
			trobat=mapa.CarregarPartida(nivel, "Partides.txt");//carreguem el fitxer partides 
			Personaje.CargarPersonaje();//i el personatje per poder continuar amb la partida guardada
			
			for (int i = 0; i < Personaje.getNumBombes() - 2;i++)
				BombesExtra.afegeixBomba();
			
		}
		if (opcio == 4)//o la opció 4 o sigui reproduir partida
		{
			trobat=Mov2.CargarMoviments("Matrius/nivell_1_Moviments.txt");//carreguem els moviments fets en la partida anterior

			mapa.CarregarPartida(nivel, "Matrius/nivell_1.txt");//i el mapa que s'havia generat al inici del nivell
		}
	}
	if (trobat == true)//Aqsauest if ens permet 
	{
		do {

			if ((nivel > 1 && opcio == 1))//comprobem si haviem seleccionar la opció de jugar nova partida i si el nivell es major a 1 per generar una nova partida
			{
				mapa.InicialitzarClau();//inicialitzem una clau aleatoria
				mapa.GenerarMatriu();
				mapa.ReiniciarEnemics();//reiniciem les condicions dels enemics
				if (nivel == 2) { mapa.GuardarPartida(nivel, "Matrius/nivell_2.txt"); }//guardem la matriu i el nivell segons el nivell que comencem
				else if (nivel == 3) { mapa.GuardarPartida(nivel, "Matrius/nivell_3.txt"); }
				else if (nivel == 4) { mapa.GuardarPartida(nivel, "Matrius/nivell_4.txt"); }
				else { mapa.GuardarPartida(nivel, "Matrius/nivell_5.txt"); }

			}
			if ((nivel > 1 && opcio == 4))//es comprova si hem pasat de nivell reproduint la partida
			{
				aux2 = Mov2;
				Mov2.Inicialitza();
				aux2.~Moviment();
				mapa.ReiniciarEnemics();
				
				if (nivel == 2) {//si es nivell 2 carreguem la matriu del nivell 2 i els moviments
					mapa.CarregarPartida(nivel, "Matrius/nivell_2.txt");  Mov2.CargarMoviments("Matrius/nivell_2_Moviments.txt");
				}
				else if (nivel == 3) {//si es nivell 3 carreguem la matriu del nivell 3 i els moviments
					mapa.CarregarPartida(nivel, "Matrius/nivell_3.txt"); Mov2.CargarMoviments("Matrius/nivell_3_Moviments.txt");
				}
				else if (nivel == 4) {//si es nivell 4 carreguem la matriu del nivell 4 i els moviments
					mapa.CarregarPartida(nivel, "Matrius/nivell_4.txt"); Mov2.CargarMoviments("Matrius/nivell_4_Moviments.txt");
				}
				else {//sino carreguem la matriu del nivell 5 i els moviments
					mapa.CarregarPartida(nivel, "Matrius/nivell_5.txt"); Mov2.CargarMoviments("Matrius/nivell_5_Moviments.txt");
				}
			}
			mapa.InicialitzarPosicio();//inicialitzem la posicio dels enemics, en el Array privat d'enemics de la clase Escenari
			contadorEnemics = 0;//inicialitzem un contador d'enemics a 0, serivira per la velocitat del moviment dels enemics
			Personaje.setpasat(false);//modifiquem la variable pasat de la clase personatje a false
			Personaje.setagafat(false);//modifiquem la variable agafat de la clase personatje a false
			indexMov = 0;
			indice = 0;

			do
			{

				contadorEnemics++;
				jocLib.processEvents();
				if (opcio == 4)//si es opció 4 guardem que tecla es el numero indice del moviment guardat en tecles
				{
					tecla = Mov2.getTecles(indice);

					indice++;


				}
				fons.draw(Inici_X, Inici_Y);//pintem el fons

				for (int index = 0; index < 10; index++)//fem un bucle per pintar tots els enemics segons la seva "vida"
				{
					if (mapa.getVidesE(index) == 1) {
						mapa.getPosicio1(Ene_i, Ene_j, index);
						mapa.PintarEnemic(Ene_j, Ene_i);
					}
				}


				if (contadorEnemics == 250 - (50 * (nivel - 1)))//es comprova si el contador d'enemics es igual al numero 250 restant-li 50 per el nivell menys 1
				{
					if (opcio == 1 || opcio == 3)//i si la opció es 1 o 3
					{
						mapa.TractarEnemic(); //cridem al moviment aleatorio dels enemics
						GuardarPosicionsEnemics(mapa, Mov);//i guardem el moviment dels enemics

					}
					else
					{
							if (opcio == 4 && indexMov < Mov2.getNMovEnemic())
							{
								int i, j, indi, i_ant, j_ant;

								int lol = indexMov + 10;
								do
								{
								Mov2.getMovEnemic(indexMov, i, j, indi);
								if ((mapa.getPosicio(j, i) == 1 || mapa.getPosicio(j, i) == 4) && mapa.getVidesE(indi) == 1)
								{
									mapa.getPosicio1(i_ant, j_ant, indi);
									mapa.setPosicio(j_ant, i_ant, 1);
									mapa.setPosicio1(i, j, indi);
									mapa.setPosicio(j, i, 3);

								}
								indexMov++;
							} while (indexMov < lol);

						}
						else
						{
							Personaje.setVidas(-1);
						}
				}
					contadorEnemics = 0;

				}

				mapa.PintarBlocs();//Aqui ens done la funcio, on es crean els blocs destructibles en les posicions aleatories de la matriu
				Personaje.getPosicioP(Per_i, Per_j);//agafem la posicio del personatje
				MovimentPersonatge(Per_j, Per_i, mapa, Personaje, Mov, tecla, BombesExtra,opcio);//comprovem la tecla polsada i fem el moviment del personatje
				mapa.PintarPersonatge(Per_j, Per_i);//pintem el personatje segons la tecla polsada per ultim cop



				if (Personaje.getagafat() == true) {//si la variable agafat de la clase personatje es true posem un 15 (la porta) en la posicio 1,1 de la matriu
					mapa.setPosicio(1, 1, 15);
				}




				ComprobarSpace(Bomb, Per_i, Per_j, tecla, BombesExtra);//comprovem si hem polsat l'espai
				Personaje.setPosicioP(Per_i, Per_j);//com hem modificat la posició del personatje la modifiquem també a la clase personatje
				ContadorBomba(mapa, Bomb, Personaje, nivel, opcio, BombesExtra);//cridem a contadorbomba
				mapa.Pintarpowerinfo(340, 650);//pintem la informació dels powerups
				ComprovacioXoc(Personaje, mapa);//comprovem amb qui es xoca el personatje
				PintarVides(Personaje, VIII);//pintem vides
				PintarPuntuacio(Personaje.getPuntuacio(), 650, 750);//pintem puntuacions
				PintarPuntuacio(nivel, 650, 1000);//pintem el nivell
				PintarPuntuacio(Personaje.getNumBombes(), 650, 500);//pintem el nombre de bombes donades pel powerup

				jocLib.update();// Actualitza la pantalla


				// ***********************************************************************
				// Sortim del bucle si pressionem ESC, si el personatge pert les vides, si ha pasat de nivell amb la clau o si ha superat el nivell 5
				// ***********************************************************************

			} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && Personaje.getVidas() > 0 && Personaje.getpasat() == false && nivel <= 5);

			if (opcio == 1 && Personaje.getagafat() == true)
			{//En aques proces es pasa a guardar els moviments i adestruir el antic array de moviments per a poder crear un nou amb noves dades. Esta organitzat per nivells
				if (nivel == 1) { Mov.GuardarRepeticio("Matrius/nivell_1_Moviments.txt");aux = Mov; Mov.Inicialitza();  aux.~Moviment(); }
				else if (nivel == 2) {
					;Mov.GuardarRepeticio("Matrius/nivell_2_Moviments.txt");aux = Mov; Mov.Inicialitza();  aux.~Moviment();;
				}
				else if (nivel == 3) {
					Mov.GuardarRepeticio("Matrius/nivell_3_Moviments.txt");aux = Mov; Mov.Inicialitza();  aux.~Moviment();
				}
				else if (nivel == 4) {
					Mov.GuardarRepeticio("Matrius/nivell_4_Moviments.txt");aux = Mov; Mov.Inicialitza();  aux.~Moviment();
				}
				else {
					Mov.GuardarRepeticio("Matrius/nivell_5_Moviments.txt"); Mov.~Moviment();
				}
			}
			if (Personaje.getagafat() == true)
			{
				nivel++;

			}


		} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && Personaje.getVidas() > 0 && nivel <= 5);
	}

	if ((Personaje.getVidas() <= 0 || nivel > 5) && opcio!=4)
	{
		PintarGameOver(Personaje.getVidas(), jocLib);
		puntuacio = Personaje.getPuntuacio();
		vidas = Personaje.getVidas();
		if (opcio == 1)
		{
		if (nivel == 1) { Mov.GuardarRepeticio("Matrius/nivell_1_Moviments.txt"); }
		else if (nivel == 2) { ;Mov.GuardarRepeticio("Matrius/nivell_2_Moviments.txt"); }
		else if (nivel == 3) { Mov.GuardarRepeticio("Matrius/nivell_3_Moviments.txt"); }
		else if (nivel == 4) { Mov.GuardarRepeticio("Matrius/nivell_4_Moviments.txt"); }
		else { Mov.GuardarRepeticio("Matrius/nivell_5_Moviments.txt"); }
		}
	}

	else if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && opcio!=4)
	{// Guardem els moviments, la informacio de la partida i els moviments en cas de que sigui la opcio 1.
		mapa.GuardarPartida(nivel, "Partides.txt");
		Personaje.GuardarPersonaje();
		
		if (opcio == 1) 
		{
			if (nivel == 1) { Mov.GuardarRepeticio("Matrius/nivell_1_Moviments.txt"); }
			else if (nivel == 2) { ;Mov.GuardarRepeticio("Matrius/nivell_2_Moviments.txt"); }
			else if (nivel == 3) { Mov.GuardarRepeticio("Matrius/nivell_3_Moviments.txt"); }
			else if (nivel == 4) { Mov.GuardarRepeticio("Matrius/nivell_4_Moviments.txt"); }
			else { Mov.GuardarRepeticio("Matrius/nivell_5_Moviments.txt"); }
		}
	}
	// Aquestos auxiliars estan inicialitzance per que el compilador no es queixi a la hora de destruirlos
	aux.Inicialitza();
	aux2.Inicialitza();
}
