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

Pid::Pid(float kp, float ki, float kd, float sErr) : kp(kp), ki(ki), kd(kd), sErr(sErr) {}

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

float Pid::output(float err, float dt) {
    float pwr = sErr + prop(err) + diff(err, dt) + integral(err, dt);
    err0 = err;
    return pwr;
}

float Pid::feedback(float dt) {
    return normalize(output(i, dt));
}