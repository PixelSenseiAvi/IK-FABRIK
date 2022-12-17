#pragma once
#include "glm/glm.hpp"
#include <string>

class ArmSegment{
    public:
        double calculatedAngle;  // Degrees
        glm::vec3 endPoint;
        glm::vec3 mountPoint;
        double length;
        double angle; // degrees
        double maxAngle; // degrees

    public: 
        ArmSegment(double length, double angle, double maxAngle);
        void updateEndpoint(ArmSegment mountedOnArm);
        double toRadians(double angleInDegrees);
        double toDegrees(double radians);
        std::string toString();
        void setAngle(double d);
        void rotateMe(glm::vec3 targetEndpoint, glm::vec3 armEndpoint);
        std::string doubleToString(double value);
};
