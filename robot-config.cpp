#include "robot-config.h"

brain Brain;
controller Controller = controller(primary);

motor FL = motor(PORT10, ratio6_1, true);
motor ML = motor(PORT14, ratio6_1, true);
motor BL = motor(PORT13, ratio6_1, true);
motor_group LeftDrive = motor_group(FL, ML, BL);
motor FR = motor(PORT1, ratio6_1, false);
motor MR = motor(PORT17, ratio6_1, false);
motor BR = motor(PORT18, ratio6_1, false);
motor_group RightDrive = motor_group(FR, MR, BR);

motor Intake1 = motor(PORT8, ratio18_1, false);
motor Intake2 = motor(PORT11, ratio18_1, true);
motor_group Intake = motor_group(Intake1, Intake2);

digital_out Descore = digital_out(Brain.ThreeWirePort.H);
digital_out Matchloader = digital_out(Brain.ThreeWirePort.C);
digital_out MiddleGoal = digital_out(Brain.ThreeWirePort.H);
digital_out Park = digital_out(Brain.ThreeWirePort.A);

inertial Inertial = inertial(PORT16);

void vexcodeInit(void) {

}
