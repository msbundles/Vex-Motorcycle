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
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("Vroom Vroom");
  Brain.Screen.print("Vroom Vroom");

  
  while(1){
    if(Controller1.ButtonX.pressing()){
      for(int i=0; i<100;i++){
        RTR.spin(directionType::fwd,i, velocityUnits::pct);
        RTL.spin(directionType::fwd,i, velocityUnits::pct);
        RBR.spin(directionType::fwd,i, velocityUnits::pct);
        RBL.spin(directionType::fwd,i, velocityUnits::pct);
        LTR.spin(directionType::fwd,i, velocityUnits::pct);
        LTL.spin(directionType::fwd,i, velocityUnits::pct);
        LBR.spin(directionType::fwd,i, velocityUnits::pct);
        LBL.spin(directionType::fwd,i, velocityUnits::pct);
        task::sleep(200);
      }
      Controller1.Screen.print("Spinup Done");
      task::sleep(500);
      Controller1.Screen.clearScreen();
    }
    else if(Controller1.ButtonB.pressing()){
      for(int i=0; i>0;i--){
        RTR.spin(directionType::fwd,i, velocityUnits::pct);
        RTL.spin(directionType::fwd,i, velocityUnits::pct);
        RBR.spin(directionType::fwd,i, velocityUnits::pct);
        RBL.spin(directionType::fwd,i, velocityUnits::pct);
        LTR.spin(directionType::fwd,i, velocityUnits::pct);
        LTL.spin(directionType::fwd,i, velocityUnits::pct);
        LBR.spin(directionType::fwd,i, velocityUnits::pct);
        LBL.spin(directionType::fwd,i, velocityUnits::pct);
        task::sleep(500);
      }
      Controller1.Screen.print("Spindown Done");
      task::sleep(500);
      Controller1.Screen.clearScreen();

    }
    else{
      RTR.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      RTL.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      RBR.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      RBL.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      LTR.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      LTL.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      LBR.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      LBL.spin(directionType::fwd,Controller1.Axis2.value(), velocityUnits::pct);
      steer.spin(directionType::fwd,Controller1.Axis4.value(), velocityUnits::pct);
    }
  }
}
