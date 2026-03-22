#pragma once

#include <fstream>
#include <string>

class D01Z01_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();

	public:
		D01Z01_2015(std::string sciezka);
		int PokazWynik();
		~D01Z01_2015();
};