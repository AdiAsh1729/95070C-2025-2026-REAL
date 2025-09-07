#include "PID.h"
#include <cmath>

PID::PID(double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband, double timeTaken, double timeGiven, double motorPower, double powerGiven):
    error(error),
    kp(kp),
    ki(ki),
    kd(kd),
    startIntegral(startIntegral),
    integral(integral),
    derivative(derivative),
    previousError(previousError),
    deadband(deadband),
    timeTaken(timeTaken),
    timeGiven(timeGiven),
    motorPower(motorPower),
    powerGiven(powerGiven)
{};

bool PID::settled(double error) {
    if(error < deadband || timeTaken > timeGiven || motorPower < powerGiven) {
        return true;
    }

    else {
        return false;
    }
};

double PID::output(double error) {
    this->derivative = error - previousError;
    
    if(fabs(error) < startIntegral) {
        this->integral += error;
    }
    
    previousError = error;

    return error * kp + integral * ki + derivative * kd;
};
