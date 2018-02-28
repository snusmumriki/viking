//
// Created by MI on 02/28/2018.
//

#ifndef VIKING_MACHINE_H
#define VIKING_MACHINE_H


#include "Envelop.h"
#include "PowerEnvelop.h"

class Machine {
private:
    int lastCommand = 0;

    Envelop lineEnvelop;
    Envelop rotationEnvelop;
    PowerEnvelop powerEnvelop;
public:
    void getPower(int command, float dt, float *motor1Power, float *motor2Power);
};


#endif //VIKING_MACHINE_H
