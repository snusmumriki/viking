//
// Created by MI on 02/23/2018.
//

#ifndef VIKING_ENVELOP_H
#define VIKING_ENVELOP_H


class Envelop {
protected:
    float time1;
    float time2;
    float time3;
    float power;
    float ka;
    float kd;

    float time = 0.0;
public:
    Envelop(float accelt, float fixedt, float power, float deccelt);

    void start();

    void stop();

    bool isOver();

    float getPower(float dt);

};


#endif //VIKING_ENVELOP_H
