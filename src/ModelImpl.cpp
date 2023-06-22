
#include "ModelImpl.h"
#include "System.h"
#include "Flow.h"
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>

using namespace std;

ModelImpl::ModelImpl(string name, double time){
    //ctor
    this->name = name;
    this->time = time;
}

ModelImpl::ModelImpl(const ModelImpl& obj){
    name = obj.name;
    time = obj.time;

    for(int i=0; i<obj.systems.size(); i++){
        systems.push_back(obj.systems[i]);
    }
    for(int i=0; i<obj.flows.size(); i++){
        flows.push_back(obj.flows[i]);
    }
}

ModelImpl::~ModelImpl(){
    //dtor
}

void ModelImpl::add(System* system){
    systems.push_back(system);
}

void ModelImpl::add(Flow* flow){
    flows.push_back(flow);
}

void ModelImpl::run(int timeStart, int timeEnd, int timeVariance){
    
    ModelImpl::SystemIterator systemIt;
    ModelImpl::FlowIterator flowIt;

    System *sourceValue, *destinyValue;

    for(time = timeStart; time < timeEnd; time +=timeVariance){
        for(flowIt = FlowBegin(); flowIt < FlowEnd(); flowIt++){
            (*flowIt)->setValue((*flowIt)->execute());
        }

        for(flowIt = FlowBegin(); flowIt < FlowEnd(); flowIt++){
            sourceValue = (*flowIt)->getSource();
            sourceValue->setValue(sourceValue->getValue() - (*flowIt)->getValue());

            destinyValue = (*flowIt)->getDestiny();
            destinyValue->setValue(destinyValue->getValue() + (*flowIt)->getValue());
        }
    }
}

ModelImpl& ModelImpl::operator=(const ModelImpl& rhs){
    if(this == &rhs)
        return *this;

    name = rhs.name;
    time = rhs.time;

    systems.clear();
    flows.clear();

    for(int i=0; i<rhs.systems.size(); i++){
        systems.push_back(rhs.systems[i]);
    }
    for(int i=0; i<rhs.flows.size(); i++){
        flows.push_back(rhs.flows[i]);
    }

    return *this;
}

ModelImpl::SystemIterator ModelImpl::SystemBegin(void){
    return systems.begin();
}

ModelImpl::SystemIterator ModelImpl::SystemEnd(void){
    return systems.end();
}

ModelImpl::FlowIterator ModelImpl::FlowBegin(void){
    return flows.begin();
}

ModelImpl::FlowIterator ModelImpl::FlowEnd(void){
    return flows.end();
}

void ModelImpl::setName(const string name){
    this->name = name;
}

void ModelImpl::setTime(const double time){
    this->time = time;
}

string ModelImpl::getName() const{
    return name;
}

double ModelImpl::getTime() const{
    return time;
}
