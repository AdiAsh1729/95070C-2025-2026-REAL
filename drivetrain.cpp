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
    PID driveLeftPID(targetDistance, targetDistance, 1.5, 0.00055, 0, 10, 0, 0, targetDistance, 0.5, /*0.2, 0, 0.5,*/ 0/*, 8*/);
    PID driveRightPID(targetDistance, targetDistance, 1.5, 0.00045, 0, 10, 0, 0, targetDistance, 0.5, /*0.2, 0, 0.5,*/ 0/*, 8*/);

    LeftDrive.resetPosition();
    RightDrive.resetPosition();

    do {
        //Brain.Timer.clear();
        driveLeftPID.error = targetDistance - LeftDrive.position(turns) * (this->wheelDiameter) * M_PI * (this->gearRatio);
        driveRightPID.error = targetDistance - RightDrive.position(turns) * (this->wheelDiameter) * M_PI * (this->gearRatio);
        
        driveLeftPID.motorOutput = driveLeftPID.output();
        driveRightPID.motorOutput = driveRightPID.output();
        
        LeftDrive.spin(forward, driveLeftPID.motorOutput, pct);
        RightDrive.spin(forward, driveRightPID.motorOutput, pct);
        
        /*if(driveLeftPID.ifCalculateTime()) {
            driveLeftPID.timeTaken += Brain.Timer.time();
        }

        if(driveRightPID.ifCalculateTime()) {
            driveRightPID.timeTaken += Brain.Timer.time();
        }*/
    } while(!driveLeftPID.settled() || !driveRightPID.settled());
    
    LeftDrive.stop(brake);
    RightDrive.stop(brake);
};

void Drivetrain::turnToHeading(double targetHeading) {
    PID turnPID(targetHeading, targetHeading, 0.15, 0, 0, 10, 0, 0, targetHeading, 3, /*3, 0, 0.5,*/ 0/*, 8*/);
    do {
        //Brain.Timer.clear();
        turnPID.error = getTurnError(Inertial.heading(), targetHeading);

        turnPID.motorOutput = turnPID.output();

        std::cout << turnPID.error << ", " << turnPID.motorOutput << std::endl;

        LeftDrive.spin(forward, turnPID.motorOutput, pct);
        RightDrive.spin(reverse, turnPID.motorOutput, pct);
        //Brain.Timer.timome();

        /*if(turnPID.ifCalculateTime()) {
            turnPID.timeTaken += Brain.Timer.time();
        }*/
    } while(!turnPID.settled());
};
