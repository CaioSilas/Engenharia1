#ifndef FLOWS_H
#define FLOWS_H

#include "../../src/Flow.h"
#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>

class Exponential : public Flow{
    public:
        /**
        * @brief Construtor da classe Exponetial.
        * @param name Nome do fluxo exponencial.
        * @param source Sistema fonte do fluxo.
        * @param destiny Sistema alvo do fluxo.
        */
        Exponential(const string name = "", System* source = NULL, System* destiny = NULL) : Flow(name, source, destiny) {}
        /**
         * sobrecarga da função execute para a class Exponetial
         * @param void recebe um ponteiro void.
        */
        virtual double execute(void){
            return 0.01 * source->getValue();
        }
};

class Logistic : public Flow{
    
    public:
        /**
        * @brief Construtor da classe logistic.
        * @param name Nome do fluxo exponencial.
        * @param source Sistema fonte do fluxo.
        * @param destiny Sistema alvo do fluxo.
        */
        Logistic(const string name = "", System* source = NULL, System* destiny = NULL) : Flow(name, source, destiny) {}
        /**
         * sobrecarga da função execute para a class logistic.
         * @param void recebe um ponteiro void.
        */
        virtual double execute(void){
            return 0.01 * (destiny->getValue())*(1-(destiny->getValue())/70);
        }
};

class MyFlow : public Flow{
    public:
        /**
         * @brief Construtor da classe Myflow.
         * @param name Nome do fluxo exponencial.
         * @param source Sistema fonte do fluxo.
         * @param destiny Sistema alvo do fluxo.
         */
        MyFlow(const string name = "", System* source = NULL, System* destiny = NULL) : Flow(name, source, destiny) {}
        /**
         * sobrecarga da função execute para a class Myflow
         * @param void recebe um ponteiro void.
        */
        virtual double execute(void){
            return 0.01 * source->getValue();
        }
};



#endif