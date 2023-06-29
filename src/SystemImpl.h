

#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>
#include "System.h"

using namespace std;

/**
 * @brief Class for SystemImpl representation
 * 
 */

class SystemImpl : public System{
    public:

		/**
		* @brief Creates empty system
		*  
		*/
		SystemImpl();
	
        /**
	     * @brief Construct a new SystemImpl object
	     * 
	     * @param name SystemImpl name
	     * @param value SystemImpl value id
	     */
        SystemImpl(string name = "", double value = 0);

        /**
	     * @brief Destroy the SystemImpl object
	     * 
	     */
        virtual ~SystemImpl();

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the SystemImpl
	     */
        void setName(const string name);

        /**
	     * @brief Set the Name object
	     * 
	     * @param value New value for the SystemImpl
	     */
        void setValue(const double value);

        /**
	     * @brief Get the Name object
	     * 
	     * @return double: SystemImpl name
	     */
        string getName() const;

        /**
	     * @brief Get the Value object
	     * 
	     * @return double: SystemImpl value
	     */
        double getValue() const;

    protected:

		string name; /**< SystemImpl name id */
        double value; /**< SystemImpl value */

    private:
        
        /**
	     * @brief Construct a new SystemImpl object by copying other SystemImpl
	     * 
	     * @param obj SystemImpl to be copied
	     */
        SystemImpl(const SystemImpl& obj); 

        /**
	     * @brief Overload the assignment operator (=)
         * 
         * @param rhs SystemImpl to be copied
         * @return SystemImpl&: return the copy
         */
        SystemImpl& operator=(const SystemImpl& rhs); 
};

#endif /* SystemImpl_H */