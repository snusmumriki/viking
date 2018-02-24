//
// Created by MI on 02/23/2018.
//

#include "Envelop.h"

Envelop::Envelop(float accelt, float fixedt, float power, float deccelt) :
        accelt(accelt), fixedt(fixedt), power(power), deccelt(deccelt) {}

float Envelop::getPower(float dt) {
    time += dt;
    if (time < accelt) return power / accelt * time;
    if (time > accelt + fixedt && time < accelt)
        return power;
}

void Envelop::start() {
    time = 0.f;
}
