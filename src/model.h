#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <iterator>
#include "flow.h"
#include "system.h"

using namespace std;


/**
 * @brief Classe responsável por representar um modelo.
 * 
 * Um modelo contém sistemas e fluxos que são usados para simular um sistema real ou teórico.
 * Exemplo de uso:
 * \code{.cpp}
 *  System *p1= new System("p1", 100.0);
    System *p2= new System("p2", 10.0);
    FlowLogistico* logFlow = new FlowLogistico("logFlow", p1,p2);
    Model *logModel= new Model("logModel",0,100,1);

    logModel->add(p1);
    logModel->add(p2);
    logModel->add(logFlow);

    logModel->execute();

    delete(logModel);
    delete(p1);
    delete(p2);
    delete(logFlow);

 * \endcode
 * 
 */
class Model {
    public:
        /**
         * @brief Construtor padrão da classe Model.
         */
        Model();

        /**
         * @brief Construtor da classe Model.
         * @param name Nome do modelo.
         * @param Time Tempo inicial da simulação.
         */
        Model(string = "", double = 0);
         /**
         * @brief Destrutor da classe Model.
         */
        virtual ~Model();
        
        void teste();
        /**
        * @brief Adiciona um sistema ao modelo.
        * @param system Ponteiro para o sistema a ser adicionado.
        */
        void add(System*);
        /**
        * @brief Adiciona um fluxo ao modelo.
        * @param flow Ponteiro para o fluxo a ser adicionado.
        */
        void add(Flow*);
        /**
        * @brief Roda um modelo.
        * @param timeInitial tempo de inicio.
        * @param timeEnd tempo final.
        * @param timeVariance variancia do for.
        * 
        */
        void run(int = 0, int = 0, int = 1);

        typedef vector<System*>::iterator systemIterator;
        typedef vector<Flow*>::iterator flowIterator;

        /**
         *  Função que sera usada para auxiliar percorrer um interator de system
         *
         *
         * @param  void um poteiro do void.
         * 
         * @return returna um ponteiro para inicio do intereitor.
         */
        systemIterator systemBegin(void);
        /**
         *  Função que sera usada para auxiliar percorrer um interator de system
         *
         *
         * @param  void um poteiro do void.
         * 
         * @return returna um ponteiro para o final do intereitor.
         */
        systemIterator systemEnd(void);
        /**
         *  Função que sera usada para auxiliar percorrer um interator de flow
         *
         *
         * @param  void um poteiro do void.
         * 
         * @return returna um ponteiro para o inicio do intereitor.
         */
        flowIterator flowBegin(void);
        /**
         *  Função que sera usada para auxiliar percorrer um interator de flow
         *
         *
         * @param  void um poteiro do void.
         * 
         * @return returna um ponteiro para o final do intereitor.
         */
        flowIterator flowEnd(void);

        //sets
        /**
         * @brief Define o nome do modelo.
         * @param name O nome do modelo.
         */
        void setName(const string);
          /**
         * @brief Define o intervalo de tempo da simulação.
         * @param initialTime O tempo inicial da simulação.
         * @param finalTime O tempo final da simulação.
         */
        void setTime(const double);

        //gets
         /**
         * @brief Obtém o nome do modelo.
         * @return O nome do modelo.
         */
        string getName() const;
        /**
         * @brief Obtém o tempo inicial da simulação.
         * @return O tempo inicial da simulação.
         */
        double getTime() const;

    protected:
        string name;
        double time;
        vector<System*> systems;
        vector<Flow*> flows;

    private:
        /**
         * @brief Operador de atribuição sobrecarregado.
         * @param obj Objeto Model a ser atribuído.
         * @return Referência para o objeto Model atualizado.
        */
        Model(const Model& obj);
         /**
         * @brief Operador de igualdade sobrecarregado.
         * @param other Objeto Model a ser comparado.
         * @return true se os objetos são iguais, false caso contrário.
        */  
        Model& operator=(const Model&); 
};

#endif