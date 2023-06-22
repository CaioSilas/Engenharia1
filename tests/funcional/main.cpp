

#include "funcionalTests.h"
#include "../../src/Model.h"
#include "../../src/System.h"
#include "../../src/Flow.h"
#include <iostream>

int main(){

    exponentialFuncionalTest();

    logisticalFuncionalTest();

    complexFuncionalTest();

    std::cout << "-FUNCTIONAL TESTS FINISH-" << std::endl;

    return 0;
}
