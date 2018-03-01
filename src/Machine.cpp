//
// Created by MI on 02/28/2018.
//

#include "Machine.h"

int abs(int x) {
    if (x >= 0) return x;
    else return -x;
}

void Machine::setCurrentEnvelop(int command) {
    if (command == 0)
        lastEnvelop = &powerEnvelop;
    else if (abs(command) == 1)
        lastEnvelop = &rotationEnvelop;
    else lastEnvelop = &boundEnvelop;
}

void Machine::getPower(int command, float dt, float *motor1Power, float *motor2Power) {

    if (command != currentCommand)
        lastEnvelop->stop();

}