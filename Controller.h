//
// Created by MI on 02/18/2018.
//

#ifndef VIKING_SCANNER_H
#define VIKING_SCANNER_H

#include "Pid.h"

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
    Pid sidePid;
    Pid light1Pid;
    Pid light2Pid;
public:
    struct {
        int data1;
        int data2;
        int data3;
        int data4;
    } distData, lightData;

    struct {
        int data1;
        int data2;
    } sideData;

    Controller(float emptyLim, float rotateLim, float lightLim, float sideLim, const Pid &distPid, const Pid &sidePid,
               const Pid &light1Pid, const Pid &light2Pid);

    int getCommand(float dt);

    int bound(float dt);

    int rotation(float dt);

    int side(float dt);
};

#endif //VIKING_SCANNER_H
