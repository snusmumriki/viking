//
// Created by MI on 02/18/2018.
//

#include <cmath>
#include "Controller.h"

float error(int left1, int left, int right, int right1) {
    return (float) (left1 * -3 + left * -1 + right * 1 + right1 * 3) / (float) ((left1 + left + right + right1) * 3);
}

float error(int data1, int data2) {
    return (float) (data2 - data1) / (float) (data1 + data2);
}

int sgn(float x, float lim) {
    return (x > lim) - (x < -lim);
}

Controller::Controller(float emptyLim, float rotateLim, float lightLim, float sideLim,
                       const Pid &distPid, const Pid &light1Pid, const Pid &light2Pid) :
        emptyLim(emptyLim), rotateLim(rotateLim), lightLim(lightLim), sideLim(sideLim),
        distPid(distPid), light1Pid(light1Pid), light2Pid(light2Pid) {}

int Controller::bound(SensDat4 *lightData, float dt) {
    float err1 = light1Pid.output(error(lightData->data1, lightData->data2), dt);
    float err2 = light2Pid.output(error(lightData->data3, lightData->data4), dt);
    if (err1 > err2) return sgn(err1, lightLim) * 2;
    else return sgn(err2, lightLim) * 3;
}

int Controller::distance(SensDat4 *distData, SensDat2 *sideData, float dt) {
    float err1 = error(distData->data1, distData->data3);
    float err2 = error(distData->data2, distData->data4);
    if ((fabsf(err1) + fabsf(err2)) / 2.f > emptyLim) {
        float output = distPid.output(error(distData->data1, distData->data2, distData->data3, distData->data4), dt);
        return sgn(output, rotateLim);
    } else return 2;
}

int Controller::side(SensDat2 *sideData) {
    return sgn(error(sideData->data1, sideData->data2), lightLim);
}

int Controller::getCommand(SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt) {
    int num = bound(lightData, dt);
    if (num) return num;
    num = distance(distData, sideData, dt);
    if (num != 2) return num;
    num = side(sideData);
    if (num) return num;
    return sgn(distPid.feedback(dt), lightLim);
}



