//
// Created by MI on 02/18/2018.
//

#include <cmath>
#include "Scanner.h"

float error(int left1, int left, int right, int right1) {
    return (float) (left1 * -3 + left * -1 + right * 1 + right1 * 3) / (float) ((left1 + left + right + right1) * 3);
}

float error(int data1, int data2) {
    return (float) (data2 - data1) / (float) (data1 + data2);
}

float Scanner::output(struct SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt) {
    float err1 = light1Pid.power(error(lightData->data1, lightData->data2), dt);
    float err2 = light2Pid.power(error(lightData->data3, lightData->data4), dt);
    if (fabsf(err1) > zeroLim || fabsf(err2) > zeroLim) {
        if (fabsf(err1) > fabsf(err2))
            return copysignf(2.0, err1);
        else return copysignf(3.0, err2);
    }

    err1 = error(distData->data1, distData->data3);
    err2 = error(distData->data2, distData->data4);
    float output;
    if ((fabsf(err1) + fabsf(err2)) / 2.f > emptyLim) {
        output = distPid.power(error(distData->data1, distData->data2, distData->data3, distData->data4), dt);
        if (fabsf(output) > rotateLim)
            return (int) copysignf(1.0, output);
        else return 0;
    } else {
        output = distPid.power(fabsf(error(sideData->data1, sideData->data2)) > zeroLim, dt);
        if (fabsf(output) > zeroLim)
            return (int) copysignf(1.0, output);
    }

    return distPid.feedback(dt);
}


