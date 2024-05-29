#include "linker.h"


void perturbed(std::vector<double> THETA, int rounds) {
	std::ofstream radius;
	radius.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\radius.txt");
	radius << std::setprecision(30);
	std::ofstream p;
	p.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\p.txt");
	p << std::setprecision(30);
	std::ofstream ecc;
	ecc.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\ecc.txt");
	ecc << std::setprecision(30);
	std::ofstream omega;
	omega.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\omega.txt");
	omega << std::setprecision(30);
	std::ofstream i;
	i.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\i.txt");
	i << std::setprecision(30);
	std::ofstream sigma;
	sigma.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\sigma.txt");
	sigma << std::setprecision(30);
	std::ofstream S;
	S.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\S.txt");
	S << std::setprecision(30);
	std::ofstream T;
	T.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\T.txt");
	T << std::setprecision(30);
	std::ofstream W;
	W.open("C:\\Users\\1\\Desktop\\MSF_lab_02\\log_dir\\W.txt");
	double tempP = P;
	double tempECC = ECC;
	double tempOm = U;
	double tempS;
	double tempT;
	std::vector<double>::iterator iter = THETA.begin();
	int tmp = 0;

	for (int step = 0; step < (360 * rounds) + 1; step += 15) {
		double tempTHETA = *(iter + tmp);
		double tempR = tempP / (1.0 + tempECC * cos(tempTHETA));
		double V = m / tempP * (1.0 + pow(tempECC, 2.0) + 2 * tempECC * cos(tempTHETA));
		double Fa = (Cxa * AtmDensity * pow(V, 2.0) * Sa) / (2.0 * m);

		tempS = -(Fa * tempECC * sin(tempTHETA)) / (sqrt(1.0 + pow(tempECC, 2.0) + 2.0 * tempECC * cos(tempTHETA)));
		tempT = -(Fa * (1.0 + tempECC * cos(tempTHETA))) / (sqrt(1.0 + pow(tempECC, 2.0) + 2.0 * tempECC * cos(tempTHETA)));
		double pChange = (2.0 / Mu) * pow(tempR, 3.0) * tempT;
		double eChange = (pow(tempR, 2.0) / Mu) * (tempS * sin(tempTHETA) + tempT * ((1.0 + (tempR / tempP)) * cos(tempTHETA) + tempECC * (tempR / tempP)));
		double omChange = (pow(tempR, 2.0) / (Mu * tempECC)) * (tempT * (1.0 + (tempR / tempP)) * cos(tempTHETA) - tempS * cos(tempTHETA));
		std::cout << "delta p = " << pChange << "; deltaECC = " << eChange << "; delta OMEGA = " << omChange << "." << std::endl;


		radius << tempR << " ";
		p << tempP << " ";
		ecc << tempECC << " ";
		omega << tempOm << " ";
		i << INC << " ";
		sigma << SIGMA << " ";
		S << tempS << " ";
		T << tempT << " ";
		W << 0.0 << " ";

		tempP += (15.0 * PI / 180.0) * pChange;
		tempECC += (15.0 * PI / 180.0) * eChange;
		tempOm += (15.0 * PI / 180.0) * omChange;
		tmp++;
	}
	radius.close();
	p.close();
	ecc.close();
	omega.close();
	i.close();
	sigma.close();
	S.close();
	T.close();
	W.close();
}