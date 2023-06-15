#include "System.h"
#include <string>

using namespace std;

System::System(){
    //ctor
    name = "";
    value = 0;
}

System::System(string name, double value): name(name), value(value){}

System::System(const System& obj){
    this->name = obj.name;
    this->value = obj.value;
}

System::~System(){
    //dtor
}

System& System::operator=(const System& rhs){
    if(this == &rhs)
        return *this;

    this->name = rhs.name;
    this->value = rhs.value;
    
    return *this;
}

void System::setName(const string name){
    this->name = name;
}

void System::setValue(const double value){
    this->value = value;
}

string System::getName() const{
    return name;
}

double System::getValue() const{
    return value;
}