#pragma once

#include "util.h"
#include <cmath>
#include <iostream>

class PID {
    public:
        double startError;
        double error;
        double kp;
        double ki;
        double kd;
        
        double startIntegral;
        double integral;
        double derivative;
        double previousError;

        double deadband;
        //double startTime;
        //double timeTaken;
        //double timeGiven;
        double motorOutput;
        //double powerGiven;

        PID(double startError, double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband, /*double startTime, double timeTaken, double timeGiven,*/ double motorOutput/*, double powerGiven*/);

        bool settled();
        //bool ifCalculateTime();
        double output();
};
