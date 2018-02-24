//
// Created by MI on 02/23/2018.
//

#ifndef VIKING_ENVELOP_H
#define VIKING_ENVELOP_H


class Envelop {
private:
    float accelt;
    float fixedt;
    float power;
    float deccelt;

    float time;
public:
    Envelop(float accelt, float fixedt, float power, float deccelt);

    void start();

    float getPower(float dt);
};


#endif //VIKING_ENVELOP_H
