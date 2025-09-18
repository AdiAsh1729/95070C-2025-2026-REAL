#pragma once

#include <cmath>

class PID {
    public:
        double error;
        double kp;
        double ki;
        double kd;
        
        double startIntegral;
        double integral;
        double derivative;
        double previousError;

        double deadband;
        double startTime;
        double timeTaken;
        double timeGiven;
        double motorOutput;
        double powerGiven;

        PID(double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband, double startTime, double timeTaken, double timeGiven, double motorOutput, double powerGiven);

        bool settled();
        bool ifCalculateTime();
        double output();
};
