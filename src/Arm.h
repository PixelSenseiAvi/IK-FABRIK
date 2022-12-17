#include <string>
#include <vector>
#include "glm/glm.hpp"
#include "ArmSegment.h"



class Arm {
     
    public:
        std::vector<ArmSegment> segments;
        glm::vec3 endPoint;
        Arm();
        void reset();
        std::string toString();
        void updateArm();
        void setArmAngle(double d, int armIndex);
        void moveEndpointToDest(glm::vec3 ep);
        bool Equal(const glm::vec3 &vecA, const glm::vec3 &vecB);
};  