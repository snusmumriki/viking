//
// Created by MI on 02/18/2018.
//

#include <cmath>
#include "Scanner.h"

float error(int data1, int data2, int data3, int data4) {
    return (float) (data1 * -3 + data2 * -1 + data3 * 1 + data4 * 3) / (float) ((data1 + data2 + data3 + data4) * 3);
}

float error(int data1, int data2) {
    return (float) (data2 - data1) / (float) (data1 + data2);
}

float Scanner::output(struct SensDat4 *distData, SensDat2 *sideData, SensDat4 *lightData, float dt) {
    float err1 = Scanner::light1Pid.output(error(lightData->data1, lightData->data4), dt);
    float err2 = Scanner::light2Pid.output(error(lightData->data2, lightData->data3), dt);

    if (fabsf(err1) > Scanner::lightLim || fabsf(err2) > Scanner::lightLim) {
        if (fabsf(err1) > fabsf(err2))
            return copysignf(2.0, err1);
        else return copysignf(3.0, err2);
    }

    err1 = error(distData->data1, distData->data3);
    err2 = error(distData->data2, distData->data4);
    float outp;
    if ((fabsf(err1) + fabsf(err2)) / 2.f > Scanner::emptyLim) {
        outp = Scanner::distPid.output(
                error(distData->data1, distData->data2, distData->data3, distData->data4), dt);
        if (fabsf(outp) > powerLim)
            return (int) copysignf(1.0, outp);
        else return 0;
    }

    outp = Scanner::distPid.output(fabsf(error(sideData->data1, sideData->data2)) > Scanner::sideLim, dt);
    if (fabsf(outp) > lightLim)
        return (int) copysignf(1.0, outp);
    

    return Scanner::distPid.output(Scanner::distPid.integral(0.0, dt), dt);
}


