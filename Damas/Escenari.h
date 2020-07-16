#pragma once
#include "lib\libreria.h"
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include "Enemics.h"


using namespace std;
const int NumEnemics = 10;
const int N_Columnes = 35;
const int N_Files = 21;

class Enemic
{
public:
	Enemic() { m_vida = 1; };

	void setPosicioE(int i, int j) { Pos_j = j;Pos_i = i; }
	void getPosicioE(int& i, int &j) { i = Pos_i; j = Pos_j; }
	int getVida() { return m_vida; }const
	void setVida(const int &valor) { m_vida = valor; }
private:
	int Pos_j;
	int Pos_i;
	int m_vida;
};
class Escenario
{
public:
	Escenario() {
		S_Perso.create("Personaje/AbaixParat.png");
		S_Persoiz.create("Personaje/IzquierdaPiernaeParado.png");
		S_Persoar.create("Personaje/AdaltPiernaeParado.png");
		S_Persode.create("Personaje/DerechaParado.png");
		S_Enemigo.create("Personaje/Enemic.png");
		S_Bomba.create("Bomba/BombaPrimersNivells.png");
		S_Bomba2.create("Bomba/BombaNivellsMitad.png");
		Centre.create("Bomba/ExplosioCentral.png");
		Lateral.create("Bomba/ExplosioHoritzontal.png");
		Vertical.create("Bomba/ExplosioVertical.png");
		Esquerra.create("Bomba/ExplosioFinalEsquerra.png");
		Dreta.create("Bomba/ExplosioFinalDreta.png");
		Superior.create("Bomba/ExplosioFinalSuperior.png");
		Inferior.create("Bomba/ExplosioFinalInferior.png");
		powerinfo.create("Bomba/powerinfo.png");
	}


	void GenerarMatriu();
	void PintarBlocs();
	int getPosicio(int j, int i) const { return m_matriu[i][j]; }
	void setPosicio(int j,int i, int valor)
	{m_matriu[i][j] = valor;} 
	void PintarPersonatge(int j, int i);
	void PintarEnemic (int j, int i)
	{S_Enemigo.draw(j*30, i*30);}
	void PintarBomba(int j, int i) {S_Bomba.draw(j * 30, i * 30);}
	void InicialitzarPosicio();
	void TractarEnemic();
	void ReiniciarEnemics();
	void setPosicio1(int& i, int &j, const int &index) { Enemy[index].setPosicioE(i, j); }
	void getPosicio1(int& i, int &j, const int &index) { Enemy[index].getPosicioE(i,j);}
	int getVidesE( const int &index) { return Enemy[index].getVida(); }
	void EliminarEnemy(const int &indiceEnemic) { Enemy[indiceEnemic].setVida(0); };
	bool getLlave(){return m_llave;} const
	 void setLlave(const bool& llave){ m_llave=llave;}
	int RandomPowerUP();
	void setpw(const bool& pw) { m_pw = pw; }
	void setps(const bool& ps) { m_ps = ps; }
	void setpd(const bool& pd) { m_pd = pd; }
	void setpa(const bool& pa) { m_pa = pa; }
	void PintarExplosions(int Bomb_i, int Bomb_j, int nivel);
	void GuardarPartida(const int &nivel,const string& fitxer);
	bool CarregarPartida(int &nivel,const string& fitxer);
	void InicialitzarClau();
	void Pintarpowerinfo(const int &posi, const int &posj) { powerinfo.draw(posi, posj); }
private:
	int m_matriu[N_Files][N_Columnes];
	Sprite S_Perso, S_Persoar, S_Persoiz, S_Persode, S_Enemigo, S_Bomba,S_Bomba2,Centre, Lateral, Vertical, Esquerra, Dreta, Superior, Inferior, powerinfo;
	Enemic Enemy[NumEnemics];
	bool  m_llave,m_pw = false, m_ps = false, m_pa = false, m_pd = false;;;
	bool m_puerta;

};

