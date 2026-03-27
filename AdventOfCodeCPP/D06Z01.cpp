#include "D06Z01.h"

void D06Z01_2015::ObliczZadanie()
{
    std::vector<std::string> linia;
    std::vector<std::string> poczatek;
    std::vector<std::string> koniec;
    int wierszStart, wierszStop, kolumnaStart, kolumnaStop;

    for(int i = 0; i < this->_ileLinii; i++)
    {
        linia = this->PodzielLinie(this->_Instrukcje[i], ' ');
        
        if(linia.at(0) == "toggle")
        {
            //1, 3
            poczatek = this->PodzielLinie(linia.at(1), ',');
            koniec = this->PodzielLinie(linia.at(3), ',');

            wierszStart = std::stoi(poczatek.at(0));
            wierszStop = std::stoi(koniec.at(0));
            kolumnaStart = std::stoi(poczatek.at(1));
            kolumnaStop = std::stoi(koniec.at(1));

            for(int wiersz = wierszStart; wiersz <= wierszStop; wiersz++)
            {
                for(int kolumna = kolumnaStart; kolumna <= kolumnaStop; kolumna++)
                {
                    this->_Swiatla[wiersz][kolumna] = !this->_Swiatla[wiersz][kolumna];
                }
            }
        }

        if(linia.at(0) == "turn")
        {
            //2, 4
            poczatek = this->PodzielLinie(linia.at(2), ',');
            koniec = this->PodzielLinie(linia.at(4), ',');

            wierszStart = std::stoi(poczatek.at(0));
            wierszStop = std::stoi(koniec.at(0));
            kolumnaStart = std::stoi(poczatek.at(1));
            kolumnaStop = std::stoi(koniec.at(1));

            for(int wiersz = wierszStart; wiersz <= wierszStop; wiersz++)
            {
                for(int kolumna = kolumnaStart; kolumna <= kolumnaStop; kolumna++)
                {
                    this->_Swiatla[wiersz][kolumna] = linia.at(1) == "on" ? true : false;
                }
            }
        }
    }

    for(int wiersz = 0; wiersz < 1000; wiersz++)
    {
        for(int kolumna = 0; kolumna < 1000; kolumna++)
        {
            if(this->_Swiatla[wiersz][kolumna])
            {
                this->_Wynik++;
            }
        }
    }
}

std::vector<std::string> D06Z01_2015::PodzielLinie(const std::string linia, char podzial)
{
    std::vector<std::string> wynik;
    int poczatek, koniec = linia.find(podzial);

    while(koniec != std::string::npos)
    {
        wynik.push_back(linia.substr(poczatek, koniec - poczatek));
        poczatek = koniec + 1;
        koniec = linia.find(podzial, poczatek);
    }

    wynik.push_back(linia.substr(poczatek));

    return wynik;
}

D06Z01_2015::D06Z01_2015(std::string sciezka)
{
    this->_Wynik = 0;
    this->_SciezkaDoPliku = sciezka;

    // Wyłączenie wszystkich świateł na początek
    for(int wiersz = 0; wiersz < 1000; wiersz++)
    {
        for(int kolumna = 0; kolumna < 1000; kolumna++)
        {
            this->_Swiatla[wiersz][kolumna] = false;
        }
    }

    std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);
    if(plik.is_open())
    {
        plik.unsetf(std::ios_base::skipws);

        // Wczytanie ilości lini
        this->_ileLinii = std::count(std::istream_iterator<char>(plik), std::istream_iterator<char>(), '\n');
        plik.clear();
        plik.seekg(0, std::ios::beg);

        // Wczytanie instrukcji
        this->_Instrukcje = new std::string[this->_ileLinii];

        for(int i = 0; i < this->_ileLinii; i++)
        {
            std::getline(plik, this->_Instrukcje[i]);
        }

        plik.close();
    }

    this->ObliczZadanie();
}

int D06Z01_2015::PokazWynik()
{
    return this->_Wynik;
}

D06Z01_2015::~D06Z01_2015()
{
    this->_Wynik = 0;
    this->_ileLinii = 0;
    this->_SciezkaDoPliku = "";
}