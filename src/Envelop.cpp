//
// Created by MI on 02/23/2018.
//

#include "Envelop.h"

Envelop::Envelop(float accelTime, float fixedTime, float power, float deccelTime) :
        power(power), ka(power / accelTime), kd(power / deccelTime) {
    time1 = accelTime;
    time2 = time1 + fixedTime;
    time3 = time2 + deccelTime;
}

void Envelop::start() {
    time = 0.f;
}

void Envelop::stop() {
    if (time < time1)
        time = time3 + (power - ka * time) / kd;
    else time = time3;
}

bool Envelop::fixedIsOver() {
    return time > time2;
}

bool Envelop::isOver() {
    return time >= time3;
}

float Envelop::getPower(float dt) {
    time += dt;
    if (time < time1)
        return time * ka;
    else if (time <= time2)
        return power;
    else if (time < time3)
        return power - time * kd;
    else return 0.0;
}

