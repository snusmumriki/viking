//
// Created by MI on 02/28/2018.
//

#ifndef VIKING_MACHINE_H
#define VIKING_MACHINE_H


#include "Envelop.h"
#include "PowerEnvelop.h"

int abs(int x);

class Machine {
private:
    int currentCommand = 0;
    Envelop *lastEnvelop;

    Envelop boundEnvelop;
    Envelop rotationEnvelop;
    PowerEnvelop powerEnvelop;
public:
    void getPower(int command, float dt, float *motor1Power, float *motor2Power);

    void setCurrentEnvelop();

    void setCurrentEnvelop(int command);
};


#endif //VIKING_MACHINE_H
