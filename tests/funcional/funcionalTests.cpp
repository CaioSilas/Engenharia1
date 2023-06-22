

#include "funcionalTests.h"
#include "flows.h"
#include "../../src/Flow.h"
#include "../../src/FlowImpl.h"
#include "../../src/System.h"
#include "../../src/SystemImpl.h"
#include "../../src/Model.h"
#include "../../src/ModelImpl.h"
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>

void exponentialFuncionalTest(){
    System *pop1  = new SystemImpl("pop1", 100); 
    System *pop2 = new SystemImpl("pop2", 0); 
    Exponential exponential; 
    exponential.setName("exponencial"); 
    exponential.connect(pop1, pop2); 
    ModelImpl m1("Model1", 0); 
    m1.add(pop1); 
    m1.add(pop2); 
    m1.add(&exponential); 
    m1.run(0, 100, 1);

    //assert(fabs(round((exponential.getValue()*10000)) - (0.366032*10000)) < 1);
    assert(round((pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round((pop2->getValue() - 63.3968) * 10000) == 0);
    
}

void logisticalFuncionalTest(){
    System *p1 = new SystemImpl("p1", 100); 
    System *p2 = new SystemImpl("p2", 10); 
    Logistic logistic; 
    logistic.setName("logistica"); 
    logistic.connect(p1, p2); 
    ModelImpl m1("Model1", 0); 
    m1.add(p1); 
    m1.add(p2); 
    m1.add(&logistic); 
    m1.run(0, 100, 1);

    //assert(fabs(round((logistic.getValue()*10000)) - (0.150046*10000)) < 1);
    assert(round((p1->getValue() - 88.2167) * 10000) == 0);
    assert(round((p2->getValue() - 21.7833) * 10000) == 0);
}

void complexFuncionalTest(){
    System *Q1 = new SystemImpl("Q1", 100), *Q2 = new SystemImpl("Q2", 0), *Q3 = new SystemImpl("Q3", 100), *Q4 = new SystemImpl("Q4", 0), *Q5 = new SystemImpl("Q5", 0); 
    Complex f, g, t, r, u, v; 
    f.setName("f"); f.connect(Q1, Q2); 
    g.setName("g"); g.connect(Q1, Q3); 
    t.setName("t"); t.connect(Q2, Q3); 
    r.setName("r"); r.connect(Q2, Q5); 
    u.setName("u"); u.connect(Q3, Q4); 
    v.setName("v"); v.connect(Q4, Q1); 
    ModelImpl m1("Model1", 0); m1.add(Q1); 
    m1.add(Q2); m1.add(Q3); 
    m1.add(Q4); m1.add(Q5); 
    
    m1.add(&f); 
    m1.add(&g); 
    m1.add(&t); 
    m1.add(&r); 
    m1.add(&u); 
    m1.add(&v); 
    
    m1.run(0, 100, 1);


    assert(round((Q1->getValue() - 31.8513) * 10000) == 0);
    assert(round((Q2->getValue() - 18.4003) * 10000) == 0);
    assert(round((Q3->getValue() - 77.1143) * 10000) == 0);
    assert(round((Q4->getValue() - 56.1728) * 10000) == 0);
    assert(round((Q5->getValue() - 16.4612) * 10000) == 0);
}


