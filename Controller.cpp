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

Controller::Controller(float emptyLim, float rotateLim, float zeroLim, const Pid &distPid, const Pid &light1Pid,
                       const Pid &light2Pid) : emptyLim(emptyLim), rotateLim(rotateLim), zeroLim(zeroLim),
                                               distPid(distPid), light1Pid(light1Pid), light2Pid(light2Pid) {}

int Controller::getCommand(struct SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt) {
    float err1 = light1Pid.output(error(lightData->data1, lightData->data2), dt);
    float err2 = light2Pid.output(error(lightData->data3, lightData->data4), dt);
    int sign = sgn(fmaxf(err1, err2), zeroLim);
    if (sign) return sign * (2 + (err2 > err1));

    err1 = error(distData->data1, distData->data3);
    err2 = error(distData->data2, distData->data4);
    if (fabsf(err1) + fabsf(err2) / 2.f > emptyLim) {
        float output = distPid.output(error(distData->data1, distData->data2, distData->data3, distData->data4), dt);
        return sgn(output, rotateLim);
    }

    sign = sgn(error(sideData->data1, sideData->data2), rotateLim);
    if (sign) return sign;

    return sgn(distPid.feedback(dt), zeroLim);
}



