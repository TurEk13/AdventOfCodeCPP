#pragma once

#include <fstream>
#include <string>
#include <unordered_set>
#include "D03_Dom.h"

class D03Z02_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();

	public:
		D03Z02_2015(std::string sciezka);
		int PokazWynik();
		~D03Z02_2015();
};