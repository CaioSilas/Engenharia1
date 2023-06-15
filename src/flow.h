#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

using namespace std;

/**
 * @brief Classe responsável por representar um fluxo.
 * 
 * Um fluxo representa a transferência de algum recurso de um sistema de origem para um sistema de destino.
 * Essa classe é uma classe base abstrata, que deve ser derivada por classes filhas para implementar a funcionalidade específica do fluxo.
 * 
 * Exemplo de uso:
 * \code{.cpp}
 * class FlowExp: public Flow{
    public:
        FlowExp();
        FlowExp(std:: string name, System *source,System *target);
        virtual ~FlowExp();
        virtual float execute() override;
}; 
    
 * \endcode
 */

class Flow {
    public:
        /**
         * @brief Construtor padrão da classe Flow.
         */
        Flow();
        
        /**
         * @brief Construtor da classe Flow.
         * @param name Nome do fluxo.
         * @param source Sistema de origem do fluxo.
         * @param target Sistema de destino do fluxo.
         */
        Flow(string = "", System* = NULL, System* = NULL);
        
        /**
         * @brief Destrutor da classe Flow.
         */
        virtual ~Flow();
        
        /**
         * @brief Função puramente virtual que deve ser implementada pelas classes filhas para executar o fluxo.
         * @return Valor resultante da execução do fluxo.
         */
        virtual double execute() = 0;
        
        /**
         * @brief Obtém o sistema de destino do fluxo.
         * @param System System de origem
         * @param System System de destino
         */
        void connect(System* = NULL, System* = NULL);
        

        
        /**
         * @brief Obtém o nome do fluxo.
         * @param Name recebe uma string para fazer um set do nome do fluxo
         * 
         */
        void setName(const string);

        /**
         * @brief Define o sistema de origem do fluxo.
         * @param Value seta o valor do fluxo.
         */
        void setValue(const double);
        /**
         * @brief Define o sistema de origem do fluxo.
         * @param source O sistema de origem do fluxo.
         */
        void setSource(System*);
        /**
         * @brief Define o sistema de destino do fluxo.
         * @param System O sistema de destino do fluxo.
         */
        void setDestiny(System*);

        //gets
        
        /**
         * @brief função que pega o nome do fluxo.
         * @return retorna uma string.
         */
        string getName() const;

        /**
         * @brief função que pega o valor do fluxo.
         * @return retorna um double com o valor do fluxo
         */
        double getValue() const;
        /**
         * @brief função que pega a origem do fluxo.
         * @return retorna um System de origem
         */
        System* getSource() const;
        
        /**
         * @brief função que pega o destino do fluxo
         * @return retorna um System de destino
         */
        System* getDestiny() const;


    protected:
        string name;
        double value;
        System* source;
        System* destiny;

    private:
        /**
         * @brief Operador de atribuição sobrecarregado.
         * @param obj Objeto Flow a ser atribuído.
         * @return Referência para o objeto Flow atualizado.
         * Exemplo de uso:
        * \code{.cpp}
        * 
        *   System *p1= new System("p1", 100.0);
            System *p2= new System("p2", 10.0);
            FlowExp* f1 = new FlowExp(); // herda de @ref Flow e implementa suas funcionalidades
            f1->setTarget(p2);
            f1->setSource(p1);
            f1->setName("f1");
            FlowExp* f2 = new FlowExp(f1); 
            
        * \endcode
         */
        Flow(const Flow& obj);
        /**
         * @brief Sobrecarga do operador de atribuição.
         * 
         * Esta função atribui os valores do objeto Flow especificado ao objeto Flow atual.
         * 
         * @param rhs Objeto Flow a ser atribuído.
         * @return Referência para o objeto Flow atualizado.
         */  
        Flow& operator=(const Flow& rhs); 
};

#endif

