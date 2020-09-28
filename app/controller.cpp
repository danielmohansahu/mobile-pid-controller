/* @file controller.cpp
 * @ author [Part 1] : Daniel Sahu (Driver), Spencer Elyard (Navigator)
 * @ author [Part 2] : Rajeshwar N S (Driver), Aditya Khopkar (Navigator)
 * @copyright [2020] <Daniel M. Sahu> <Spencer Elyard> 
 */

#include "include/controller.h"

// stub implementation
double PIDController::compute(double setpoint, double velocity) {
  // Find the error
  double err = setpoint - velocity;
  // Find the proportional output
  double prop_term = kp_ * err;
  integral_ += err * dt_;
  // FInd the Integral output
  double integ_term = ki_ * integral_;
  double derivative = (err - previous_error_) / dt_;
  // FInd the derivative output
  double deriv_term = kd_ * derivative;
  // Combine the outputs
  double out = prop_term + integ_term + deriv_term;
  // New error
  previous_error_ = err;
  return out;
}

// stub implementation
void PIDController::reset() {
  integral_ = 0.0;
  previous_error_ = 0.0;
}

// stub implementation
void PIDController::setK(double kp, double ki, double kd) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
}

// stub implementation
void PIDController::setT(double dt) {
  dt_ = dt;
}

// stub implementation
double& PIDController::getKp() {
  return kp_;
}
// stub implementation
double& PIDController::getKi() {
  return ki_;
}
// stub implementation
double& PIDController::getKd() {
  return kd_;
}

// stub implementation
double& PIDController::getDt() {
  return dt_;
}
