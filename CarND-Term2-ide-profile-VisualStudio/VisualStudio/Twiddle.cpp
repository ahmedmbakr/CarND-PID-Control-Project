#include "Twiddle.h"

double Twiddle::optimize(double tol = 0.2)
{
	Try_params try_params(params[0], params[1], params[2]);
	double best_err = try_params.run();
	double sum_params = 0;
	while(sum_params() < tol)
	{
		
	}
}

double Twiddle::sum_params()
{
	double sum = 0;
	for (double param : this->params)sum += param;
	return sum;
}
