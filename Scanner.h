//
// Created by MI on 02/18/2018.
//

#ifndef VIKING_SCANNER_H
#define VIKING_SCANNER_H

#include "Pid.h"

struct SensDat4 {
    int data1;
    int data2;
    int data3;
    int data4;
};
struct SensDat2 {
    int data1;
    int data2;
};

float error(int data1, int data2, int data3, int data4);

float error(int data1, int data2);

class Scanner {
private:
    float emptyLim;
    float powerLim;
    float lightLim;
    float sideLim;

    Pid distPid;
    Pid light1Pid;
    Pid light2Pid;
public:
    float output(SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt);
};

#endif //VIKING_SCANNER_H
