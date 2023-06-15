#include "flow.h"
#include <string>

using namespace std;

Flow::Flow(){
    //ctor
    name = "";
    source = NULL;
    destiny = NULL;
}

Flow::Flow(string name, System* source, System* destiny): name(name) , source(source) , destiny(destiny){}

Flow::Flow(const Flow& obj){
    this->name = obj.name;
    this->value = obj.value;
    this->source = obj.source;
    this->destiny = obj.destiny;
}

Flow::~Flow(){
    //dtor
}

void Flow::connect(System* source, System* destiny){
    this->source = source;
    this->destiny = destiny;
}   

Flow& Flow::operator=(const Flow& rhs){
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

void Flow::setName(const string name){
    this->name = name;
}

void Flow::setValue(const double value){
    this->value = value;
}

void Flow::setSource(System* source){
    this->source = source;
}

void Flow::setDestiny(System* destiny){
    this->destiny = destiny;
}

string Flow::getName() const{
    return name;
}

double Flow::getValue() const{
    return value;
}

System* Flow::getSource() const{
    return source;
}

System* Flow::getDestiny() const{
    return destiny;
}

