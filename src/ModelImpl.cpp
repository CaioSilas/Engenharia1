
#include "ModelImpl.h"
#include "SystemImpl.h"
#include "FlowImpl.h"
#include "Flow.h"
#include "System.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>

using namespace std;

vector<Model*> ModelImpl::models;


System* ModelImpl::createSystem(const string name, const double value){
    System *sys = new SystemHandle(name, value);
    add(sys);
    return sys;
}

Model* Model::createModel(const string name, const double time){
    return ModelImpl::createModel(name, time);
}

Model* ModelImpl::createModel(const string name, const double time){
    Model *mod = new ModelHandle(name, time);
    add(mod);
    return mod;
}

void ModelImpl::deleteSystem(System* const system) {
	systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	for (auto f : flows) {
		if (f->getSource() == system)
			f->setSource(NULL);

		if (f->getDestiny() == system)
			f->setDestiny(NULL);
	}
}

void ModelImpl::deleteFlow(Flow* flow) {
	flows.erase(std::remove(flows.begin(), flows.end(), flow), flows.end());
}

void Model::deleteModel(Model* model) {
	ModelImpl::deleteModel(model);
}

void ModelImpl::deleteModel(Model* model) {
	models.erase(std::remove(models.begin(), models.end(), model), models.end());
	delete model;
}

ModelImpl::~ModelImpl(){
    //dtor
    for (auto sys : systems)
        deleteSystem(sys);
    for (auto f : flows) 
        deleteFlow(f);
}

ModelImpl::ModelImpl(string name, double time){
    //ctor
    this->name = name;
    this->time = time;
}

ModelImpl::ModelImpl(const ModelImpl& obj){
    name = obj.name;
    time = obj.time;

    for(int i=0; i<(int)obj.systems.size(); i++){
        systems.push_back(obj.systems[i]);
    }
    for(int i=0; i<(int)obj.flows.size(); i++){
        flows.push_back(obj.flows[i]);
    }
}


void ModelImpl::add(System* const system){
    systems.push_back(system);
}

void ModelImpl::add(Flow* const flow){
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
            if (sourceValue != NULL)
                sourceValue->setValue(sourceValue->getValue() - (*flowIt)->getValue());

            destinyValue = (*flowIt)->getDestiny();
            if (destinyValue != NULL)
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

    for(int i=0; i<(int)rhs.systems.size(); i++){
        systems.push_back(rhs.systems[i]);
    }
    for(int i=0; i<(int)rhs.flows.size(); i++){
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

ModelImpl::ModelIterator ModelImpl::ModelBegin(void){
    return models.begin();
}

ModelImpl::ModelIterator ModelImpl::ModelEnd(void){
    return models.end();
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
