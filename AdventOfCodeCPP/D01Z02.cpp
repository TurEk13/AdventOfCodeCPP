#include "D01Z02.h"

void D01Z02_2015::ObliczZadanie()
{
	std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
	char znak;
	int pozycja = 0;

	if (plik.is_open())
	{
		while (pozycja != -1 && plik.read(&znak, 1))
		{
			pozycja = znak == '(' ? pozycja + 1 : pozycja - 1;
			this->_Wynik++;
		}
	}
}

D01Z02_2015::D01Z02_2015(std::string sciezka)
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = sciezka;

	this->ObliczZadanie();
}

D01Z02_2015::~D01Z02_2015()
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = "";
}

int D01Z02_2015::PokazWynik()
{
	return this->_Wynik;
}
