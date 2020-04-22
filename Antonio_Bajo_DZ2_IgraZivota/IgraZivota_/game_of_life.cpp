#include "game_of_life.h"
#include <ctime>
#include <iomanip>
#define GREEN   "\033[1m\033[32m" 
#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"

using namespace std;

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			this->_generacija[i][j] = slucajna_vrijednost();
		}
	}
	
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {

			if (celija_zauzeta(i,j))//ako je zauzeta ..
			{
				if (broj_susjeda(i, j) < 2 || broj_susjeda(i, j) > 3)_sljedeca_generacija[i][j] = 0;    //broj susjednik veci >3 ili <2 celija =0;
				else _sljedeca_generacija[i][j] = 1;
			}
		
			else  //ako nije zauzeta
			{
				if (broj_susjeda(i, j) == 3)_sljedeca_generacija[i][j] = 1; //broj susjednik =3 , celija =1;
				else _sljedeca_generacija[i][j] = 0;
			}

		
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];   //generacija = sljedeca generacija
		}
	}
}

void game_of_life::iscrtaj()
{
	
	system("cls");
	for (unsigned i = 0; i < REDAKA; i++) {
		for (unsigned j = 0; j < STUPACA; j++) {
			if (this->_generacija[i][j] == 0)cout << RED<< setw(2.5) << '-'<<RESET;
			else cout  << GREEN << setw(2.5)<< '*' << RESET;
		}
		cout << endl;
	}
}

bool game_of_life::slucajna_vrijednost()
{
	int n = rand() % (100 - 1 + 1) + 1;
	if (n <= 25)return true;
	else return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j] == false)return false;
	else return true;
}

int game_of_life::broj_susjeda(int i, int j)
{
	//A B C
	//D E F					//E - Trenutna pozicija
	//G H J
	bool A(1), B(1), C(1), D(1), F(1), G(1), H(1), J(1);
	int n = 0;
	if (i == 0)  { A = 0, B = 0, C = 0; }
	if (i == REDAKA-1) { G = 0, H = 0, J = 0; }
	if (j == 0)  { A = 0, D = 0, G = 0; }
	if (j == STUPACA-1) { C = 0, F = 0, J = 0; }
	
	if (A) { if (_generacija[i - 1][j - 1] == 1)n++; }	
	if (B) { if (_generacija[i - 1][j] == 1)n++; }			
	if (C) { if (_generacija[i - 1][j + 1] == 1)n++; }		

	if (D) { if (_generacija[i][j - 1] == 1)n++; }		
												
	if (F) { if (_generacija[i][j + 1] == 1)n++; }
	
	if (G) { if (_generacija[i + 1][j - 1] == 1)n++; }	
	if (H) { if (_generacija[i + 1][j] == 1)n++; }
	if (J) { if (_generacija[i + 1][j + 1] == 1)n++; }

	return n;
}


