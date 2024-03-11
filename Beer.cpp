#include "Beer.h"
#include <cstring>

const char* Beer::GetBrand() const{
	return this->Brand;
}

void Beer::SetBrand(const char name[128]) {
	strcpy_s(this->Brand, name);
}

int Beer::GetVolume() const{
	return this->Vol;
}

void Beer::SetVolume(const int size) {
	this->Vol = size;
}

Beer::Beer(const char* x, const int y) {
	SetBrand(x);
	SetVolume(y);
}

void Beer::AddBeer(Beer& sourse, const int vol) {
	strcat_s(this->Brand, sourse.Brand);
	this->Vol += vol;
	sourse.Vol -= vol;
}

bool Beer::Check(const char* Brand) const{
	if (!strstr(this->Brand, Brand)) {
		return false;
	}
	return true;
}