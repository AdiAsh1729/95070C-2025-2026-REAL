#include "autons.h"

void RightQual() {
    Intake.setVelocity(99, pct);
    Intake1.spin(forward);
    Intake2.spin(reverse);
    wait(50, msec);
    chassis.driveDistance(24);
    wait(50, msec);
    chassis.driveDistance(5);
    wait(50, msec);
    chassis.turnToHeading(100);
    wait(50, msec);
    chassis.driveDistance(30);
    Intake.stop();
    wait(50, msec);
    chassis.turnToHeading(160);
    wait(50, msec);
    chassis.driveDistance(-14);
    wait(50, msec);
    Intake.spin(reverse);
    wait(500, msec);
    Intake.spin(forward);
}

void LeftQual() {
    chassis.turnToHeading(180);
}

void RightElim() {

}

void LeftElim() {

}

void SoloAWP() {

}

void AutonSkills() {

}
