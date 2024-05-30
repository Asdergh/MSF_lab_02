#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

//Constant params
#define mu 398602.4415 //Gravity parameter
#define R 6378.1 //Earth's radius

//Initial data
#define PI 3.1415926
#define I (40.5 * PI / 180.0) //Inclanation
#define Ha 860.0 //Apogee height
#define Hp 210.0 //Perigee height
#define OMEGA (40.0 * PI / 180.0) //The longitude of the ascending node
#define U (50.0 * PI / 180.0) //Latitude argument
#define Sa 12.0 //Area of Space Aircaft(SA)
#define m 1500.0 //SA's mass
#define Cxa 2.0 //Coefficient of frontal force resistance

//Orbital parameters(not found yet)
#define Ra R + Ha //Apogee radius
#define Rp R + Hp //Perigee radius
#define a (Rp + Ra) / 2.0 //Semi-major axis
#define e (Ra - Rp) / (Ra + Rp) //Eccentricity
#define P a * (1 - pow(e, 2.0)) //Focal parameter
#define AtmDensity 1.82838 * pow(10.0, -10.0)

#define Re 6378.1
#define Wz 7.2921159 * pow(10.0, -5.0)

void undisturbance();
void disturbance(std::vector<double> THETA, int rounds);