#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;
/**
 * @brief Classe responsável por representar um sistema.
 * 
 * Um sistema é uma entidade que possui um nome e um valor associado.
 * 
 * Exemplo de uso:
 * * \code{.cpp}
 *  System *p1= new System("p1", 100.0);
    System *p2= new System("p2", 10.0);
    
    cout << p1->getValue() << endl;
    p1->setValue(200);
    cout << p1 == p2 << endl;
    delete(p1);
    delete(p2);
    
    
 * \endcode

 */

class System {
    public:
        /**
         * @brief Construtor padrão da classe System.
         */
        System();
        /**
         * @brief Construtor da classe System.
         * @param name Nome do sistema.
         * @param value valor da capacidade do System.
         */
        System(string = "", double = 0);
         /**
         * @brief Destrutor da classe System.
         */
        virtual ~System();

        //sets
        /**
         * @brief Define o nome do sistema.
         * @param name O novo nome do sistema.
         */
        void setName(const string);
        /**
         * @brief Define o valor do sistema.
         * @param value O novo valor do sistema.
         */
        void setValue(const double);

        //gets
        /**
         * @brief Obtém o nome do sistema.
         * @return O nome do sistema.
         */
        string getName() const;
        /**
         * @brief Obtém o valor do sistema.
         * @return O valor do sistema.
         */
        double getValue() const;

    protected:
        string name;
        double value;
    private:
         
        /**
         * @brief Construtor de cópia da classe System.
         * @param obj Objeto System a ser copiado.
        */
        System(const System& obj); 
        /**
         * @brief Operador de atribuição sobrecarregado.
         * @param other Objeto System a ser atribuído.
         * @return Referência para o objeto System atualizado.
         */
        System& operator=(const System& rhs); 
};

#endif