
#ifndef Model_H
#define Model_H

#include <string>
#include <vector>
#include <iterator>
#include "System.h"
#include "Flow.h"

using std::vector;

/**
 * @brief Class for Model Interface representation
 * 
 */

class Model {
    public:

        /**
        * @brief Instantiates a model
        * @param name give a name of model
        * @param time give a time od model
        * @return Model*: The created model
        *  
        */
	    static Model* createModel(const string name = "", const double time = 0.0);


        /**
        * @brief Creates a Flow and add it to the model
        * @param name A name to flow
        * @param source A pointer to the source system
        * @param destiny A pointer to the destiny system
        * @return Flow*: Returns a pointer to the created Flow
        *  
        */
        template <typename T_FLOW>
        Flow* createFlow(string name,System* source=NULL, System* destiny=NULL) {
            Flow* f = new T_FLOW(name,source, destiny);
            add(f);
            return f;
        }

        /**
        * @brief Creates a System and add it to the model
        * @param value Initial value to the created system
        * @param name Name to the created system
        * @return System*: The system that was just created
        *  
        */
        virtual System* createSystem(double value=0, string name="")=0;
        
        /**
	     * @brief Destroy the Model Interface object
	     * 
	     */
        virtual ~Model() {}

        /**
	     * @brief Add a new System Interface to the System Interface container
	     * 
	     * @param sys System Interface to be added
	     */
        virtual void add(System* System) = 0;

        /**
	     * @brief Add a new Flow to the Flow container
	     * 
	     * @param Flow Flow to be added
	     */
        virtual void add(Flow* Flow) = 0;

        /**
	     * @brief Run the simulation
	     * 
	     * @param timeStart initial time for the simulation
	     * @param timeEnd final time for the simulation
	     * @param timeVariance time step for the simulation
	     * @return true: if it the simulation succesful
	     * @return false: if it the simulation unsuccesful
	     */
        virtual void run(int timeStart = 0, int timeEnd = 0, int timeVariance = 1) = 0;

        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;
        
        /**
         * @brief Get the First Iterator of System Interface the container
         *  
         * @return vector<System*>::iterator : First Iterator
         */
        virtual vector<System*>::iterator SystemBegin(void) = 0;

        /**
         * @brief Get the Last Iterator of the System Interface container
         * 
         * @return vector<System*>::iterator 
         */
        virtual vector<System*>::iterator SystemEnd(void) = 0;

        /**
         * @brief Get the First Iterator of the Flow container
         * 
         * @return vector<Flow*>::iterator 
         */
        virtual vector<Flow*>::iterator FlowBegin(void) = 0;

        /**
         * @brief Get the Last Iterator of the Flow container
         * 
         * @return vector<Flow*>::iterator 
         */
        virtual vector<Flow*>::iterator FlowEnd(void) = 0;

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the Model Interface
	     */
        virtual void setName(const string name) = 0;

        /**
	     * @brief Set the Time object
	     * 
	     * @param time New initial time for the Model Interface
	     */
        virtual void setTime(const double time) = 0;

        /**
	     * @brief Get the Name object
	     * 
	     * @return string: Model name
	     */
        virtual string getName() const = 0;

        /**
	     * @brief Get the Time object
	     * 
	     * @return double: Model initial time
	     */
        virtual double getTime() const = 0;
    
        // /**
	    //  * @brief Construct a new Model object by copying other System
	    //  * 
	    //  * @param obj Model to be copied
	    //  */
        // Model(const Model& obj);  

        // /**
	    //  * @brief Overload the assignment operator (=)
        //  * 
        //  * @param rhs Model to be copied
        //  * @return Model&: return the copy
        //  */
        // Model& operator=(const Model& rhs); 
};

#endif /* Model_H */