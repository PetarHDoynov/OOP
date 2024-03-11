#pragma once
class Beer
{
	char Brand[128];
	int Vol;
public:
	Beer();
	Beer(const char* x, const int y);
	const char* GetBrand() const;
	void SetBrand(const char name[128]);
	int GetVolume() const;
	void SetVolume(const int size);
	void AddBeer(Beer& sourse, const int vol);
	bool Check(const char* Brand) const;
};