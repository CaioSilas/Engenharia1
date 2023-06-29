

#include "FlowImpl.h"
#include <string>

using namespace std;


FlowImpl::FlowImpl(string name, System* source, System* destiny) : name(name),source(source),destiny(destiny) {}

FlowImpl::FlowImpl(const FlowImpl& obj){
    this->name = obj.name;
    this->value = obj.value;
    this->source = obj.source;
    this->destiny = obj.destiny;
}

FlowImpl::~FlowImpl(){
    //dtor
}

void FlowImpl::connect(System* source, System* destiny){
    this->source = source;
    this->destiny = destiny;
}   

FlowImpl& FlowImpl::operator=(const FlowImpl& rhs){
    if(this == &rhs)
        return *this;

    this->name = rhs.name;
    this->value = rhs.value;

    delete this->source;
    delete this->destiny;

    this->source = rhs.source;
    this->destiny = rhs.destiny;

    return *this;
}

void FlowImpl::setName(const string name){
    this->name = name;
}

void FlowImpl::setValue(const double value){
    this->value = value;
}

void FlowImpl::setSource(System* source){
    this->source = source;
}

void FlowImpl::setDestiny(System* destiny){
    this->destiny = destiny;
}

string FlowImpl::getName() const{
    return name;
}

double FlowImpl::getValue() const{
    return value;
}

System* FlowImpl::getSource() const{
    return source;
}

System* FlowImpl::getDestiny() const{
    return destiny;
}

