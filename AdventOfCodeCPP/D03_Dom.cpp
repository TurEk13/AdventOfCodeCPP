#include "D03_Dom.h"

Dom::Dom()
{
	this->_X = 0;
	this->_Y = 0;
}

void Dom::UstawWspolrzedne(int x, int y)
{
	this->_X += x;
	this->_Y += y;
};

Dom Dom::ZmienKierunek(char znak)
{
	Dom wynik;
	switch (znak)
	{
	case '<':
		wynik.UstawWspolrzedne(this->_X - 1, this->_Y);
		break;
	case '>':
		wynik.UstawWspolrzedne(this->_X + 1, this->_Y);
		break;
	case '^':
		wynik.UstawWspolrzedne(this->_X, this->_Y + 1);
		break;
	case 'v':
		wynik.UstawWspolrzedne(this->_X, this->_Y - 1);
		break;
	default:
		break;
	}

	return wynik;
}

bool Dom::operator==(const Dom dom) const
{
	return this->_X == dom._X && this->_Y == dom._Y;
}

size_t Dom::HashFunction::operator()(const Dom& dom) const
{
	size_t xHash = std::hash<int>()(dom._Y);
	size_t yHash = std::hash<int>()(dom._Y) << 1;
	return xHash ^ yHash;
}