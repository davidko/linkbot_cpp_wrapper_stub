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
    l->move(90, 90, 90);
    l->move(-90, -90, -90);
    l->setMovementStateTime(
            ROBOT_FORWARD, ROBOT_FORWARD, ROBOT_FORWARD, 3);
    l->setMovementStateTime(
            ROBOT_BACKWARD, ROBOT_BACKWARD, ROBOT_BACKWARD, 3);
    l->setMovementStateTime(
            ROBOT_POSITIVE, ROBOT_POSITIVE, ROBOT_POSITIVE, 3);
    l->setMovementStateTime(
            ROBOT_NEGATIVE, ROBOT_NEGATIVE, ROBOT_NEGATIVE, 3);
    return 0;
}
