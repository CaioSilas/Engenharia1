

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>


using namespace std;

/**
 * @brief System interface
 * 
 */

class System{
    public:

		/**
	     * @brief Destroy the System Interface object
	     * 
	     */
        virtual ~System() {}

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the System Interface
	     */
        virtual void setName(const string name) = 0;

        /**
	     * @brief Set the Name object
	     * 
	     * @param value New value for the System Interface
	     */
        virtual void setValue(const double value) = 0;

        /**
	     * @brief Get the Name object
	     * 
	     * @return double: System name
	     */
        virtual string getName() const = 0;

        /**
	     * @brief Get the Value object
	     * 
	     * @return double: System value
	     */
        virtual double getValue() const = 0;

        // /**
	    //  * @brief Construct a new System object by copying other System
	    //  * 
	    //  * @param obj System to be copied
	    //  */
        // System(const System& obj); 

        // /**
	    //  * @brief Overload the assignment operator (=)
        //  * 
        //  * @param rhs System to be copied
        //  * @return System&: return the copy
        //  */
        // System& operator=(const System& rhs); 
};



#endif /* System_H */
