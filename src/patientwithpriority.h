#ifndef PATIENTWITHPRIORITY_H
#define PATIENTWITHPRIORITY_H
#include <string>

class PatientWithPriority
{
private:
    std::string _name;
    int _priority;
    int _timestmp;

public:
    /*
     * Constructor: PatientWithPriority
     * Usage: PatientWithPriority(name, priority, timestamp)
     *---------------
     *Creates a Patient sets priority and timestamp
*/

    PatientWithPriority(std::string Name, int priority, int timestamp);
    std::string getName();
    void setName(std::string name);
    int getPriority(){return _priority;}
    int getTimeStamp(){return _timestmp;}
    void SetPriority(int priority);
    void SetTimeStamp(int timestamp);


};

#endif // PATIENTWITHPRIORITY_H
