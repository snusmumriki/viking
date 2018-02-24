//
// Created by MI on 02/23/2018.
//

#ifndef VIKING_ENVELOP_H
#define VIKING_ENVELOP_H


class Envelop {
private:
    float time1;
    float time2;
    float time3;
    float power;
    float ka;
    float kd;

    float time;
public:
    Envelop(float accelt, float fixedt, float power, float deccelt);

    void start();

    float getPower(float dt);

    void stop();
};


#endif //VIKING_ENVELOP_H
