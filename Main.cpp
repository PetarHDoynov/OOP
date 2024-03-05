#include <iostream>
#include <fstream>

int main() {
	int current, result;
	std::ifstream in("data.dat", std::ios::binary | std::ios::in);
	if (!in) {
		return -1, current = 0;
	}
	
	in.seekg(0, std::ios::end);
	int size = in.tellg();
	if (size % 4 != 0) {
		std::cout << "Error";
		in.close();
		return -1;
	}
	in.seekg(0, std::ios::beg);

	while (in.read(reinterpret_cast<char*>(&current), sizeof(int))) {
		result = std::max(result, current);
	}

	std::cout << result;
	return 0;
}