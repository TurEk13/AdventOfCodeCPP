#pragma once

#include <fstream>
#include <string>
#include <unordered_set>
#include "D03_Dom.h"

class D03Z01_2015
{
	private:
		std::string _SciezkaDoPliku;
		int _Wynik;
		void ObliczZadanie();

	public:
		D03Z01_2015(std::string sciezka);
		int PokazWynik();
		~D03Z01_2015();
};