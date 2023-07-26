

#include "../../src/FlowImpl.h"
#include "../../src/ModelImpl.h"
#include "unitModel.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>

class TestFlow : public FlowHandle {
public:
    TestFlow(string nome,System* source, System* destiny) : FlowHandle(nome,source, destiny) {}
    
    virtual double execute(void) {
        return 0.01 * (pImpl_->getSource())->getValue();
    }
};



void runUnitTestModel(void){

    unitModelConstructor();
    unitModelDestructor();

    unitModelSetName();

    unitModelGetTime();
    unitModelSetTime();

    unitModelAdd();

    unitModelRun();
    
}

void unitModelConstructor(void){
    Model *mod1 = Model::createModel();
    assert(mod1->getName() == "");
    assert(mod1->getTime() == 0);

    Model *mod2 = Model::createModel("Model", 10);
    assert(mod2->getName() == "Model");
    assert(mod2->getTime() == 10);

    delete mod1;
    delete mod2;

}

void unitModelDestructor(void){

}


void unitModelSetName(void){
    Model *mod = Model::createModel("model1");

    mod->setName("Model2");

    assert(mod->getName() == "Model2");

    delete mod;

}

void unitModelGetTime(void){
    Model *mod = Model::createModel("",10);
    

    assert(mod->getTime() == 10);

    delete mod;

}

void unitModelSetTime(void){
    Model *mod = Model::createModel("",10);

    mod->setTime(15.3);

    assert(mod->getTime() == 15.3);

    delete mod;

}

void unitModelAdd(void){
    System *sys;
    Flow *flow;
    Model *mod = Model::createModel("Model", 0);

    sys = mod->createSystem();
    flow = mod->createFlow<TestFlow>();
    
    assert(find(mod->SystemBegin(), mod->SystemEnd(), sys) != mod->SystemEnd());
    assert(find(mod->FlowBegin(), mod->FlowEnd(), flow) != mod->FlowEnd());

    delete mod;

}

void unitModelRun(void){
    Model *mod = Model::createModel();
    mod->setName("model");
    mod->setTime(0);

    mod->run(0, 0, 1);
    assert(fabs(round(mod->getTime()*10000) - 0) < 1);

    mod->run(100, 0, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    mod->run(0, 100, 1);
    assert(fabs(round(mod->getTime()*10000) - 1000000) < 1);

    delete mod;
    
}