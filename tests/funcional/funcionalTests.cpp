

#include "../../src/Flow.h"
// #include "../../src/System.h"
#include "../../src/Model.h"
#include "funcionalTests.h"
#include "flows.h"
#include <cassert>
#include <cmath>

void exponentialFuncionalTest(){

    Model* m1 = Model::createModel("model",0);
    System* pop1 = m1->createSystem(100,"pop1");
    System* pop2 = m1->createSystem(0,"pop2");
    m1->createFlow<Exponential>("exponencial", pop1, pop2);

    

    m1->run(0, 100, 1);


    assert(round((pop1->getValue() - 36.6032) * 10000) == 0);
    assert(round((pop2->getValue() - 63.3968) * 10000) == 0);
    // printf("aqui\n");

    delete m1;
    
}

void logisticalFuncionalTest(){


    Model *m1 = Model::createModel("model1",0);
    System *p1 = m1->createSystem(100,"p1");
    System *p2 = m1->createSystem(10,"p2");
    m1->createFlow<Logistic>("logistic",p1,p2);

    m1->run(0,100,1);

    assert(round((p1->getValue() - 88.2167) * 10000) == 0);
    assert(round((p2->getValue() - 21.7833) * 10000) == 0);

    delete m1;
}

void complexFuncionalTest(){

    Model* m1 = Model::createModel("model1",0);

    System *Q1 = m1->createSystem(100,"Q1");
    System *Q2 = m1->createSystem(0,"Q2"); 
    System *Q3 = m1->createSystem(100,"Q3"); 
    System *Q4 = m1->createSystem(0,"Q4"); 
    System *Q5 = m1->createSystem(0,"Q5"); 

    m1->createFlow<Complex>("f",Q1,Q2);
    m1->createFlow<Complex>("g",Q1,Q3);
    m1->createFlow<Complex>("t",Q2,Q3);
    m1->createFlow<Complex>("r",Q2,Q5);
    m1->createFlow<Complex>("u",Q3,Q4);
    m1->createFlow<Complex>("v",Q4,Q1);


    
    m1->run(0, 100, 1);


    assert(round((Q1->getValue() - 31.8513) * 10000) == 0);
    assert(round((Q2->getValue() - 18.4003) * 10000) == 0);
    assert(round((Q3->getValue() - 77.1143) * 10000) == 0);
    assert(round((Q5->getValue() - 16.4612) * 10000) == 0);

    delete m1;
}

