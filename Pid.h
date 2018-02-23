//
// Created by MI on 02/11/2018.
//

#ifndef VIKING_PID_H
#define VIKING_PID_H


class Pid {
public:
    Pid(float kp, float ki, float kd);

    void setKp(float kp);

    void setKi(float ki);

    void setKd(float kd);

    float prop(float err);

    float diff(float err, float t);

    float integral(float err, float t);

    float output(float err, float t);

private:
    float kp;
    float ki;
    float kd;

    float error0 = 0;
};


#endif //VIKING_PID_H
