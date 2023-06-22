

#include "../../src/SystemImpl.h"
#include "../../src/System.h"
#include "../../src/FlowImpl.h"
#include "../../src/Flow.h"
#include "../funcional/flows.h"
#include "unitFlow.h"
#include <cassert>

void runUnitTestFlow(void){

    unitFlowConstructor();
    unitFlowDestructor();

    unitFlowGetName();
    unitFlowSetName();

    unitFlowGetValue();
    unitFlowSetValue();

    unitFlowGetSource();
    unitFlowSetSource();

    unitFlowGetDestiny();
    unitFlowSetDestiny();

}

void unitFlowConstructor(void){
    Flow *flow1 = new Complex();
    assert(flow1->getName() == "");
    assert(flow1->getSource() == NULL);
    assert(flow1->getDestiny() == NULL);

    SystemImpl* sys1 = NULL, *sys2 = NULL;
    Flow *flow2 = new Complex("Flow", sys1, sys2);
    assert(flow2->getName() == "Flow");
    assert(flow2->getSource() == NULL);
    assert(flow2->getDestiny() == NULL);

    delete flow1;
    delete flow2;

}

void unitFlowDestructor(void){

}

void unitFlowGetName(void){
    Flow* flow = new Complex("Flow");
    assert(flow->getName() == "Flow");

    delete flow;
}

void unitFlowSetName(void){
    Flow* flow = new Complex("Flow");
    flow->setName("Flow2");

    assert(flow->getName() == "Flow2");

    delete flow;
}

void unitFlowGetSource(void){
    SystemImpl *sys = NULL;
    Flow *flow = new Complex("", sys);

    assert(flow->getSource() == sys);

    delete sys;
    delete flow;
}

void unitFlowSetSource(void){
    SystemImpl *sys = NULL;
    Flow *flow = new Complex("");

    flow->setSource(sys);

    assert(flow->getSource() == sys);

    delete sys;
    delete flow;
}

void unitFlowGetDestiny(void){
    SystemImpl *sys = NULL;
    Flow *flow = new Complex("", NULL, sys);

    assert(flow->getSource() == sys);

    delete sys;
    delete flow;
}

void unitFlowSetDestiny(void){
    SystemImpl *sys = NULL;
    Flow *flow = new Complex("");

    flow->setSource(sys);

    assert(flow->getSource() == sys);

    delete sys;
    delete flow;
}

void unitFlowGetValue(void){
    Flow *flow = new Complex();

    assert(flow->getValue() == 0);

    delete flow;
}

void unitFlowSetValue(void){
    Flow *flow = new Complex();
    flow->setValue(10.9);

    assert(flow->getValue() == 10.9);

    delete flow;
}

void unitFlowExecute(void){
    Flow *flow = new Complex("Flow", NULL, NULL);

    flow->setValue(flow->getValue() - flow->execute());

    assert(flow->getValue() == -1);

    delete flow;
}