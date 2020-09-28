/* @file test.cpp
 * @ author [Part 1] : Daniel Sahu (Driver), Spencer Elyard (Navigator)
 * @ author [Part 2] : Rajeshwar N S (Driver), Aditya Khopkar (Navigator)
 * @copyright [2020] <Daniel M. Sahu> <Spencer Elyard> 
 */

#include <gtest/gtest.h>
#include <controller.h>

// instantiate and initialize the class
PIDController controller { };

// Check that a newly instantiated class has no state.
TEST(Initialization, should_pass) {
  EXPECT_EQ(controller.compute(0.0, 0.0), 0.0);
}

// Test setters and getters.
TEST(SetGetParameters, should_pass) {
  double kp = 0.5;
  double ki = 0.1;
  double kd = 0.2;
  double dt = 0.01;

  // set parameters
  controller.setK(kp, ki, kd);
  controller.setT(dt);

  // get parameters back
  double kp_out, ki_out, kd_out;
  kp_out = controller.getKp();
  ki_out = controller.getKi();
  kd_out = controller.getKd();
  double dt_out;
  dt_out = controller.getDt();

  // check that input matches output
  EXPECT_DOUBLE_EQ(kp, kp_out);
  EXPECT_DOUBLE_EQ(ki, ki_out);
  EXPECT_DOUBLE_EQ(kd, kd_out);
  EXPECT_DOUBLE_EQ(dt, dt_out);
}

// Test that basic computation works
TEST(Compute1, should_pass) {
  EXPECT_DOUBLE_EQ(controller.compute(1.0, 0.0), 20.501);
}

// Test that basic computation works
TEST(Compute2, should_pass) {
  EXPECT_DOUBLE_EQ(controller.compute(1.0, 1.1), -22.0491);
}

// Test that resetting the controller works
TEST(ResetCompute, should_pass) {
  controller.reset();
  EXPECT_DOUBLE_EQ(controller.compute(1.0, 0.0), 20.501);
}
