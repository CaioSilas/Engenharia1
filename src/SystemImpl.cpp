

#include "SystemImpl.h"
#include <string>

using namespace std;

SystemImpl::SystemImpl(string name, double value){
    //ctor
    this->name = name;
    this->value = value;
}

SystemImpl::SystemImpl(const SystemImpl& obj){
    this->name = obj.name;
    this->value = obj.value;
}

SystemImpl::~SystemImpl(){
    //dtor
}

SystemImpl& SystemImpl::operator=(const SystemImpl& rhs){
    if(this == &rhs)
        return *this;

    this->name = rhs.name;
    this->value = rhs.value;
    
    return *this;
}

void SystemImpl::setName(const string name){
    this->name = name;
}

void SystemImpl::setValue(const double value){
    this->value = value;
}

string SystemImpl::getName() const{
    return name;
}

double SystemImpl::getValue() const{
    return value;
}