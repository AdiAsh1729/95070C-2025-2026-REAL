#include "PID.h"

PID::PID(double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband, double startTime, double timeTaken, double timeGiven, double motorOutput, double powerGiven):
    error(error),
    kp(kp),
    ki(ki),
    kd(kd),
    startIntegral(startIntegral),
    integral(integral),
    derivative(derivative),
    previousError(previousError),
    deadband(deadband),
    startTime(startTime),
    timeTaken(timeTaken),
    timeGiven(timeGiven),
    motorOutput(motorOutput),
    powerGiven(powerGiven)
{};

bool PID::settled() {
    if(error < deadband || timeTaken > timeGiven || motorOutput < powerGiven) {
        return true;
    }

    else {
        return false;
    }
};

bool PID::ifCalculateTime() {
    if(error < startTime) {
        return true;
    }

    else {
        return false;
    }
}

double PID::output() {
    this->derivative = error - previousError;
    
    if(fabs(error) < startIntegral) {
        this->integral += error;
    }
    
    previousError = error;

    return error * kp + integral * ki + derivative * kd;
};
