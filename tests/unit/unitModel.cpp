

#include "../../src/FlowImpl.h"
#include "../../src/ModelImpl.h"
#include "unitModel.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>

class TestFlow : public FlowImpl {
public:
    TestFlow(string nome,System* source, System* destiny) : FlowImpl(nome,source, destiny) {}
    
    virtual double execute(void) {
        return 0.01 * source->getValue();
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
    Model* m = Model::createModel();

    System* s = m->createSystem(10);
    System* d = m->createSystem(10);
    Flow* f = m->createFlow<TestFlow>("f",s, d);
    Flow* g = m->createFlow<TestFlow>("g",nullptr, nullptr);

    Model::systemIterator sIt = m->SystemBegin();
    assert((*sIt) == s);
    sIt++;
    assert((*sIt) == d);

    Model::flowIterator fIt = m->FlowBegin();
    assert((*fIt) == f);
    fIt++;
    assert((*fIt) == g);

    delete m;

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