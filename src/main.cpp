#include <cmath>
#include "Arm.h"
#include <cstring>
#include <glm/glm.hpp>
#include <iostream>


int main() {
    Arm a;
    std::cout << "main is reached running program\n";
    //create new position vector
    glm::vec3 newDest(290.0, 150.0, 0.0);
    a.reset();
    a.updateArm();
    //move arm to new dest
    a.moveEndpointToDest(newDest);
    std::cout << "\n AFTER POSITION: ";  
    std::cout <<  a.toString()+"\n";
    
    return 0;
}