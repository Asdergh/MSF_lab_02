#include "linker.h"


void unperturbed() {
	std::ofstream file;
	file.open("C:/Users/mk170/MSF/3/lab 3/lab 3 graph/unperturbed.txt");
	std::vector<double> parameters = { P, SIGMA, INC, U, ECC };
	for (int i = 0; i < 5; i++) {
		file << parameters[i] << " ";
	}
	file.close();
}