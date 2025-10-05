#include "driver-control.h"

void runIfPressingMotor(motor& Motor, const controller::button& ButtonForward, const controller::button& ButtonReverse, int velocityPct) {
    if(ButtonForward.pressing()) {
        Motor.spin(forward, velocityPct, pct);
    }

    else if(ButtonReverse.pressing()) {
        Motor.spin(reverse, velocityPct, pct);
    }

    else {
        Motor.stop();
    }
}

void runIfPressingMotorGroup(motor_group& MotorGroup, const controller::button& ButtonForward, const controller::button& ButtonReverse, int velocityPct) {
    if(ButtonForward.pressing()) {
        MotorGroup.spin(forward, velocityPct, pct);
    }

    else if(ButtonReverse.pressing()) {
        MotorGroup.spin(reverse, velocityPct, pct);
    }

    else {
        MotorGroup.stop();
    }
}

void runIfPressedMotor(motor& Motor, const controller::button& ButtonForward, const controller::button& ButtonReverse, const controller::button& ButtonStop, int velocityPct) {
    if(ButtonForward.pressing()) {
        Motor.spin(forward, velocityPct, pct);
    }

    else if(ButtonReverse.pressing()) {
        Motor.spin(reverse, velocityPct, pct);
    }

    else if(ButtonStop.pressing()) {
        Motor.stop();
    }
}

void runIfPressedMotorGroup(motor_group& MotorGroup, const controller::button& ButtonForward, const controller::button& ButtonReverse, const controller::button& ButtonStop, int velocityPct) {
    if(ButtonForward.pressing()) {
        MotorGroup.spin(forward, velocityPct, pct);
    }

    else if(ButtonReverse.pressing()) {
        MotorGroup.spin(reverse, velocityPct, pct);
    }

    else if(ButtonStop.pressing()) {
        MotorGroup.stop();
    }
}

void runArcadeDrive(motor_group& LeftDrive, motor_group& RightDrive, inertial& Inertial, controller& Controller, double scaleDriveSpeed, double scaleTurnSpeed) {
    double DriveSpeed = (Controller.Axis3.position()) * scaleDriveSpeed;
    double TurnSpeed = (Controller.Axis1.position()) * scaleTurnSpeed;
    LeftDrive.setStopping(coast);
    RightDrive.setStopping(coast);
    if((LeftDrive.velocity(pct) > 0 && RightDrive.velocity(pct) == 0) || (LeftDrive.velocity(pct) == 0 && RightDrive.velocity(pct) > 0)) {
        LeftDrive.setVelocity(0, pct);
        RightDrive.setVelocity(0, pct);
    }

    else {
        LeftDrive.setVelocity((DriveSpeed + TurnSpeed), pct);
        RightDrive.setVelocity((DriveSpeed - TurnSpeed), pct);
    }

    if(Controller.ButtonUp.pressing()) {
        scaleDriveSpeed *= 0.5;
        scaleTurnSpeed *= 0.5;
    }

    LeftDrive.spin(forward);
    RightDrive.spin(forward);
}

void descore_middleGoal() {
    DMPressed ++;
    if((DMPressed)%2 == 0) {
        Descore.set(true);
        MiddleGoal.set(true);
    }

    else {
        Descore.set(false);
        MiddleGoal.set(false);
    }
}


void doublePark() {
    ParkPressed ++;

    if((ParkPressed)%2 == 0) {
        Park.set(true);
    }

    else {
        Park.set(false);
    }
}

void matchload() {
    MatchloadPressed ++;

    if((MatchloadPressed)%2 == 0) {
        Matchloader.set(true);
    }

    else {
        Matchloader.set(false);
    }
}

void moveIntake() {
    switch(CurrentDriver) {
        case Daniel:
            runIfPressedMotor(Intake1, Controller.ButtonR2, Controller.ButtonR1, Controller.ButtonB, 99);
            runIfPressedMotorGroup(Intake, Controller.ButtonL2, Controller.ButtonL1, Controller.ButtonB, 99);
            break;

        case Thomas:
            runIfPressedMotor(Intake1, Controller.ButtonR1, Controller.ButtonR2, Controller.ButtonB, 99);
            runIfPressedMotorGroup(Intake, Controller.ButtonL1, Controller.ButtonL2, Controller.ButtonB, 99);
            break;

        case Nikhil:
            runIfPressedMotor(Intake1, Controller.ButtonR1, Controller.ButtonR2, Controller.ButtonB, 99);
            runIfPressedMotorGroup(Intake, Controller.ButtonL1, Controller.ButtonL2, Controller.ButtonB, 99);
            break;
    }
}

void moveDrivetrain() {
    switch(CurrentDriver) {
        case Daniel:
            runArcadeDrive(LeftDrive, RightDrive, Inertial, Controller, 0.99, 0.95);
            break;

        case Thomas:
            runArcadeDrive(LeftDrive, RightDrive, Inertial, Controller, 0.70, 0.65);
            break;

        case Nikhil:
            runArcadeDrive(LeftDrive, RightDrive, Inertial, Controller, 0.50, 0.50);
            break;
    }
}
