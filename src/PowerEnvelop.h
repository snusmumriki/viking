//
// Created by MI on 02/28/2018.
//

#ifndef VIKING_POWERENVELOP_H
#define VIKING_POWERENVELOP_H


#include "Envelop.h"

class PowerEnvelop : public Envelop {
protected:
    float time4;
    float bpower;
    float time5;
    float kab;
    float kdb;
public:
    PowerEnvelop(float accelt, float fixedt, float power, float deccelt, float baccelt, float bpower, float bdeccelt);

    float getPower(float dt);

    bool isOver();
};


#endif //VIKING_POWERENVELOP_H
