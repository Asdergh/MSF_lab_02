#include "linker.h"

std::vector<double> createTHETADataFile(int rounds);


int main() {
	int rounds = 3;
	std::vector<double> THETA = createTHETADataFile(rounds);
	unperturbed();
	perturbed(THETA, rounds);
	return 0;
}


std::vector<double> createTHETADataFile(int rounds) {
	std::ofstream file;
	std::ofstream unperturbedRadius;
	unperturbedRadius.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\unperturbedRadius.txt");
	std::vector<double> THETA;
	file.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\THETAparams.txt");


	for (int step = 0; step < (360 * rounds) + 1; step += 15) {
		double stepPI = step * PI / 180.0;
		THETA.push_back(stepPI);
		unperturbedRadius << (P / (1.0 + ECC * cos(stepPI))) << " ";
		file << step << " ";
	}
	file.close();
	unperturbedRadius.close();
	return THETA;
}