//
// Created by MI on 02/23/2018.
//

#include "Envelop.h"

Envelop::Envelop(float accelt, float fixedt, float power, float deccelt) :
        time1(accelt), time2(accelt + fixedt), time3(accelt + fixedt + deccelt),
        power(power), ka(power / accelt), kd(power / deccelt) {}

void Envelop::start() {
    time = 0.f;
}

float Envelop::getPower(float dt) {
    time += dt;
    if (time < time1)
        return time * ka;
    else if (time <= time2)
        return power;
    else if (time < time3)
        return power - time * kd;
    else return 0;
}