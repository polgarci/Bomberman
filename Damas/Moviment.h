#pragma once
#include "Joc.h"

class Punt
{
public:
	Punt() { m_i = 0; m_j = 0; };
	int get_i() { return m_i; }
	int get_j() { return m_j; }
	void set_i(const int & i) { m_i = i; }
	void set_j(const int & j) { m_j = j; }
	void set_index(const int & index) { m_index = index; }
	int get_index() { return m_index; }
private:
	int m_i;
	int m_j;
	int m_index;
};



class Moviment
{
public:
	Moviment() { m_NTecles = 0; m_tecles =NULL; m_NMovEnemics = 0; m_MovEnemics=NULL; }
	Moviment(const Moviment &M1) {
		m_NTecles = M1.m_NTecles; for (int i = 0; i < m_NTecles;i++) { m_tecles[i] = M1.m_tecles[i]; }
		m_NMovEnemics = M1.m_NMovEnemics;for (int i = 0; i < m_NMovEnemics;i++) { m_MovEnemics[i] = M1.m_MovEnemics[i]; }
	}
	void GuardarTecla(const int &tecla);
	void GuardarRepeticio(const string& nom);
	void GuardarMovEnemic( Punt valor);
	int getTecles(const int &index) { return m_tecles[index]; }
	void getMovEnemic(const int &index, int &i, int& j, int &index_E) { i = m_MovEnemics[index].get_i(); j = m_MovEnemics[index].get_j();index_E = m_MovEnemics[index].get_index(); }
	void Inicialitza() { m_NTecles = 0; m_tecles = NULL; m_NMovEnemics = 0; m_MovEnemics = NULL; }
	bool CargarMoviments(const string& nom);
	int getNMovEnemic() { return m_NMovEnemics; }
	int getNtecles() { return m_NTecles; }
	~Moviment() { delete[] m_tecles; delete[] m_MovEnemics; };

private:
	int* m_tecles;
	int m_NTecles;
	Punt *m_MovEnemics;
	int m_NMovEnemics;
};

