#include "D03Z01.h"

void D03Z01_2015::ObliczZadanie()
{
	// 2 2631
	std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
	Dom d;
	std::unordered_set<Dom, Dom::HashFunction> domy;
	domy.insert(d);//
	char znak;

	if (plik.is_open())
	{
		while (plik.read(&znak, 1))
		{
			d = d.ZmienKierunek(znak);
			domy.insert(d);
		}
	}

	this->_Wynik = domy.size();
}

D03Z01_2015::D03Z01_2015(std::string sciezka)
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = sciezka;

	this->ObliczZadanie();
}

int D03Z01_2015::PokazWynik()
{
	return this->_Wynik;
}

D03Z01_2015::~D03Z01_2015()
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = "";
}