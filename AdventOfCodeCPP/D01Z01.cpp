#include "D01Z01.h"

void D01Z01_2015::ObliczZadanie()
{
	std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
	int lewo = 0, prawo = 0;
	char znak;

	if (plik.is_open())
	{
		while (plik.read(&znak, 1))
		{
			if (znak == '(') { lewo++; }
			if (znak == ')') { prawo++; }
		}
	}

	this->_Wynik = lewo - prawo;
}

D01Z01_2015::D01Z01_2015(std::string sciezka)
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = sciezka;

	this->ObliczZadanie();
}

int D01Z01_2015::PokazWynik()
{
	return this->_Wynik;
}

D01Z01_2015::~D01Z01_2015()
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = "";
}