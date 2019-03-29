#include "PID.h"
#include <vector>  
#include <numeric>  
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

double arraySum(std::vector<double> &v) { 
    double initial_sum  = 0.0;  
    return std::accumulate(v.begin(), v.end(), initial_sum); 
} 

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
  PID::prev_cte = 0.0;
  
//   dp = {0.0, 0.0, 0.0};
//   p = {&p_error, &i_error, &d_error};
  
//   threshold = 0.001;
}

void PID::UpdateError(double cte) {
  // Proportional part
  PID::p_error = cte;
  
  // Integral part
  PID::i_error += cte;
  
  // Differential part
  PID::d_error = cte - PID::prev_cte;
  
  PID::prev_cte = cte;
  
  // Twiddle
//   PID::best_error = PID::TotalError();
  
//   while (arraySum(dp) > threshold) {
//     for (int i = 0; i < dp.size(); i++) {
//       *p[i] += dp[i];
      
//       if (PID::TotalError() < PID::best_error) {
//         PID::best_error = PID::TotalError();
//         dp[i] *= 1.1;
//       } else {
//         *p[i] -= 2*dp[i];
//         if (PID::TotalError() < PID::best_error) {
//           PID::best_error = PID::TotalError();
//           dp[i] *= 1.05;
//         } else {
//           *p[i] += dp[i];
//           dp[i] *= 0.95;
//         }
//       }
//     }
//   }
  
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  return PID::p_error * PID::Kp + PID::i_error * PID::Ki + PID::d_error * PID::Kd;
}
