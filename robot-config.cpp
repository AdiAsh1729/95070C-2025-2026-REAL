#include "vex.h"
#include "robot-config.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;


brain Brain;
controller Controller;


motor FL = motor(PORT12, ratio6_1, true);
motor ML = motor(PORT15, ratio6_1, true);
motor BL = motor(PORT6, ratio6_1, true);
motor_group LeftDrive = motor_group(FL, ML, BL);
motor FR = motor(PORT17, ratio6_1, false);
motor MR = motor(PORT11, ratio6_1, false);
motor BR = motor(PORT1, ratio6_1, false);
motor_group RightDrive = motor_group(FR, MR, BR);

motor Intake1 = motor(PORT3, ratio18_1, true);
motor Intake2 = motor(PORT4, ratio18_1, false);
motor_group Intake = motor_group(Intake1, Intake2);

digital_out PL = digital_out(Brain.ThreeWirePort.A);

inertial Inertial = inertial(PORT2);
rotation Rotation = rotation(PORT22, true);

void vexcodeInit(void);
