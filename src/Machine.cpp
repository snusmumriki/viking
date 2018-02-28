//
// Created by MI on 02/28/2018.
//

#include "Machine.h"

void Machine::getPower(int command, float dt, float *motor1Power, float *motor2Power) {
    switch (command){
        case 0:
            float mp = powerEnvelop.getPower(dt);
    }
}
