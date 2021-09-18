#include "patientwithpriority.h"

PatientWithPriority::PatientWithPriority(std::string Name, int priority, int timestamp){
    _name=Name;
    _priority=priority;
    _timestmp=timestamp;
}

std::string PatientWithPriority::getName() {
    return _name;
}
void PatientWithPriority::setName(std::string name){
    _name=name;
}

void PatientWithPriority::SetPriority(int priority){
   _priority=priority;
}
void PatientWithPriority::SetTimeStamp(int timestamp){
    _timestmp=timestamp;
}

