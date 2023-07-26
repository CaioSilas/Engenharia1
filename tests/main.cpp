#include <cstdlib>
#include <iostream>

#include "../src/ModelImpl.h"
#include "../src/FlowImpl.h"
#include "../src/SystemImpl.h"

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
	int numHandleDeleted = 0;
	int numBodyCreated = 0;
	int numBodyDeleted = 0;
#endif

using namespace std;

class FluxoLog:public FlowHandle{
   public:
    FluxoLog(string name = "", System* source = NULL, System* destiny = NULL):FlowHandle(name, source, destiny){};
    //FluxoLog(System* ori,System* des):FlowImpl(ori,des){};
    double execute(){
          double q = (pImpl_->getDestiny())->getValue();
          return q*(0.3*(1-(q/70)));;
    }    
};

class FluxoExp:public FlowHandle{
  public:
   FluxoExp(string name = "", System* source = NULL, System* destiny = NULL):FlowHandle(name, source, destiny){};
   //FluxoExp(System *ori,System *des):FlowImpl(ori,des){};
   double execute(){
         return (pImpl_->getDestiny())->getValue()*0.3;
   }      
};

int main(int argc, char *argv[])
{
    // Apenas a implementacao da classe "Flux" precisa ser conhecida na
    // fase de "cria��o de objetos", pois o usu�rio precisa implementar 
    // v�rios tipos de fluxo. Ent�o, o m�dulo de cria��o de objetos precisa
    // conhecer os fluxos implementados pelo usu�rio.No entanto, nenhuma outra 
    // implementa��o precisa ser conhecida por qq outro m�dulo.
    
    // Cria modelo
    Model* m = Model::createModel("Modelo de Pop.");      
    Flow* f1 = m->createFlow<FluxoLog>("nascimento");    

    // USANDO REFERENCIAS PARA INTERFACE (CLASSE ABSTRATA)
    //System& s1 = m.createSystem("populacao",10.0);
    //System& s2 = m.createSystem("Teste", 7.90)   ;
    //cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;
    //s1 = s2;  // nao funciona pq s1 � uma referencia, portanto nao pode ser redefinida
    //cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;    

    // USANDO PONTEIROS PARA INTERFACE (CLASSE ABSTRATA)
    System* s1 = m->createSystem("populacao",10.0);
    System* s2 = m->createSystem("Teste", 7.90)   ;
    cout << "s1: " << s1->getName() << ", s2: " <<  s2->getName() << endl;
    //s1 = s2;
    *s1 = *s2;
    cout << "s1: " << s1->getName() << ", s2: " <<  s2->getName() << endl;    
    cout << "s1: " << s1 << ", s2: " <<  s2 << endl;    
 
    
    // Fa�a o teste COM e SEM as chaves abaixo
{
    // USANDO OBJETOS HANDLES (DELEGA��O)
    SystemHandle s3("tiago", 7), s4("antonio", 8);
    cout << "s3: " << s3.getName() << ", s4: " <<  s4.getName() << endl;
    s3 = s4;  // comente esta linha e veja que o resultado muda
    cout << "s3: " << s3.getName() << ", s4: " <<  s4.getName() << endl;        
	s3 = s3;
	cout << "s3: " << s3.getName() << ", s4: " <<  s4.getName() << endl;        
}   
    // Monta Modelo
    //m.setTarget(f1, s1);
    f1->setDestiny(s1);
    
    // executa o modelo
    m->run(0,30,1);

    
    // imprime relatorio
    //cout << s1.getValue() << endl;
    cout << s1->getValue() << endl;
    cout << "Created handles: "  << numHandleCreated << endl;
    cout << "Deleted handles: "  << numHandleDeleted << endl;    
    cout << "Created bodies: "  << numBodyCreated << endl;
    cout << "Deleted bodies: "  << numBodyDeleted << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}