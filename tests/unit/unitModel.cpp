

#include "../../src/FlowImpl.h"
#include "../../src/Flow.h"
#include "../../src/ModelImpl.h"
#include "../../src/Model.h"
#include "../funcional/flows.h"
#include "unitModel.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>

void runUnitTestModel(void){

    unitModelConstructor();
    unitModelDestructor();

    unitModelGetName();
    unitModelSetName();

    unitModelGetTime();
    unitModelSetTime();

    unitModelAdd();

    unitModelRun();
    
}

void unitModelConstructor(void){
    Model *mod1 = new ModelImpl();
    assert(mod1->getName() == "");
    assert(mod1->getTime() == 0);

    Model *mod2 = new ModelImpl("Model", 10);
    assert(mod2->getName() == "Model");
    assert(mod2->getTime() == 10);

    delete mod1;
    delete mod2;

}

void unitModelDestructor(void){

}

void unitModelGetName(void){
    Model *mod = new ModelImpl("Model");

    assert(mod->getName() == "Model");

    delete mod;

}

void unitModelSetName(void){
    Model *mod = new ModelImpl("Model");

    mod->setName("Model2");

    assert(mod->getName() == "Model2");

    delete mod;

}

void unitModelGetTime(void){
    Model *mod = new ModelImpl("", 10);

    assert(mod->getTime() == 10);

    delete mod;

}

void unitModelSetTime(void){
    Model *mod = new ModelImpl("", 10);

    mod->setTime(15.3);

    assert(mod->getTime() == 15.3);

    delete mod;

}

void unitModelAdd(void){
    System *sys = NULL;
    Flow *flow = NULL;
    Model *mod = new ModelImpl("Model", 0);

    mod->add(sys);
    mod->add(flow);
    
    assert(find(mod->SystemBegin(), mod->SystemEnd(), sys) != mod->SystemEnd());
    assert(find(mod->FlowBegin(), mod->FlowEnd(), flow) != mod->FlowEnd());

    delete sys;
    delete flow;
    delete mod;

}

void unitModelRun(void){
    Model *mod = new ModelImpl("Model", 0);

    mod->run(0, 0, 1);
    assert(fabs(round(mod->getTime()*10000) - 0) < 1);

    mod->run(100, 0, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    mod->run(0, 100, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    delete mod;
    
}