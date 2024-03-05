#include <iostream>
#include <fstream>

struct Point {
	float coordx;
	float coordy;
};

int main() {
	std::ifstream in("input-points.dat", std::ios::binary | std::ios::in);
	if (!in) {
		return -1;
	}

	in.seekg(0, std::ios::end);
	int size = in.tellg();
	if (size % (2 * sizeof(float)) != 0) {
		std::cout << "Error";
		in.close();
		return -1;
	}
	in.seekg(0, std::ios::beg);

	Point arr[size / sizeof(float)];

	return 0;
}