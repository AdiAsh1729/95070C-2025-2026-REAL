#pragma once

#include "vex.h"
#include "robot-config.h"
#include <iostream>
using namespace vex;

enum Driver {
    Daniel,
    Thomas,
    Nikhil
};

inline Driver CurrentDriver = Daniel;
inline bool DriverButtonPressed = false;

void displayDriver();
void changeDriverRight();
void changeDriverLeft();
void ifDriverButtonPressed();
void selectDriver();
