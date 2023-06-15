#include "Model.h"
#include "System.h"
#include "Flow.h"
#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <cstdlib>

using namespace std;

Model::Model(){
    //ctor
    name = "";
    time = 0;
}

Model::Model(string name, double time){
    //ctor
    this->name = name;
    this->time = time;
}

Model::Model(const Model& obj){
    name = obj.name;
    time = obj.time;

    Model::systemIterator systemIt;
    Model::flowIterator flowIt;
    
 
    for(unsigned int i=0; i<obj.systems.size(); i++){
        (systems).push_back(obj.systems[i]);
    }
    for(unsigned int i=0; i<obj.flows.size(); i++){
        (flows).push_back(obj.flows[i]);
    }
}

Model::~Model(){
    //dtor
}

void Model::add(System* system){
    systems.push_back(system);
}

void Model::add(Flow* flow){
    flows.push_back(flow);
}

void Model::run(int timeStart, int timeEnd, int timeVariance){
    
    Model::systemIterator systemIt;
    Model::flowIterator flowIt;

    System *sourceValue, *destinyValue;

    for(int i = timeStart; i < timeEnd; i+=timeVariance){
        for(flowIt = flowBegin(); flowIt < flowEnd(); flowIt++){
            (*flowIt)->setValue((*flowIt)->execute());
        }

        for(flowIt = flowBegin(); flowIt < flowEnd(); flowIt++){
            sourceValue = (*flowIt)->getSource();
            sourceValue->setValue(sourceValue->getValue() - (*flowIt)->getValue());

            destinyValue = (*flowIt)->getDestiny();
            destinyValue->setValue(destinyValue->getValue() + (*flowIt)->getValue());
        }
        time++;
    }

}

Model& Model::operator=(const Model& rhs){
    if(this == &rhs)
        return *this;

    name = rhs.name;
    time = rhs.time;


    systems.clear();
    flows.clear();



    for(unsigned int i=0; i<rhs.systems.size(); i++){
        (systems).push_back(rhs.systems[i]);
    }
    for(unsigned int i=0; i<rhs.flows.size(); i++){
        (flows).push_back(rhs.flows[i]);
    }

    return *this;
}


// /**
//  * Breve descrição da função/método.
//  *
//  * Descrição mais detalhada da função/método.
//  * Pode ser várias linhas.
//  *
//  * @param  Descrição do primeiro parâmetro.
//  * recebe um void

//  * @return Descrição do valor de retorno (se houver).
//     returna um ponteiro para inicio do intereitor
//  */
Model::systemIterator Model::systemBegin(void){
    return systems.begin();
}

// /**
//  * Breve descrição da função/método.
//  *
//  * Descrição mais detalhada da função/método.
//  * Pode ser várias linhas.
//  *
//  * @param parametro1 Descrição do primeiro parâmetro.
//  * @return Descrição do valor de retorno (se houver).
//  */
Model::systemIterator Model::systemEnd(void){
    return systems.end();
}

Model::flowIterator Model::flowBegin(void){
    return flows.begin();
}

Model::flowIterator Model::flowEnd(void){
    return flows.end();
}

void Model::setName(const string name){
    this->name = name;
}

void Model::setTime(const double time){
    this->time = time;
}

string Model::getName() const{
    return name;
}

double Model::getTime() const{
    return time;
}
