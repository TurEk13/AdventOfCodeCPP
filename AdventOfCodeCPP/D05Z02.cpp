#include "D05Z02.h"

void D05Z02_2015::ObliczZadanie()
{
    bool PodwojoneLitery, PodwojonePary;
    int PodwojoneLiteryI = 0, PodwojoneParyI = 0;

    for(int i = 0; i < this->_ileLinii; i++)
    {
        if(i == 24)
        {
            //std::cout << "Pauza\n";
        }
        PodwojonePary = this->SprawdzPodwojonePary(i);
        PodwojoneLitery = this->SprawdzPodwojoneLitery(i);

        if(PodwojonePary) { PodwojoneParyI++; std::cout << i << '\t' << this->string[i] << "\r\n"; }
        if(PodwojoneLitery) PodwojoneLiteryI++;

        if(PodwojoneLitery && PodwojonePary)
        {
            this->_Wynik++;
        }
    }

    std::cout << "PodwojoneLitery(431): " << PodwojoneLiteryI << ", PodwojonePary(129): " << PodwojoneParyI << '\n';
}

bool D05Z02_2015::SprawdzPodwojonePary(int obecnaLinia)
{
    /*
    - It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
    
    410
    
    */

    std::string cz;
    int indeks, indeksStary, powtorzenia;

    for(int i = 0; i < this->_ileZnakow - 1; i++)
    {
        cz = this->string[obecnaLinia].substr(i, 2);

        powtorzenia = 0;
        indeksStary = 0;
        indeks = -1;
        while((indeks = this->string[obecnaLinia].find(cz, indeks + 1)) != std::string::npos)
        {
            if(indeksStary + 1 == indeks)
            {
                continue;
            }
            powtorzenia++;
            indeksStary = indeks;
        }

        if(powtorzenia > 1)
        {
            return true;
        }
    }

    return false;
}

bool D05Z02_2015::SprawdzPodwojoneLitery(int obecnaLinia)
{
    char *czastka = new char[this->_ileZnakow];
    std::strcpy(czastka, this->string[obecnaLinia].c_str());

    for(int i = 0; i < this->_ileZnakow - 2; i++)
    {
        if(*(czastka + i) == *(czastka + i + 2))
        {
            return true;
        }
    }

    return false;
}

D05Z02_2015::D05Z02_2015(std::string sciezka)
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

        this->_ileLinii = std::count(std::istream_iterator<char>(plik), std::istream_iterator<char>(), '\n');
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

int D05Z02_2015::PokazWynik()
{
    return this->_Wynik;
}

D05Z02_2015::~D05Z02_2015()
{
    this->_Wynik = 0;
    this->_SciezkaDoPliku = "";
    this->_ileLinii = 0;
    this->_ileZnakow = 0;
    delete this->samogloski;
    delete this->string;
}