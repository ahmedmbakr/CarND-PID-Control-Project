#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	is_prev_cte_init = false;
	i_error = 0;
	this->Kp = Kp; 
	this->Kd = Kd;
	this->Ki = Ki;
}

void PID::UpdateError(double cte) {
	if (!is_prev_cte_init) {
		prev_cte = cte;
		is_prev_cte_init = true;
	}
	p_error = cte;
	d_error = cte - prev_cte;
	prev_cte = cte;
	i_error += cte;
}

double PID::TotalError() {
	const double steer = -Kp * p_error - Ki * i_error - Kd * d_error;
	return steer;
}

