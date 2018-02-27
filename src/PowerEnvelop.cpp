//
// Created by MI on 02/28/2018.
//

#include "PowerEnvelop.h"

PowerEnvelop::PowerEnvelop(float accelt, float fixedt, float power, float deccelt, float baccelt, float bpower,
                           float bdeccelt) : Envelop(accelt, fixedt, power, deccelt),
                                             time4(accelt + fixedt + deccelt + baccelt),
                                             time5(accelt + fixedt + deccelt + baccelt + bdeccelt), bpower(bpower),
                                             kab(bpower / baccelt), kdb(bpower / deccelt) {}

bool PowerEnvelop::isOver() {
    return time >= time5;
}

float PowerEnvelop::getPower(float dt) {
    time += dt;
    if (time < time1)
        return time * ka;
    else if (time <= time2)
        return power;
    else if (time < time3)
        return power - time * kd;
    else if (time < time4)
        return time * -kab;
    else if (time < time5)
        return time * kdb - bpower;
    else return 0.0;
}
