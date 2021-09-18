/*************************************************************
 * File: VectorPQueue.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "VectorPQueue.h";
#include "error.h";
#include <vector.h>;
#include "patientwithpriority.h"
#include <iterator>

using namespace std;
Vector<std::string> ParseString(const std::string &value);

VectorPriorityQueue::VectorPriorityQueue() {
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() const {
return _patientWithPriotiry.size();
}

bool VectorPriorityQueue::isEmpty() const {
    _patientWithPriotiry.size()==0;

}

void VectorPriorityQueue::enqueue(const std::string& value) {
    Vector<string> v=ParseString(value);
    //PatientWithPriority patient()
    _patientWithPriotiry.push_back(PatientWithPriority(v[0],stoi(v[1]),stoi(v[2])));


}

string VectorPriorityQueue::peek() const {
    int element=findlargest(_patientWithPriotiry);
    int t=getOneWithHighestPriority(_patientWithPriotiry,element);
    PatientWithPriority patient=_patientWithPriotiry[t];
    string patientName=patient.getName();
}

string VectorPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	
	return "";
}

Vector<std::string> ParseString(const std::string &value){

    Vector<std::string> str;
    for (int i =0; i<value.size(); i++){
        int pos=0;
        if(value[i] == ' '){
            str.add(value.substr(pos,i));
            pos=pos+i+1;
        }
    }
    return str;
}

void fillInPatientInfo(Vector<std::string> vc,PatientWithPriority patient){
    patient.setName(vc[0]);
    patient.SetPriority(std::stoi(vc[1]));
    patient.SetTimeStamp(std::stoi(vc[1]));
}

int VectorPriorityQueue::findlargest(Vector<PatientWithPriority> _vector) const{
    int max = _vector[0].getPriority();
    int priority=0;
    for (int i=1;i<_vector.size();i++){
        priority=_vector[i].getPriority();
        if (priority>max){
            max = _vector[i].getPriority();
        }
    }
    return max;

}


int VectorPriorityQueue::getOneWithHighestPriority(Vector<PatientWithPriority> _vector, int element) const {
    Vector<int> patientsWithHighestPriority;
    try {
        if (_vector.size()!=0){
            int p=_vector[0].getTimeStamp();
            int numpat;
            for(int i=0; i<=_vector.size();i++){
                if (_vector[i].getPriority()==element){
                    patientsWithHighestPriority.add(i);
                }
            }
            for (int t=1; t<patientsWithHighestPriority.size(); t++){
                if (_vector[t].getTimeStamp() > p){
                    p=_vector[t].getTimeStamp();
                    numpat=t;
                }
            }
            return numpat;
        } else {
            throw (_vector.size());
        }
    }  catch (...) {
        cout << "Queue is empty!!\n";
    }
    return 0;
}
