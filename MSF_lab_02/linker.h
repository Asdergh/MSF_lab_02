#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

//Constant params
#define Mu 398602.4415 //Gravity parameter
#define R 6378.1 //Earth's radius

//Initial data
#define PI 3.1415926
#define INC (40.5 * PI / 180.0) //Inclanation
#define Ha 860.0 //Apogee height
#define Hp 210.0 //Perigee height
#define SIGMA (40.0 * PI / 180.0) //The longitude of the ascending node
#define U (50.0 * PI / 180.0) //Latitude argument
#define Sa 12.0 //Area of Space Aircaft(SA)
#define m 1500.0 //SA's mass
#define Cxa 2.0 //Coefficient of frontal force resistance

//Orbital parameters(not found yet)
#define Ra R + Ha //Apogee radius
#define Rp R + Hp //Perigee radius
#define SMA (Rp + Ra) / 2.0 //Semi-major axis
#define ECC (Ra - Rp) / (Ra + Rp) //Eccentricity
#define P SMA * (1 - pow(ECC, 2.0)) //Focal parameter
#define AtmDensity 1.82838 * pow(10.0, -10.0)

void unperturbed();
void perturbed(std::vector<double> THETA, int rounds);