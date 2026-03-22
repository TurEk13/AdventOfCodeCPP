#include "D03Z02.h"

void D03Z02_2015::ObliczZadanie()
{
	// 2 2631
	std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
	Dom dM, dR;
	std::unordered_set<Dom, Dom::HashFunction> domy;
	domy.insert(dM);
	char znak;
	bool CzytajDalej = true;

	if (plik.is_open())
	{
		while (CzytajDalej)
		{
			if (plik.read(&znak, 1))
			{
				dM = dM.ZmienKierunek(znak);
				domy.insert(dM);
			}
			else
			{
				CzytajDalej = false;
			}

			if (CzytajDalej && plik.read(&znak, 1))
			{
				dR = dR.ZmienKierunek(znak);
				domy.insert(dR);
			}
			else
			{
				CzytajDalej = false;
			}
		}
	}

	this->_Wynik = domy.size();
}

D03Z02_2015::D03Z02_2015(std::string sciezka)
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = sciezka;

	this->ObliczZadanie();
}

int D03Z02_2015::PokazWynik()
{
	return this->_Wynik;
}

D03Z02_2015::~D03Z02_2015()
{
	this->_Wynik = 0;
	this->_SciezkaDoPliku = "";
}