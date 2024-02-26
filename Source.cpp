#include <iostream>
#include <cmath>
#include <fstream>

struct Star {
	float x;
	float y;
	float z;
	double distance;
};

void Distance(Star& notSun) {
	notSun.distance = pow(notSun.x, 2) + pow(notSun.y, 2) + pow(notSun.z, 2);
}

int main() {
	const int MAX_Name = 31;
	const int MAX_Size = 64;
	int count = 0;
	char fileName[MAX_Name];
	Star arr[MAX_Size];
	std::cin >> fileName;

	std::ifstream in(fileName);
	if (!in) {
		std::cout << "Couldn't open the given file.";
		return 0;
	}
	//out << "\n" << "May God forgive you, because I won't." << std::endl;
	in >> count;
	double Minimum = 100000000000000000000.0;
	int adress;
	for (int i = 0; i < count; i++) {
		in >> arr[i].x;
		in >> arr[i].y;
		in >> arr[i].z;
		Distance(arr[i]);
		std::cout << arr[i].distance << "\n";
		if (arr[i].distance < Minimum) {
			Minimum = arr[i].distance;
			adress = i;
		}
	}
	std::cout << "The closest star to us is located at (" << arr[adress].x << "; " << arr[adress].y << "; " << arr[adress].z << ") that is " << sqrt(arr[adress].distance) << " lightyears away.";
	in.close();
	return 0;
}