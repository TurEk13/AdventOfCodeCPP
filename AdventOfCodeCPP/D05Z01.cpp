#include "D05Z01.h"

void D05Z01_2015::ObliczZadanie()
{
    bool samogloski3, podwojneLitery, zlaCzastka;
    
    for(int i = 0; i < this->_ileLinii; i++)
    {
        samogloski3 = this->SprawdzSamogloski(i);
        podwojneLitery = this->SprawdzPodwojneLitery(i);
        zlaCzastka = this->SprawdzPodwojneKolejneLitery(i);

        if(samogloski3 && podwojneLitery && !zlaCzastka)
        {
            this->_Wynik++;
        }
    }
}

bool D05Z01_2015::SprawdzSamogloski(int obecnaLinia)
{
    int ileSamoglosek = 0, npos;
    for(int obecnaPozycja = 0; obecnaPozycja < this->_iloscSamoglosek; obecnaPozycja++)
    {
        npos = -1;
        while((npos = this->string[obecnaLinia].find(this->samogloski[obecnaPozycja], npos + 1)) != std::string::npos)
        {
            ileSamoglosek++;
        }
    }

    return ileSamoglosek > 2 ? true : false;
}

bool D05Z01_2015::SprawdzPodwojneLitery(int obecnaLinia)
{
    std::string linia = this->string[obecnaLinia];

    for(int i = 0; i < this->_ileZnakow - 1; i++)
    {
        if(this->string[obecnaLinia][i] == this->string[obecnaLinia][i + 1])
        {
            return true;
        }
    }

    return false;
}

bool D05Z01_2015::SprawdzPodwojneKolejneLitery(int obecnaLinia)
{
    std::string czesci[4] = { "ab", "cd", "pq", "xy" };

    for(int i = 0; i < sizeof(czesci) / sizeof(czesci[0]); i++)
    {
        if(this->string[obecnaLinia].find(czesci[i]) != std::string::npos)
        {
            i = sizeof(czesci);
            return true;
        }
    }

    return false;
}

D05Z01_2015::D05Z01_2015(std::string sciezka)
{
    this->_Wynik = 0;
    this->_iloscSamoglosek = 5;
    this->samogloski = new char[this->_iloscSamoglosek]{ 'a', 'e', 'i', 'o', 'u' };
    this->_SciezkaDoPliku = sciezka;
    this->_ileLinii = 0;
    bool kolejnaLinia = true;
    std::string linia;

    std::ifstream plik(this->_SciezkaDoPliku, std::ios::in);

    if(plik.is_open())
    {
        int dlugoscPliku = 0;

        plik.unsetf(std::ios_base::skipws);

        // Wczytanie ilości lini
        this->_ileLinii = std::count(std::istream_iterator<char>(plik), std::istream_iterator<char>(), '\n');

        // Utworzenie tablicy do danych wejściowych
        this->string = new std::string[this->_ileLinii];

        plik.clear();
        plik.seekg(0, std::ios::beg);

        for(int i = 0; i < this->_ileLinii; i++)
        {
            std::getline(plik, this->string[i]);
        }

        plik.close();
        this->_ileZnakow = this->string[0].length();
    }

    this->ObliczZadanie();
}

int D05Z01_2015::PokazWynik()
{
    return this->_Wynik;
}

D05Z01_2015::~D05Z01_2015()
{
    this->_Wynik = 0;
    this->_SciezkaDoPliku = "";
    this->_ileLinii = 0;
    this->_ileZnakow = 0;
    delete this->samogloski;
    delete this->string;
}