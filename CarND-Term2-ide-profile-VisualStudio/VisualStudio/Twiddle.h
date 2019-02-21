#pragma once
class Twiddle
{
	double params[3];// p, i, d params
	double params_weights[3] = {0};
	double best_err;
	class Try_params
	{
		double kp, ki, kd;
	public:
		Try_params(double kp, double ki, double kd)
			: kp(kp), ki(ki), kd(kd)
		{
		}
		//This function tries the parameters given on samples from the track and gives us the average error
		double run();
	};
public:
	Twiddle(double kp, double ki, double kd)
	{
		params[0] = kp;
		params[1] = ki;
		params[2] = kd;	
	}

	double optimize(double tol);
	double sum_params();
};