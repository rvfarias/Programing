#include <iostream>

int ask(/* arguments */) {
	int x;

	std::cout << "Digite um valor para x:" << '\n';
	std::cin >> x;
	std::cout << "\nConcluido...\n";

	return x;
}

int main(int argc, char const *argv[]) {

		int x;

		x = ask();

		while (x>0) {

			std::cout << "O pai ta on!!!" << '\n';
			x--;
		}

		return 0;
}
