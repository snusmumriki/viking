//
// Created by MI on 02/28/2018.
//

#ifndef VIKING_MACHINE_H
#define VIKING_MACHINE_H


#include "Envelop.h"
#include "PowerEnvelop.h"

int abs(int x);

struct MachineDir {
    float motor1Dir;
    float motor2Dir;
};

MachineDir dirs[7] = {
        {-1.f, 0.f},
        {0.f,  -1.f},
        {-1.f, 1.f},
        {1.f,  1.f},
        {1.f,  -1.f},
        {1.f,  0.f},
        {0.f,  1.f},
};

class Machine {
private:
    int currentCommand = 0;
    Envelop *currentEnvelop;
    MachineDir *currentDir;

    float motor1Power;
    float motor2Power;

    Envelop boundEnvelop;
    Envelop rotationEnvelop;
    PowerEnvelop powerEnvelop;
public:
    float getMotor1Power() const;

    float getMotor2Power() const;

    void setPower(int newCommand, float dt);

    void setCurrent(int newCommand);
};

#endif //VIKING_MACHINE_H
