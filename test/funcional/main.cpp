#include "funcional_testes.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include <iostream>

int main(){

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();
    
    std::cout << "-FIM DOS TESTES-" << std::endl;

    return 0;
}
