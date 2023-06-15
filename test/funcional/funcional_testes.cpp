#include "funcional_testes.h"
#include "flows.h"
#include "../../src/Flow.h"
#include "../../src/System.h"
#include "../../src/Model.h"
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iomanip>

void exponentialFuncionalTest(){
    System pop1("pop1", 100); 
    System pop2("pop2", 0); 
    Exponential exponential; 
    exponential.setName("exponencial"); 
    exponential.connect(&pop1, &pop2); 
    Model m1("Model1", 0); 
    m1.add(&pop1); 
    m1.add(&pop2); 
    m1.add(&exponential); 
    m1.run(0, 100, 1);

    assert(fabs(pop1.getValue()-36.6032) < 0.0001);
    assert(fabs(pop2.getValue()-63.3968) < 0.0001);
    
}

void logisticalFuncionalTest(){
    System p1("p1", 100); 
    System p2("p2", 10); 
    Logistic logistic; 
    logistic.setName("logistica"); 
    logistic.connect(&p1, &p2); 
    Model m1("Model1", 0); 
    m1.add(&p1); 
    m1.add(&p2); 
    m1.add(&logistic); 
    m1.run(0, 100, 1);


    assert(fabs(p1.getValue()-88.2167) < 0.0001);
    assert(fabs(p2.getValue()-21.7833) < 0.0001);
}

void complexFuncionalTest(){
    System Q1("Q1", 100), Q2("Q2", 0), Q3("Q3", 100), Q4("Q4", 0), Q5("Q5", 0); 
    MyFlow f, g, t, r, u, v; 
    f.setName("f"); f.connect(&Q1, &Q2); 
    g.setName("g"); g.connect(&Q1, &Q3); 
    t.setName("t"); t.connect(&Q2, &Q3); 
    r.setName("r"); r.connect(&Q2, &Q5); 
    u.setName("u"); u.connect(&Q3, &Q4); 
    v.setName("v"); v.connect(&Q4, &Q1); 
    Model m1("Model1", 0); m1.add(&Q1); 
    m1.add(&Q2); m1.add(&Q3); 
    m1.add(&Q4); m1.add(&Q5); 
    
    m1.add(&f); 
    m1.add(&g); 
    m1.add(&t); 
    m1.add(&r); 
    m1.add(&u); 
    m1.add(&v); 
    
    m1.run(0, 100, 1);


    assert(abs(Q1.getValue()-31.8513) < 0.0001);
    assert(abs(Q2.getValue()-18.4004) < 0.0001);
    assert(abs(Q3.getValue()-77.1143) < 0.0001);
    assert(abs(Q4.getValue()-56.1728) < 0.0001);
    assert(abs(Q5.getValue()-16.4612) < 0.0001);


}


