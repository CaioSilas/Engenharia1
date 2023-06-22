

#ifndef FLOWS_H
#define FLOWS_H

#include "../../src/FlowImpl.h"
#include <iostream> 
#include <string>
#include <cassert>
#include <cstdlib>

/**
 * @brief Class for Exponential representation that especifies FlowImpl
 * 
 */

class Exponential : public FlowImpl{
    public:

        /**
	     * @brief Construct a new Exponential object
	     * 
	     * @param name Exponential value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Exponential(const string name = "", System* source = NULL, System* destiny = NULL) : FlowImpl(name, source, destiny) {}

        /**
         * @brief Execute the FlowImpl equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * source->getValue();
        }
};

/**
 * @brief Class for Logistic representation that especifies FlowImpl
 * 
 */

class Logistic : public FlowImpl{
    public:

        /**
	     * @brief Construct a new Logistic object
	     * 
	     * @param name Logistic value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Logistic(const string name = "", System* source = NULL, System* destiny = NULL) : FlowImpl(name, source, destiny) {}

        /**
         * @brief Execute the FlowImpl equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * (destiny->getValue())*(1-(destiny->getValue())/70);
        }
};

/**
 * @brief Class for Complex representation that especifies FlowImpl
 * 
 */

class Complex : public FlowImpl{
    public:

        /**
	     * @brief Construct a new Complex object
	     * 
	     * @param name Complex value
	     * @param source Pointer to source System
         * @param destiny Pointer to destiny System
	     */
        Complex(const string name = "", System* source = NULL, System* destiny = NULL) : FlowImpl(name, source, destiny) {}

        /**
         * @brief Execute the FlowImpl equation
         * 
         * @return double: result of equation 
         */
        virtual double execute(void){
            return 0.01 * source->getValue();
        }
};



#endif