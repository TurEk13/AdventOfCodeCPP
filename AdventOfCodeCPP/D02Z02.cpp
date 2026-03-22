#include "D02Z02.h"

void D02Z02_2015::ObliczZadanie()
{
	std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
	std::string linia;

	if (plik.is_open())
	{
		while (std::getline(plik, linia))
		{
			std::regex szukaj("^(\\d{1,})x(\\d{1,})x(\\d{1,})");
			std::smatch dopasowania;

			std::regex_search(linia, dopasowania, szukaj);

			this->_Wynik += this->ObliczIloscPapieru(dopasowania);
		}
	}
}

int D02Z02_2015::ObliczIloscPapieru(std::smatch dlugosci)
{
	int boki[] = { std::stoi(dlugosci[1]), std::stoi(dlugosci[2]), std::stoi(dlugosci[3])};
	std::sort(std::begin(boki), std::end(boki));

	return 2 * boki[0] + 2 * boki[1] + boki[0] * boki[1] * boki[2];
}

D02Z02_2015::D02Z02_2015(std::string sciezka)
{
	this->_SciezkaDoPliku = sciezka;
	this->_Wynik = 0;

	this->ObliczZadanie();
}

D02Z02_2015::~D02Z02_2015()
{
	this->_SciezkaDoPliku = "";
	this->_Wynik = 0;
}

int D02Z02_2015::PokazWynik()
{
	return this->_Wynik;
}
