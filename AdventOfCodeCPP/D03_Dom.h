#pragma once
#include <unordered_set>

class Dom
{
private:
	int _X;
	int _Y;
public:
	Dom();
	void UstawWspolrzedne(int x, int y);
	Dom ZmienKierunek(char znak);
	bool operator == (const Dom dom) const;
	struct HashFunction
	{
		size_t operator()(const Dom& dom) const;
	};
};