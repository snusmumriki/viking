//
// Created by MI on 02/11/2018.
//

#include "Pid.h"

Pid::Pid(float kp, float ki, float kd) {
    Pid::kp = kp;
    Pid::ki = ki;
    Pid::kd = kd;
}

void Pid::setKp(float kp) {
    Pid::kp = kp;
}

void Pid::setKi(float ki) {
    Pid::ki = ki;
}

void Pid::setKd(float kd) {
    Pid::kd = kd;
}

float Pid::prop(float error) {
    return kp * error;
}

float Pid::diff(float error, float dt) {
    float d = kd * (error - error0) / dt;
    if (d > 1.f)
        d = 1.f;
    if (d < -1.f)
        d = -1.f;
    return d;
}

float Pid::integral(float error, float dt) {
    float i = ki * (error + error0) / 2.f * dt;
    if (i > 1.f)
        i = 1.f;
    if (i < -1.f)
        i = -1.f;
    return i;
}

float Pid::output(float error, float dt) {
    float pwr = prop(error) + diff(error, dt) + integral(error, dt);
    error0 = error;
    return pwr;
}
