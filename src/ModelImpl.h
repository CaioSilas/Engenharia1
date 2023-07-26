
#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <string>
#include <vector>
#include <iterator>
#include "Flow.h"
#include "System.h"
#include "Model.h"
#include "handleBodySemDebug.h"

using namespace std;

/**
 * @brief Class for ModelImpl representation
 * 
 */

class ModelImpl : public Body{
    public:

        System* createSystem(const string name = "", const double value = 0);

        //Flow* createFlow(const string name = "", System *source = NULL, System *destiny = NULL);
        
        static Model* createModel(const string name = "", const double time = 0);

        /**
         * @brief Delete and remove a System from the Model
         * 
         * @param system Pointer to System to be deleted
         */
        void deleteSystem(System* const system);

        /**
         * @brief Delete and remove a Flow from the Model
         * 
         * @param Flow Pointer to Flow to be deleted
         */
        void deleteFlow(Flow* const Flow);

        /**
         * @brief Delete and remove a Model from the Model
         * 
         * @param Model Pointer to Model to be deleted
         */
        static void deleteModel(Model* const Model);

        /**
	     * @brief Construct a new ModelImpl object
	     * 
	     * @param name ModelImpl name
	     * @param time ModelImpl initial time
	     */
        ModelImpl(string name = "", double time = 0);

        /**
	     * @brief Destroy the ModelImpl object
	     * 
	     */
        virtual ~ModelImpl();
        
        /**
	     * @brief Add a new Flow to the Flow container
	     * 
	     * @param Flow Flow to be added
	     */
        void add(Flow* const Flow);

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
         * @brief typedef a container for the Model pointers
         */
        typedef vector<Model*>::iterator ModelIterator;

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
         * @brief Get the First Iterator of the Model container
         * 
         * @return ModelIterator 
         */
        ModelIterator ModelBegin(void);

        /**
         * @brief Get the Last Iterator of the Model container
         * 
         * @return ModelIterator 
         */
        ModelIterator ModelEnd(void);

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

    protected:
        /**
	     * @brief Add a new System to the System container
	     * 
	     * @param sys System to be added
	     */
        void add(System* const System);

        /**
	     * @brief Add a new Model to the Model container
	     * 
	     * @param Model Model to be added
	     */
        static void add(Model* Model);

    private:
        string name; /**< ModelImpl name id */
        double time; /**< System actual time */
        vector<System*> systems; /**< ModelImpl container for Systems */
        vector<Flow*> flows; /**< ModelImpl container for Flows */
        static vector<Model*> models; /**< ModelImpl container for Models */
        
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

class ModelHandle : public Model, public Handle<ModelImpl> {
    public:
        ModelHandle(string name = "", double time = 0){
            pImpl_->setName(name);
			pImpl_->setTime(time);
        }

        virtual ~ModelHandle() {}     

        void add(Flow* const Flow){
            return pImpl_->add(Flow);
        }

        void run(int timeStart = 0, int timeEnd = 0, int timeVariance = 1){
            return pImpl_->run(timeStart, timeEnd, timeVariance);
        }

        System* createSystem(const string name = "", const double value = 0){
            return pImpl_->createSystem(name, value);
        }

        void deleteSystem(System* const system){
            return pImpl_->deleteSystem(system);
        }

        void deleteFlow(Flow* const Flow){
            return pImpl_->deleteFlow(Flow);
        }

        ModelImpl::SystemIterator SystemBegin(void){
            return pImpl_->SystemBegin();
        }

        ModelImpl::SystemIterator SystemEnd(void){
            return pImpl_->SystemEnd();
        }

        ModelImpl::FlowIterator FlowBegin(void){
            return pImpl_->FlowBegin();
        }

        ModelImpl::FlowIterator FlowEnd(void){
            return pImpl_->FlowEnd();
        }

        ModelImpl::ModelIterator ModelBegin(void){
            return pImpl_->ModelBegin();
        }

        ModelImpl::ModelIterator ModelEnd(void){
            return pImpl_->ModelEnd();
        }

        void setName(const string name){
            return pImpl_->setName(name);
        }

        void setTime(const double time){
            return pImpl_->setTime(time);
        }

        string getName() const{
            return pImpl_->getName();
        }

        double getTime() const{
            return pImpl_->getTime();
        }
};

#endif