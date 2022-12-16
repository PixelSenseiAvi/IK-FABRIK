#include "Fabrik.h"

void FABRIK::backward()
{

}

void FABRIK::forward()
{
    
}

SKELETON FABRIK::SolveIK()
{
    for(size_t i =0; i< MAX_ITERATIONS; i++)
    {
        forward();
        if(skeleton[0]->startPos)
            backward();
    }

}

float FABRIK::CalculateError(glm::vec2 a, glm::vec2 b)
{

}
