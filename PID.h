#pragma once

class PID {
    public:
        double error;
        double kp;
        double ki;
        double kd;
        
        double startIntegral; //when to start calculating integral
        double integral;
        double derivative;
        double previousError;

        double deadband; //how far off you can be
        double timeTaken; //how much time your PID has taken around the target
        double timeGiven; //how much time you have allotted for the PID
        double motorPower; //how much power your motor is at
        double powerGiven; //at how much power you should stop spinning

        PID(double error, double kp, double ki, double kd, double startIntegral, double integral, double derivative, double previousError, double deadband, double timeTaken, double timeGiven, double motorPower, double powerGiven);

        bool settled(double error);
        double output(double error);
};
