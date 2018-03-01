//
// Created by MI on 02/28/2018.
//

#include "PowerEnvelop.h"

PowerEnvelop::PowerEnvelop(float accelTime, float fixedTime, float power, float deccelTime,
                           float revAccelTime, float revPower, float revDeccelTime) :
        Envelop(accelTime, fixedTime, power, deccelTime),
        revPower(revPower), revKa(revPower / revAccelTime), revKd(revPower / deccelTime) {
    time4 = time3 + revAccelTime;
    time5 = time4 + revDeccelTime;
}

bool PowerEnvelop::isOver() {
    return time >= time5;
}

float PowerEnvelop::getPower(float dt) {
    float pwr = Envelop::getPower(dt);
    if (pwr) return pwr;
    else if (time < time4)
        return time * -revKa;
    else if (time < time5)
        return time * revKd - revPower;
    else return 0.0;
}
