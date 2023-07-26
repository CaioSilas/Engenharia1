

#ifndef FLOWS_H
#define FLOWS_H

#include "../../src/FlowImpl.h"
#include <iostream> 
#include <string>
#include <cassert>
#include <cstdlib>



/**
 * @brief Class for Exponential representation that especifies FlowHandle
 * 
 */

class Exponential : public FlowHandle{
    public:

        /**
	     * @brief Construct a new Exponential object
	     * 
	     * @param name Exponential value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Exponential(const string name = "", System* source = NULL, System* destiny = NULL) : FlowHandle(name, source, destiny) {}

        /**
         * @brief Execute the FlowHandle equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * (pImpl_->getSource())->getValue();
        }
};

/**
 * @brief Class for Logistic representation that especifies FlowHandle
 * 
 */

class Logistic : public FlowHandle{
    public:

        /**
	     * @brief Construct a new Logistic object
	     * 
	     * @param name Logistic value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Logistic(const string name = "", System* source = NULL, System* destiny = NULL) : FlowHandle(name, source, destiny) {}

        /**
         * @brief Execute the FlowHandle equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * ((pImpl_->getDestiny())->getValue())*(1-((pImpl_->getDestiny())->getValue())/70);
        }
};

/**
 * @brief Class for Complex representation that especifies FlowHandle
 * 
 */

class Complex : public FlowHandle{
    public:

        /**
	     * @brief Construct a new Complex object
	     * 
	     * @param name Complex value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Complex(const string name = "", System* source = NULL, System* destiny = NULL) : FlowHandle(name, source, destiny) {}

        /**
         * @brief Execute the FlowHandle equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * (pImpl_->getSource())->getValue();
        }
};



#endif