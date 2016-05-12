#include "Job.h"
#include <iostream>
#include <sstream>

int Job::number = 0;

Job::Job(int priority) {
    this->priority = priority;
    id = number;
    number++;
    nextJob = NULL;
}

void Job::setPriority(int priority) {
    this->priority = priority;
}

int Job::getPriority() const {
    return priority;
}

void Job::setNext(Job *job) {
    nextJob = job;
}

Job* Job::getNext() const {
    return nextJob;
}

string Job::toString() {
    ostringstream out;
     out << '[' << id << ':'<< priority << ']';
    return out.str();
}

void Job::setId(int id) {
    this->id = id;
}

int Job::getId() const {
    return id;
}
