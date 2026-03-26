#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>
#include <bits/stdc++.h>

class D05Z02_2015
{
	private:
		std::string _SciezkaDoPliku;
		char *samogloski;
		std::string *string;
		int _Wynik;
		int _ileLinii;
		int _ileZnakow;
		int _iloscSamoglosek;
		void ObliczZadanie();
		bool SprawdzPodwojonePary(int obecnaLinia);
		bool SprawdzPodwojoneLitery(int obecnaLinia);


	public:
		D05Z02_2015(std::string sciezka);
		int PokazWynik();
		~D05Z02_2015();
};