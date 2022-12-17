#include "ArmSegment.h"

#include <sstream>
#include <cmath>

#define pi 3.14159265359

ArmSegment::ArmSegment(double length, double angle, double maxAngle) {
    //change syntax when this works
    glm::vec3 tempendpoint(0,0,0);       
    endPoint = tempendpoint;
    glm::vec3 tempmountpoint(0,0,0);
    mountPoint = tempmountpoint;
    calculatedAngle=0;
    
    this->angle = angle;
    this->length = length;
    this->maxAngle = maxAngle;
}


void ArmSegment::updateEndpoint(ArmSegment mountedOnArm) {
    calculatedAngle = mountedOnArm.calculatedAngle + angle;
    // NOTE: Angle is 90 degrees shifted counter clock wise.
    endPoint.x = mountedOnArm.endPoint.x + (length * cos(toRadians(calculatedAngle))); 
    endPoint.y = mountedOnArm.endPoint.y + (length * sin(toRadians(calculatedAngle)));
    
    mountPoint.x = mountedOnArm.endPoint.x;
    mountPoint.y = mountedOnArm.endPoint.y;
    mountPoint.z = mountedOnArm.endPoint.z;
}

double ArmSegment::toRadians(double angleInDegrees){
    return (angleInDegrees * pi)  / 180.0; //TODO: maybe turn into double
}

double ArmSegment::toDegrees(double radians) {
    return radians * (180.0 / pi);
}

std::string ArmSegment::toString() {
    return "Arm mountpoint:" + doubleToString(mountPoint.x) + "," +
    doubleToString(mountPoint.y) + 
    " endpoint:" + doubleToString(endPoint.x) + "," + doubleToString(endPoint.y);
}

void ArmSegment::setAngle(double d) {
    this->angle = d;
}

void ArmSegment::rotateMe(glm::vec3 targetEndpoint, glm::vec3 armEndpoint) {
    glm::vec3 r;//target
    glm::vec3 p;//current
    glm::vec3 cross;
    r.x = targetEndpoint.x - mountPoint.x;
    r.y = targetEndpoint.y - mountPoint.y;
    r.z = targetEndpoint.z - mountPoint.z;
    p.x = armEndpoint.x - mountPoint.x;
    p.y = armEndpoint.y - mountPoint.y;
    p.z = armEndpoint.z - mountPoint.z;
    double vDot = glm::dot(p, r)/(glm::length(p)*glm::length(r));
    if(vDot < -1.0) vDot = -1.0;
    if(vDot > 1.0) vDot = 1.0;
    double adiff = glm::degrees(glm::acos(vDot)); //angle difference betweem p and r
    cross = glm::cross(r, p); //doublecheck if r or p should be used or if it dousnt matter
    // Which way to rotate  3d trick
    if ( adiff < 10 ) {
        adiff /= 1 ;
    }
    else if ( adiff < 30 ) {
        adiff /= 2 ;
    }
    else if ( adiff < 60 ) {
        adiff /= 3 ;
    }
    else {
        adiff /= 4 ;
    }
    
    if (cross.z > 0) {
        angle = angle - adiff;
    }
    else {
        angle = angle + adiff;            
    }
    if ( angle > maxAngle ) angle = maxAngle ; 
    if ( angle < -maxAngle ) angle = -maxAngle ; 
}

std::string ArmSegment::doubleToString(double value){
    std::ostringstream strs;
    strs << value;
    std::string str = strs.str();
    return str;
}