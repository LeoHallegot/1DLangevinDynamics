#include "constants.h"
#include <cmath>
using namespace std;

// ----- Constants ----- //
extern const double m = 1.0; // Mass of particle
extern const double gamma_Lang = 100.0; // Friction coefficient
extern const double dt = 0.001; // Time step
extern const double kt = 1.0;
extern const double sigma = sqrt((1.0 - exp(-2.0 * gamma_Lang * dt)) * m * kt);
// ----- Simulation parameters ----- //
extern const int num_steps = 20000000; // Number of simulation steps
extern const int outfreq = 1000;  //prints 1 line every outfreq steps
// ----- Well parameters ----- //
extern const double k = 1.0; // Spring constant (single harmonic well)
extern const double A = 0.05; // A, B and C : constant for double well
extern const double B = 0.8; // = Ax⁴+Bx²+C
extern const double C = abs( A*pow(sqrt(B/(2*A)),4) - B*pow(sqrt(B/(2*A)),2) );
// C : normalisation, make min(V(x))=0 and barrier heigth = C. 
// A = 0.05, B=1.2 -> C = 7.2  // A=0.07, B=1.0 -> C env= 3.5 kbT


// ----- Bias parameters ----- //
// - constant - //
extern const double k_bias = 1.4; //harmonic restraint
extern const double cstbias = C/2.0; //constant bias
// - time-dependant - //
extern const double v_bias = 8.0/(dt*num_steps); // x~[-5;5]; time to walk the entire path ~ 10/v_bias
								  // we want at *least* 10.000 time steps => v_bias<0.001.
