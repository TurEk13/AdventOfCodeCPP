#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <bits/stdc++.h>

class D06Z01_2015
{
	private:
		std::string _SciezkaDoPliku;
		std::string *_Instrukcje;
		int _ileLinii;
		int _Wynik;
		bool _Swiatla[1000][1000];
		void ObliczZadanie();
		std::vector<std::string> PodzielLinie(const std::string linia, char podzial);

	public:
		D06Z01_2015(std::string sciezka);
		int PokazWynik();
		~D06Z01_2015();
};