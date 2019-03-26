#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients and errors
   */
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;
  
  PID::p_error = 0.0;
  PID::i_error = 0.0;
  PID::d_error = 0.0;

}

void PID::UpdateError(double cte) {
  // Proportional part
  PID::p_error = cte;
  
  // Integral part
  PID::i_error += cte;
  
  // Differential part
  PID::d_error = cte - PID::p_error;
  
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return PID::p_error * PID::Kp + PID::i_error * PID::Ki + PID::d_error * PID::Kd;
}