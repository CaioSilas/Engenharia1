

#include "../../src/SystemImpl.h"
#include "../../src/System.h"
#include "unitSystem.h"
#include <cassert>

void runUnitTestSystem(void){

    unitSystemConstructor();
    unitSystemDestructor();

    unitSystemGetName();
    unitSystemSetName();

    unitSystemGetValue();
    unitSystemSetValue();

}

void unitSystemConstructor(void){
    System *sys1 = new SystemImpl();
    assert(sys1->getName() == "");
    assert(sys1->getValue() == 0);

    System *sys2 = new SystemImpl("System 1", 10.5);
    assert(sys2->getName() == "System 1");
    assert(sys2->getValue() == 10.5);

    delete sys1;
    delete sys2;
}

void unitSystemDestructor(void){

}

void unitSystemGetName(void){
    System *sys = new SystemImpl("System 1");
    assert(sys->getName() == "System 1");

    delete sys;
}

void unitSystemSetName(void){
    System *sys = new SystemImpl("System 1");
    sys->setName("System 2");

    assert(sys->getName() == "System 2");

    delete sys;
}

void unitSystemGetValue(void){
    System *sys = new SystemImpl("", 10.5);
    assert(sys->getValue() == 10.5);

    delete sys;
}

void unitSystemSetValue(void){
    System *sys = new SystemImpl("", 10.5);
    sys->setValue(50.1);

    assert(sys->getValue() == 50.1);

    delete sys;
}