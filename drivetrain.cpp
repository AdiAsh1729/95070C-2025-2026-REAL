#include "drivetrain.h"

Drivetrain::Drivetrain(brain& Brain, motor_group& LeftDrive, motor_group& RightDrive, inertial& Inertial, double gearRatio, double wheelDiameter):
    Brain(Brain),
    LeftDrive(LeftDrive),
    RightDrive(RightDrive),
    Inertial(Inertial),
    gearRatio(gearRatio),
    wheelDiameter(wheelDiameter)
{};

void Drivetrain::driveDistance(double targetDistance) {
    PID driveLeftPID(targetDistance, 0, 0, 0, 10, 0, 0, targetDistance, 0.1, 0.2, 0, 0.5, 0, 8);
    PID driveRightPID(targetDistance, 0, 0, 0, 10, 0, 0, targetDistance, 0.1, 0.2, 0, 0.5, 0, 8);
    
    while(!driveLeftPID.settled() || !driveRightPID.settled()) {
        Brain.Timer.clear();
        driveLeftPID.error = targetDistance - LeftDrive.position(turns) * (this->wheelDiameter) * M_PI * (this->gearRatio);
        driveRightPID.error = targetDistance - RightDrive.position(turns) * (this->wheelDiameter) * M_PI * (this->gearRatio);
        
        driveLeftPID.motorOutput = driveLeftPID.output();
        driveRightPID.motorOutput = driveRightPID.output();
        
        LeftDrive.spin(forward, driveLeftPID.motorOutput, pct);
        RightDrive.spin(forward, driveRightPID.motorOutput, pct);
        Brain.Timer.time();
        
        if(driveLeftPID.ifCalculateTime()) {
            driveLeftPID.timeTaken += Brain.Timer.time();
        }

        if(driveRightPID.ifCalculateTime()) {
            driveRightPID.timeTaken += Brain.Timer.time();
        }
    }
};

void Drivetrain::turnToHeading(double targetHeading) {
    PID turnPID(targetHeading, 0, 0, 0, 10, 0, 0, targetHeading, 1, 3, 0, 0.5, 0, 8);

    while(!turnPID.settled()) {
        Brain.Timer.clear();
        turnPID.error = getTurnError(Inertial.heading(), targetHeading);

        turnPID.motorOutput = turnPID.output();

        LeftDrive.spin(forward, turnPID.motorOutput, pct);
        RightDrive.spin(reverse, turnPID.motorOutput, pct);
        Brain.Timer.time();
    }
};
