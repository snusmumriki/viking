//
// Created by MI on 02/28/2018.
//

#include "Machine.h"

int abs(int x) {
    if (x >= 0) return x;
    else return -x;
}

float Machine::getMotor1Power() const {
    return motor1Power;
}

float Machine::getMotor2Power() const {
    return motor2Power;
}

void Machine::setCurrent(int newCommand) {
    if (newCommand == 0)
        currentEnvelop = &powerEnvelop;
    else if (abs(newCommand) == 1)
        currentEnvelop = &rotationEnvelop;
    else currentEnvelop = &boundEnvelop;
    currentDir = dirs + 3 + newCommand;

}

void Machine::setPower(int command, float dt) {

    if (command != currentCommand)
        currentEnvelop->stop();

}
