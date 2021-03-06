#include <math.h>
#include <vector>
#include <iostream>
#include "RHS.h"
#include "constants.h"
#include "pulsar_parameters.h"
#include "process_functions.h"
#include "auxilary.h"

void RHS(double R, double *f, double *dydx) {
	double coeff = R_star * omega / (2.0 * c);

	double LL = Lambda (R);
	double QQ = Q (R);
	double BB = BetaB (R);
	double DD = delta (R);
	
	//temp for understanding
	cout << R << " " << LL << " " << QQ << " " << BB << " " << DD << endl;

	dydx[0] = coeff * (-LL / QQ - LL * cos(2 * f[0] - 2 * BB - 2 * DD) * sinh(2 * f[1]));
	dydx[1] = coeff * LL * sin(2 * f[0] - 2 * BB - 2 * DD) * cosh(2 * f[1]);
	/*/temp for debug
	if (fabs(dydx[1])>1e5) {
		cout << R << " " << f[0] << " " << f[1] << " " << coeff << " " << LL << endl;
	}*/
}
