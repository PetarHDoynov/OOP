#include <iostream>
#include <fstream>
#include "Beer.h"

int main() {
	Beer beer1("Stella Artois", 500);
	Beer beer2("Heineken", 500);
	beer1.AddBeer(beer2, 250);
	std::cout << beer1.GetBrand() << " " << beer1.GetVolume() << "ml" << "\n";
	std::cout << beer2.GetBrand() << " " << beer2.GetVolume() << "ml" << "\n";
	if (beer1.Check(beer2.GetBrand())) {
		std::cout << "true";
	}
	else {
		std::cout << "false";
	}
}