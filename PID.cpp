#include "PID.h"

PID::PID(double startError, double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband/*, double startTime, double timeTaken, double timeGiven*/, double motorOutput/*, double powerGiven*/):
    startError(startError),
    error(error),
    kp(kp),
    ki(ki),
    kd(kd),
    startIntegral(startIntegral),
    integral(integral),
    derivative(derivative),
    previousError(previousError),
    deadband(deadband),
    //startTime(startTime),
    //timeTaken(timeTaken),
    //timeGiven(timeGiven),
    motorOutput(motorOutput)//,
    //powerGiven(powerGiven)
{};

bool PID::settled() {
    if((std::abs(this->error) < deadband)/* || (timeTaken > timeGiven) || (motorOutput < powerGiven)*/) {
        return true;
    }

    else {
        return false;
    }
};

/*bool PID::ifCalculateTime() {
    if(std::abs(error) < startTime) {
        return true;
    }

    else {
        return false;
    }
}*/

double PID::output() {
    this->derivative = (this->error - this->previousError) * 50;
    
    if(std::abs(this->error) < this->startIntegral) {
        this->integral += (this->error)/50;
    }

    if(getSign(this->error) != getSign(this->startError)) {
        this->integral = 0;
    }

    this->previousError = this->error;

    return this->error * this->kp + this->integral * this->ki + this->derivative * this->kd;

    wait(20, msec);
};
