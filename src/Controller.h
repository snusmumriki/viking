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

float error(int left1, int left, int right, int right1);

float error(int data1, int data2);

int sgn(float x, float lim);

class Controller {
private:
    float emptyLim;
    float rotateLim;
    float lightLim;
    float sideLim;

    Pid distPid;
    Pid light1Pid;
    Pid light2Pid;

public:
    Controller(float emptyLim, float rotateLim, float lightLim, float sideLim,
               const Pid &distPid, const Pid &light1Pid, const Pid &light2Pid);

    int getCommand(SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt);

    int bound(SensDat4 *lightData, float dt);

    int distance(SensDat4 *distData, SensDat2 *sideData, float dt);

    int side(SensDat2 *sideData);
};

#endif //VIKING_SCANNER_H
