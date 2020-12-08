#include <iostream>

int main(int argc, char const *argv[]) {

	int x;

	std::cin >> x;
	std::cout << x << "\n";

	for (int i = 1; i <= x; i++) {
		std::cout << "#" << x << "O pai ta on\n";
	}

	return 0;
}
