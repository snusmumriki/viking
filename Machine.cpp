//
// Created by MI on 02/28/2018.
//

#include "Machine.h"

int abs(int x) {
    if (x >= 0) return x;
    else return -x;
}

Machine::Machine(const Envelop &boundEnvelop, const Envelop &rotationEnvelop, const PowerEnvelop &powerEnvelop,
                 const Controller &controller) : boundEnvelop(boundEnvelop), rotationEnvelop(rotationEnvelop),
                                                 powerEnvelop(powerEnvelop), controller(controller) {}

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
    else
        currentEnvelop = &boundEnvelop;
    currentDir = dirs + 3 + newCommand;
}

void Machine::setPower(float dt) {
    int newCommand = controller.getCommand(dt);
    if (newCommand != currentCommand) {
        if (currentEnvelop->isOver()) {
            setCurrent(newCommand);
            currentEnvelop->start();
        } else currentEnvelop->stop();
    }

    motor1Power = currentDir->motor1Dir * currentEnvelop->getPower(dt);
    motor2Power = currentDir->motor2Dir * currentEnvelop->getPower(dt);
}
