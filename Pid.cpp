//
// Created by MI on 02/11/2018.
//

#include "Pid.h"

float normalize(float x) {
    if (x > 1.f)
        return 1.f;
    if (x < -1.f)
        return -1.f;
}

Pid::Pid(float kp, float ki, float kd) : kp(kp), ki(ki), kd(kd) {}

void Pid::setKp(float kp) {
    Pid::kp = kp;
}

void Pid::setKi(float ki) {
    Pid::ki = ki;
}

void Pid::setKd(float kd) {
    Pid::kd = kd;
}

void Pid::setSErr(float sErr) {
    Pid::sErr = sErr;
}

float Pid::prop(float err) {
    return kp * err;
}

float Pid::diff(float err, float dt) {
    float d = kd * (err - err0) / dt;
    return normalize(d);
}

float Pid::integral(float err, float dt) {
    i = ki * (err + err0) / 2.f * dt;
    return normalize(i);
}

float Pid::power(float err, float dt) {
    float pwr = sErr + prop(err) + diff(err, dt) + integral(err, dt);
    err0 = err;
    return pwr;
}

float Pid::feedback(float dt) {
    return normalize(power(i, dt));
}