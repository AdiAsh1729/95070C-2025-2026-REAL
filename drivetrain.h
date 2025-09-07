#pragma once

#include "vex.h"
#include "PID.h"
#include <iostream>
using namespace vex;

class Drivetrain {
    public:
        motor_group& LeftDrive;
        motor_group& RightDrive;
        inertial& Inertial;

        double gearRatio;
        double wheelDiameter;

        Drivetrain(motor_group& LeftDrive, motor_group& RightDrive, inertial& Inertial, double gearRatio, double wheelDiameter);

        void driveDistance(double targetDistance);
        void turnToHeading(double targetHeading);
};
