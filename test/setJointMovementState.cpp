#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#define sleep(x) Sleep((x)*1000)
#endif

#include <iostream>
#include "barobo/linkbot.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <serial_id>"<<std::endl;
        return 0;
    }

    Linkbot *l = new Linkbot();
    sleep(2);
    l->connect(argv[1]);
    l->setJointMovementStateNB(ROBOT_JOINT1, ROBOT_FORWARD);
    sleep(3);
    l->setJointMovementStateNB(ROBOT_JOINT1, ROBOT_BACKWARD);
    sleep(3);
    l->setJointMovementStateNB(ROBOT_JOINT1, ROBOT_NEUTRAL);

    return 0;
}

