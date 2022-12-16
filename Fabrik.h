#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Arm.h"

class FABRIK{
    public:
        SKELETON skeleton;
        float ErrorOfMargin = 0.01f;    //Magnitude

        glm::vec2 startPos = {0.0f, 0.0f};
        glm::vec2 goalPos;

        int MAX_ITERATIONS = 11;
    private:
        void backward();
        void forward();

        float CalculateError(glm::vec2 a, glm::vec2 b);
    public:
        SKELETON SolveIK();
};