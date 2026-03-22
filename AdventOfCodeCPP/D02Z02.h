#pragma once

#include <fstream>
#include <string>
#include <regex>

class D02Z02_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();
		int ObliczIloscPapieru(std::smatch dopasowania);

	public:
		D02Z02_2015(std::string sciezka);
		~D02Z02_2015();
		int PokazWynik();
};