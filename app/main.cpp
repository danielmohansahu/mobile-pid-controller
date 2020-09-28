/* @file main.cpp
 * @ author [Part 1] : Daniel Sahu (Driver), Spencer Elyard (Navigator)
 * @ author [Part 2] : Rajeshwar N S (Driver), Aditya Khopkar (Navigator)
 * @copyright [2020] <Daniel M. Sahu> <Spencer Elyard> 
 */

#include <iostream>
#include "include/controller.h"

int main() {
  PIDController controller;
  double desired, actual;
  double kp = 0.5;
  double ki = 0.1;
  double kd = 0.2;
  double dt = 0.01;
  std::cout << "Enter the desired velocity: ";
  std::cin >> desired;

  std::cout << "ENter the actual velocity: ";
  std::cin >> actual;

  // call the setter function
  controller.setK(kp, ki, kd);
  controller.setT(dt);

  // call the compute method
  double new_output = controller.compute(desired, actual);
  std::cout << "output of the PID controller= " << new_output << std::endl;
  return 0;
}
