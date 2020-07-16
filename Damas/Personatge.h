#include <iostream>
#include "Joc.h"

using namespace std;




class Jugador
{
    public:
		Jugador() { m_i = 1; m_j = 1; m_vidas = 3;  m_puntuacio = 0; m_pasat = false; m_agafat = false; }
		void getPosicioP(int &i, int &j) { i = m_i;j = m_j; }
		void setPosicioP(const int &i, const int &j) {m_i = i; m_j = j;}
		bool getpasat() { return m_pasat; }
		void setpasat(const bool &pasat) { m_pasat = pasat; }
		bool getagafat() { return m_agafat; }
		void setagafat(const bool &agafat) { m_agafat = agafat; }
		int getVidas() const { return m_vidas; } 
		void setVidas(const int &vidas) { m_vidas = vidas; }
		void GuardarPersonaje();
		void CargarPersonaje();
		int getPuntuacio() { return m_puntuacio; } const
		void setPuntuacio(const int &p) { m_puntuacio = p; }
		void setPowerUp(const bool &agafatpower) { m_agafatpower = agafatpower; }
		bool getPowerUp() { return m_agafatpower; }
		void setNumBombes(const int &NumBombes) { m_NumBombes = NumBombes; }
		int getNumBombes() { return m_NumBombes; }

private:
	int m_i;
	int m_j;
	int m_vidas;
	int m_puntuacio;
	int m_NumBombes;
	bool m_pasat, m_agafat, m_agafatpower;
};

