#pragma once

#include <fstream>
#include <string>
#include <regex>

class D02Z01_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();
		int ObliczIloscPapieru(std::smatch dopasowania);

	public:
		D02Z01_2015(std::string sciezka);
		~D02Z01_2015();
		int PokazWynik();
};