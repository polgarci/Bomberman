#include "Moviment.h"




void Moviment::GuardarTecla(const int &tecla)//s'encarrega de guardar les tecles
{

	m_NTecles++;//s'augmenta el numero de tecles
	int* aux = m_tecles;//es copia el array m_tecles en un array auxiliar aux
	m_tecles = new int[m_NTecles];//es declara un nou array m_tecles amb la nova dimensio
	int i = 0;
	if (m_NTecles>1)//si el numero de tecles es major a 1
		for (i; i < m_NTecles - 1; i++)
		{
			m_tecles[i] = aux[i];//es copien al nou array m_tecles totes les tecles guardades al array auxiliar

		}

	m_tecles[i] = tecla;//en la ultima posicio es guarda la nova tecla 


	delete[]aux;//s'allibera la memoria del array aux

}
void Moviment::GuardarMovEnemic(Punt MovEnemic)//s'encarrega de guardar les posicions del enemics
{

	m_NMovEnemics++;//s'augmente el numero de moviments dels enemics
	Punt* aux = m_MovEnemics;//en un array auxiliar es guarden tots el moviments del array m_MovEnemics
	int i = 0;
	m_MovEnemics = new Punt[m_NMovEnemics];//es declara un nou array m_MovEnemics amb la nova dimensio

	if (m_NTecles>1)//es comproba que el numero de moviments sigui major a 1
		for (i; i < m_NMovEnemics - 1; i++)
		{
			m_MovEnemics[i] = aux[i];//es copien el moviments al nou array m_MovEnemics del array aux

		}
	m_MovEnemics[i] = MovEnemic;//es guarda el moviment donat en la ultima posicio del nou array


	delete[] aux;// s'allibera el array auxiliar
}

void Moviment::GuardarRepeticio(const string& nom)//es guarden els moviments fet per el personatge i per el enemics
{

	ofstream file;//s'obre en mode escriptura

	file.open(nom);

	if (file.is_open())
	{
		file << m_NTecles << endl;;//es guarden el numero de tecles
		for (int i = 0; i < m_NTecles; i++)
		{
			file << m_tecles[i] << " ";//per ordre deixant un espai
		}
		file << endl << m_NMovEnemics << endl;//un cop guardades les tecles, es guarden els moviments fets pels enemics

		for (int j = 0; j < m_NMovEnemics; j++)//per ordre
		{
			int i_E = m_MovEnemics[j].get_i();//s'agafa la posicio i del enemic
			int j_E = m_MovEnemics[j].get_j();//s'agafa la posicio j del enemic
			int index_E = m_MovEnemics[j].get_index();//s'agafa el index del enemic, el numero que correspon al enemic del 0 al 9
			file << index_E << " " << i_E << " " << j_E << " | ";
			if (j % 9 == 0 && j != 0)//es comproba que s'ha guardat la posicio de tots els enemics
			{
				file << endl;//i es fa un salt de linea
			}
		}


		file.close();
	}


}
bool Moviment::CargarMoviments(const string& nom)//es carreguen els movimetns guardats al arxiu nivell_X_Moviments
{
	ifstream file;//s'obre el arxiu en mode lectura
	file.open(nom);
	int Ntecles, totalMov, tecla, i, j, index;
	int m = 0;char aux;
	Punt p;

	if (file.is_open())
	{
		file >> Ntecles;//es llegeix el numero de tecles
		while (!file.eof()& m<Ntecles)
		{
			for (m = 0; m < Ntecles; m++)//es va mirant que m no superi el numero de tecles
			{
				file >> tecla;//i es va llegint cada tecla
				GuardarTecla(tecla);//es guarda la tecla per reproduir-ho
			}
			file >> totalMov;//es llegeix el numero de moviments efectuats pels enemics
			for (int x = 0; x < totalMov; x++)
			{
				file >> index >> i >> j;//es llegeix el index del enemic, la posicio "i" i "j"
				file >> aux;//es llegeix el caracter "|" que es el separador del moviment de cada enemic
				p.set_i(i);//es cambia la posicio segons el que s'ha llegit i el index de igual manera
				p.set_j(j);
				p.set_index(index);//Guardem el index del enemic al que pertoca les posicions anteriorment agafades

				GuardarMovEnemic(p);//es guardar el moviment del enemic per reproduir-ho
			}
		}
		file.close();
		
	}
	else
	{
		return false;
	}
	return true;

}