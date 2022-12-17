#include "Arm.h"
#include "ArmSegment.h"
#include <vector>
#include <string>
#include <iostream>

#define numSegments 3

Arm::Arm(){
    segments.push_back(ArmSegment(150.0,0.0,300));
    segments.push_back(ArmSegment(150.0,0.0,300));
    segments.push_back(ArmSegment(140.0,0.0,300));
}

void Arm::reset() {
    for(int i=0;i<numSegments;i++){                
        segments[i].setAngle(0);
    }
    //debug
    std::cout << "Arm.reset()\n";
}

std::string Arm::toString() {
    return segments[segments.size()-1].toString();
}

void Arm::updateArm() {
    ArmSegment mountPoint(0.0,0.0,0) ;
    for(int i=0;i<numSegments;i++){                
        segments[i].updateEndpoint(mountPoint);
        std::cout << "\n DURING POSITION FOR : ";  
        std::cout <<  segments[i].toString() + "\n";
        mountPoint = segments[i];
    }
    // Endpoint arm is endpoint last segement.
    endPoint = segments[segments.size()-1].endPoint;
 }

void Arm::setArmAngle(double d,int armIndex) {
    segments.at(armIndex).setAngle(d);
}

void Arm::moveEndpointToDest(glm::vec3 ep){
    int back = numSegments - 1 ;  // Last arm segment index.
    int loopcount = 0 ;
    
    while (!Equal(ep,endPoint)) { 
        if ( loopcount++ == 100 ) break ;
        while ( back >= 0 ) {
            segments[back].rotateMe(ep, endPoint) ;
            updateArm();
            back-- ;
        }
        //gc.clearRect(0, 0, 600, 250);
        // drawArm() ;
        //INSERT REAL ARM CODE HERE
        
        back = numSegments - 1 ;
       // std::cout << loopcount + "\n";
       // Thread.sleep(20);
        //System.out.println(loopcount);
    }
    //INSTER REAL ARM CODE HERE
    //drawArm();
}


bool Arm::Equal(const glm::vec3 &vecA, const glm::vec3 &vecB) 
{ 
   const double epsilion = 0.0001;  // choose something apprpriate.

   return    fabs(vecA[0] -vecB[0]) < epsilion   
          && fabs(vecA[1] -vecB[1]) < epsilion   
          && fabs(vecA[2] -vecB[2]) < epsilion;
} 