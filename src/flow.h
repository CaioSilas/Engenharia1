

#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

using namespace std;

/**
 * @brief Flow interface 
 * 
 */

class Flow {
    public:

		/**
         * @brief Destroy the Flow object
         * 
         */
        virtual ~Flow() {}
		
        /**
         * @brief Set the source and the destiny of the Flow object
         * 
         * @param source New source System Interface for the Flow 
         * @param destiny New destiny System Interface for the Flow
         */
        virtual void connect(System*source = NULL, System*destiny = NULL) = 0;
        
        /**
	     * @brief Execute the Flow equation
	     * 		  Abstract method to be overriden
	     * @return double: Flow value after executing
	     */
        virtual double execute() = 0;

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the Flow
	     */
        virtual void setName(const string name) = 0;

        /**
	     * @brief Set the Last Value object
	     * 
	     * @param value New value for the Flow
	     */
        virtual void setValue(const double value) = 0;

        /**
	     * @brief Set the Source object
	     * 
	     * @param source New source System Interface for the Flow
	     */
        virtual void setSource(System* source) = 0;

        /**
	     * @brief Set the Destiny object
	     * 
	     * @param destiny New destiny System Interface for the Flow
	     */
        virtual void setDestiny(System* destiny) = 0;

        /**
	     * @brief Get the Name object
	     * 
	     * @return string: Flow name
	     */
        virtual string getName() const = 0;

        /**
	     * @brief Get the Last Value object
	     * 
	     * @return double: Flow last value
	     */
        virtual double getValue() const = 0;

        /**
	     * @brief Get the Source object
	     * 
	     * @return System*: pointer to source System Interface
	     */
        virtual System* getSource() const = 0;

        /**
	     * @brief Get the Destiny object
	     * 
	     * @return System*: pointer to destiny System Interface
	     */ 
        virtual System* getDestiny() const = 0;

        // /**
	    //  * @brief Construct a new Flow object by copying other System
	    //  * 
	    //  * @param obj Flow to be copied
	    //  */
        // Flow(const Flow& obj);  

        // /**
	    //  * @brief Overload the assignment operator (=)
        //  * 
        //  * @param rhs Flow to be copied
        //  * @return Flow&: return the copy
        //  */
        // Flow& operator=(const Flow& rhs); 
};

#endif /* Flow_H */