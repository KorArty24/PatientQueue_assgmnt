#include "patientnode.h"

PatientNode::PatientNode(std::string name, int priority, PatientNode* next) {
    this->name = name;
    this->priority = priority;
    this->next = next;
}

std::ostream& operator <<(std::ostream& out, const PatientNode& node) {
    return out << node.priority << ":" << node.name;
}

