#pragma once

#include <fstream>
#include <string>

class D01Z02_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();

	public:
		D01Z02_2015(std::string sciezka);
		~D01Z02_2015();
		int PokazWynik();
};