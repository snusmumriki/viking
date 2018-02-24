//
// Created by MI on 02/11/2018.
//

#ifndef VIKING_PID_H
#define VIKING_PID_H

float normalize(float x);

class Pid {
public:
    Pid(float kp, float ki, float kd, float sErr);

    float prop(float err);

    float diff(float err, float dt);

    float integral(float err, float dt);

    float power(float err, float dt);

    float feedback(float dt);

private:
    float kp;
    float ki;
    float kd;
    float sErr;

    float err0 = 0.f;
    float i = 0.f;
};


#endif //VIKING_PID_H
