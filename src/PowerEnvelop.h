//
// Created by MI on 02/28/2018.
//

#ifndef VIKING_POWERENVELOP_H
#define VIKING_POWERENVELOP_H


#include "Envelop.h"

class PowerEnvelop : public Envelop {
protected:
    float time4;
    float revPower;
    float time5;
    float revKa;
    float revKd;
public:
    PowerEnvelop(float accelTime, float fixedTime, float power, float deccelTime,
                 float revAccelTime, float revPower, float revDeccelTime);

    bool isOver();

    float getPower(float dt);
};


#endif //VIKING_POWERENVELOP_H
