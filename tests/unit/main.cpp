
#include "unitSystem.h"
#include "unitFlow.h"
#include "unitModel.h"
#include <iostream>

int main(){

    runUnitTestSystem();
    runUnitTestFlow();
    runUnitTestModel();

    std::cout << "-UNITARY TESTS FINISH-" << std::endl;
    
    return 0;
}