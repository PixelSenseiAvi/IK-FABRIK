#pragma once
#include "glm/glm.hpp"

struct arm{
    glm::vec3 startPos;
    float length;
    int angle;
    arm* next;
};

//SKELETON can be defined as an array of arm (at the moment for simpler problems)
#define SKELETON arm*