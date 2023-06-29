
#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowImpl.h"
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<Model*> ModelImpl::models;

// Model* Model::createModel() {
//     return ModelImpl::createModel();
// }

// Model* ModelImpl::createModel() {
//     Model* m = new ModelImpl();
//     models.push_back(m);
//     return m;
// }

ModelImpl::ModelImpl(string name, double time){
    //ctor
    this->name = name;
    this->time = time;
}

Model* Model::createModel(const string name, const double time) {
	return ModelImpl::createModel(name, time);
}

Model* ModelImpl::createModel(const string name, const double time) {
	Model *m = new ModelImpl(name, time);
	add(m);
	return m;
}


System* ModelImpl::createSystem(double value, string name) {
    System* s = new SystemImpl(name, value);
    add(s);
    return s;
}


ModelImpl::ModelImpl(const ModelImpl& obj){
    name = obj.name;
    time = obj.time;

    for(unsigned int i=0; i<obj.systems.size(); i++){
        systems.push_back(obj.systems[i]);
    }
    for(unsigned int i=0; i<obj.flows.size(); i++){
        flows.push_back(obj.flows[i]);
    }
}


ModelImpl::~ModelImpl(){
    //dtor
    ModelImpl::SystemIterator systemIt;
    ModelImpl::FlowIterator flowIt;
    for (systemIt = SystemBegin(); systemIt<SystemEnd(); systemIt++)
    delete (*systemIt);
    
    for (flowIt  = FlowBegin(); flowIt<FlowEnd(); flowIt++)
        delete (*flowIt);

    for (auto i = models.begin(); i<models.end(); i++)
        if (*i == this) {
            models.erase(i);
            break;
        }
}

void ModelImpl::add(System* system){
    systems.push_back(system);
}

void ModelImpl::add(Flow* flow){
    flows.push_back(flow);
}

void ModelImpl::add(Model* model){
    models.push_back(model);
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

    for(unsigned int i=0; i<rhs.systems.size(); i++){
        systems.push_back(rhs.systems[i]);
    }
    for(unsigned int i=0; i<rhs.flows.size(); i++){
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
