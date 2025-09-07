#include "drivetrain.h"

Drivetrain::Drivetrain(motor_group& LeftDrive, motor_group& RightDrive, inertial& Inertial, double gearRatio, double wheelDiameter):
    LeftDrive(LeftDrive),
    RightDrive(RightDrive),
    Inertial(Inertial),
    gearRatio(gearRatio),
    wheelDiameter(wheelDiameter)
{};

void Drivetrain::driveDistance(double targetDistance) {
    double leftError = targetDistance;
    PID driveLeftPID(leftError, 0, 0, 0, 10, 0, 0, targetDistance, 0.1, 0, 0.5, 0, 8);
    double leftDriveOutput = 0;
    while(!driveLeftPID.settled(leftError)) {
        leftError = targetDistance - LeftDrive.position(turns) * (this->wheelDiameter) * M_PI * (this->gearRatio);
        driveLeftPID.error = leftError;
        
        leftDriveOutput = driveLeftPID.output(leftError);
        driveLeftPID.motorPower = leftDriveOutput;
        
        LeftDrive.spin(forward, leftDriveOutput, pct);
    }
};

void Drivetrain::turnToHeading(double targetHeading) {};
