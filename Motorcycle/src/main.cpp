/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\abertocchini05                                   */
/*    Created:      Tue Feb 04 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <iostream>
#include <math>
using namespace std;
using namespace vex;
motor RTR = motor(PORT1, ratio18_1, false);
motor RTL = motor(PORT2, ratio18_1, false);
motor RBL = motor(PORT3, ratio18_1, true);
motor RBR = motor(PORT4, ratio18_1, true);
motor LTR = motor(PORT5, ratio18_1, false);
motor LTL = motor(PORT6, ratio18_1, false);
motor LBL = motor(PORT7, ratio18_1, false);
motor LBR = motor(PORT8, ratio18_1, false);
motor steer = motor(PORT20, ratio18_1, false);
controller Controller1;
double speedExpo = 1;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  RTR.setStopping(brakeType::coast);
  RTL.setStopping(brakeType::coast);
  RBL.setStopping(brakeType::coast);
  RBR.setStopping(brakeType::coast);
  LTR.setStopping(brakeType::coast);
  LTL.setStopping(brakeType::coast);
  LBL.setStopping(brakeType::coast);
  LBR.setStopping(brakeType::coast);
  steer.setStopping(brakeType::hold);
  steer.resetRotation();
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("Vroom Vroom");
  Brain.Screen.print("Vroom Vroom");

  while(1){
    int turnSpeed = Controller1.Axis4.value()*pow(1,Controller1.Axis4.value());
    RTR.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    RTL.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    RBR.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    RBL.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    LTR.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    LTL.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    LBR.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    LBL.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);	
    steer.spin(directionType::fwd,turnSpeed,);	
  }	
}
