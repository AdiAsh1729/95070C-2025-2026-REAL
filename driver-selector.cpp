#include "driver-selector.h"

void displayDriver() {
    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    switch(CurrentDriver) {
        case Daniel:
            Controller.Screen.print("Daniel");
            break;

        case Thomas:
            Controller.Screen.print("Thomas");
            break;

        case Nikhil:
            Controller.Screen.print("Nikhil");
            break;
    }
}

void changeDriverRight() {
    displayDriver();
    switch(CurrentDriver) {
        case Daniel:
            CurrentDriver = Thomas;
            displayDriver();
            break;

        case Thomas:
            CurrentDriver = Nikhil;
            displayDriver();
            break;

        case Nikhil:
            CurrentDriver = Daniel;
            displayDriver();
            break;
    }
}

void changeDriverLeft() {
    displayDriver();
    switch(CurrentDriver) {
        case Daniel:
            CurrentDriver = Nikhil;
            displayDriver();
            break;

        case Thomas:
            CurrentDriver = Daniel;
            displayDriver();
            break;

        case Nikhil:
            CurrentDriver = Thomas;
            displayDriver();
            break;
    }
}

void ifDriverButtonPressed() {
    DriverButtonPressed = true;
}
