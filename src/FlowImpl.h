

#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include <string>
#include "System.h"
#include "Flow.h"

using namespace std;

/**
 * @brief Class for FlowImpl representation
 * 
 */

class FlowImpl : public Flow{
    public:

        /**
	     * @brief Construct a new FlowImpl object
	     * 
	     * @param name FlowImpl value
	     * @param source Pointer to source System Interface
         * @param destiny Pointer to destiny System Interface
	     */
        FlowImpl( string nome = "" ,System* source = NULL, System* destiny = NULL);
        
        /**
         * @brief Destroy the FlowImpl object
         * 
         */
        virtual ~FlowImpl();

        /**
         * @brief Set the source and the destiny of the FlowImpl object
         * 
         * @param source New source System Interface for the FlowImpl 
         * @param destiny New destiny System Interface for the FlowImpl
         */
        void connect(System*source = NULL, System*destiny = NULL);
        
        /**
	     * @brief Execute the FlowImpl equation
	     * 		  Abstract method to be overriden
	     * @return double: FlowImpl value after executing
	     */
        virtual double execute() = 0;

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the FlowImpl
	     */
        void setName(const string name);

        /**
	     * @brief Set the Last Value object
	     * 
	     * @param value New value for the FlowImpl
	     */
        void setValue(const double value);

        /**
	     * @brief Set the Source object
	     * 
	     * @param source New source System Interface for the FlowImpl
	     */
        void setSource(System* source);

        /**
	     * @brief Set the Destiny object
	     * 
	     * @param destiny New destiny System Interface for the FlowImpl
	     */
        void setDestiny(System* destiny);

        /**
	     * @brief Get the Name object
	     * 
	     * @return string: FlowImpl name
	     */
        string getName() const;

        /**
	     * @brief Get the Last Value object
	     * 
	     * @return double: FlowImpl last value
	     */
        double getValue() const;

        /**
	     * @brief Get the Source object
	     * 
	     * @return System*: pointer to source System Interface
	     */
        System* getSource() const;

        /**
	     * @brief Get the Destiny object
	     * 
	     * @return System*: pointer to destiny System Interface
	     */ 
        System* getDestiny() const;


    protected:

        string name; /**< FlowImpl name id */
        double value; /**< FlowImpl value */
        System* source; /**< Pointer for source System Interface*/
        System* destiny; /**< Pointer for destiny System Interface*/

    private:

        /**
	     * @brief Construct a new FlowImpl object by copying other FlowImpl object
	     * 
	     * @param obj FlowImpl to be copied
	     */
        FlowImpl(const FlowImpl& obj);  

        /**
	     * @brief Overload the assignment operator (=)
         * 
         * @param rhs FlowImpl to be copied
         * @return FlowImpl&: return the copy
         */
        FlowImpl& operator=(const FlowImpl& rhs); 
};

#endif /* FlowImpl_H */
