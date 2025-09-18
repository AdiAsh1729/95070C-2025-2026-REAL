#pragma once

#include "vex.h"
#include "PID.h"
#include "util.h"
#include <iostream>
using namespace vex;

class Drivetrain {
    public:
        brain& Brain;
        motor_group& LeftDrive;
        motor_group& RightDrive;
        inertial& Inertial;

        double gearRatio;
        double wheelDiameter;

        Drivetrain(brain& Brain, motor_group& LeftDrive, motor_group& RightDrive, inertial& Inertial, double gearRatio, double wheelDiameter);

        void driveDistance(double targetDistance);
        void turnToHeading(double targetHeading);
};
