

#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <string>
#include <vector>
#include <iterator>
#include "Flow.h"
#include "System.h"
#include "Model.h"

// using namespace std;

/**
 * @brief Class for ModelImpl representation
 * 
 */

class ModelImpl : public Model{
    public:

        /**
        * @brief  fabric of model
        * @param name give a nome of model
        * @param time give a time of model
        * @return Model*: The created model
        *  
        */
	    static Model* createModel(const string name = "", const double time = 0.0);


        /**
        * @brief Creates a System and add it to the model
        * @param value Initial value to the created system
        * @param name Name to the created system
        * @return System*: The system that was just created
        *  
        */
        System* createSystem(double value=0, string name="");
        /**
	     * @brief Construct a new ModelImpl object
	     * 
	     * @param name ModelImpl name
	     * @param time ModelImpl initial time
	     */
        ModelImpl(string name = "",double time = 0);


        /**
	     * @brief Destroy the ModelImpl object
	     * 
	     */
        virtual ~ModelImpl();
        
        /**
	     * @brief Add a new System to the System container
	     * 
	     * @param sys System to be added
	     */
        void add(System* System);

        /**
	     * @brief Add a new Flow to the Flow container
	     * 
	     * @param Flow Flow to be added
	     */
        void add(Flow* Flow);

        /**
	     * @brief Run the simulation
	     * 
	     * @param timeStart initial time for the simulation
	     * @param timeEnd final time for the simulation
	     * @param timeVariance time step for the simulation
	     * @return true: if it the simulation succesful
	     * @return false: if it the simulation unsuccesful
	     */
        void run(int timeStart = 0, int timeEnd = 0, int timeVariance = 1);

        /**
         * @brief typedef a container for the System pointers
         */
        typedef vector<System*>::iterator SystemIterator;
        
        /**
         * @brief typedef a container for the Flow pointers
         */
        typedef vector<Flow*>::iterator FlowIterator;

        /**
         * @brief Get the First Iterator of System the container
         *  
         * @return SystemIterator : First Iterator
         */
        SystemIterator SystemBegin(void);

        /**
         * @brief Get the Last Iterator of the System container
         * 
         * @return SystemIterator 
         */
        SystemIterator SystemEnd(void);

        /**
         * @brief Get the First Iterator of the Flow container
         * 
         * @return FlowIterator 
         */
        FlowIterator FlowBegin(void);

        /**
         * @brief Get the Last Iterator of the Flow container
         * 
         * @return FlowIterator 
         */
        FlowIterator FlowEnd(void);

        /**
	     * @brief Set the Name object
	     * 
	     * @param name New name for the ModelImpl
	     */
        void setName(const string name);

        /**
	     * @brief Set the Time object
	     * 
	     * @param time New initial time for the ModelImpl
	     */
        void setTime(const double time);

        /**
	     * @brief Get the Name object
	     * 
	     * @return string: ModelImpl name
	     */
        string getName() const;

        /**
	     * @brief Get the Time object
	     * 
	     * @return double: ModelImpl initial time
	     */
        double getTime() const;

        /**
	     * @brief Add a new Model to the Model container
	     * 
	     * @param Model Model to be added
	     */
        static void add(Model* Model);
        
    protected:
        string name; /**< ModelImpl name id */
        double time; /**< System actual time */
        vector<System*> systems; /**< ModelImpl container for Systems */
        vector<Flow*> flows; /**< ModelImpl container for Flows */
        static vector<Model*> models;

    private:
        /**
	     * @brief Construct a new ModelImpl object by copying other System
	     * 
	     * @param obj ModelImpl to be copied
	     */
        ModelImpl(const ModelImpl& obj);  

        /**
	     * @brief Overload the assignment operator (=)
         * 
         * @param rhs ModelImpl to be copied
         * @return ModelImpl&: return the copy
         */
        ModelImpl& operator=(const ModelImpl& rhs); 
};

#endif