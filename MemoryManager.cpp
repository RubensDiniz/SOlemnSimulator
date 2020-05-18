#define FIRST_FIT 0
#define BEST_FIT 1
#define QUICK_FIT 2

#include "MemoryBlock.cpp"
#include <list>
#include <queue>

class MemoryManager {
protected:
	//lista de MemoryBlock chamada memory
    MemoryBlock* free_blocks_list;
    int allocation_algorithm;
    int total_memory;
    int memory_overhead;

public:

    MemoryManager(){
        
    }
    
    MemoryBlock* malloc(int requested_memory){
        return nullptr;
    }

    MemoryBlock* free(MemoryBlock* block){
        //void ou n�o? por mim tanto faz, imaginei como um list.pop();
    }    

    void set_allocation_algorithm(int algorithm){
        allocation_algorithm = algorithm;
    }

    int get_total_memory() {
	    
    }
	
	int get_memory_overhead() {
	    
    }

    int get_available_memory() {
        return get_total_memory() - (get_memory_overhead() + get_occupied_memory());
    }

	int get_occupied_memory() {
	    
    }

}

/*
-----memory_manager: classe que implementa o gerenciador de mem�ria, suas estruturas
de dados e algoritmos:

memory: estrutura de dados usada para representar a mem�ria RAM instalada
no sistema, � composta por memory_blocks.

free_blocks_list: ponteiro para o primeiro bloco de mem�ria livre, o qual deve
fazer parte da lista de blocos livres.

malloc: m�todo que simula uma chamada de sistema por mem�ria, tem como
par�metro um inteiro que representa a quantidade de mem�ria solicitada em
bytes. Tem como retorno o endere�o do bloco de mem�ria que foi usado para
satisfazer a chamada. Chama um algoritmo de aloca��o de mem�ria para
efetuar a aloca��o de um bloco.

free: simula uma chamada de sistema solicitando a desaloca��o de um dado
endere�o de mem�ria (par�metro). O bloco � marcado como livre por meio da
sua inser��o na lista de blocos livres.

set_allocation_algorithm: m�todo que seleciona o algoritmo de aloca��o de
mem�ria a ser usado.

total_memory: quantidade de mem�ria RAM instalada no sistema em bytes.

memory_overhead: quantidade de mem�ria utilizada pelo pr�prio
memory_manager.

available_memory: quantidade de mem�ria livre dispon�vel para os processos
num dado instante de tempo. available = total - (occupied + overhead).

occupied_memory: total de mem�ria ocupada pelos processos, n�o leva em
considera��o o overhead.

check_free_memory: checa se � poss�vel resolver uma requisi��o de mem�ria
por X bytes. Leva em considera��o a mem�ria numericamente dispon�vel e a
disposi��o dos blocos (fragmenta��o externa).

first_fit: m�todo que implementa o algoritmo de aloca��o de mem�ria first fit.
Recebe um inteiro representando a quantidade de mem�ria desejada e retorna
um inteiro que representa o endere�o do bloco que foi usado para satisfazer a
chamada por mem�ria.

best_fit: m�todo que implementa o algoritmo de aloca��o de mem�ria best fit.
Recebe um inteiro representando a quantidade de mem�ria desejada e retorna
um inteiro que representa o endere�o do bloco que foi usado para satisfazer a
chamada por mem�ria.

quick_fit: m�todo que implementa o algoritmo de aloca��o de mem�ria quick fit.
Recebe um inteiro representando a quantidade de mem�ria desejada e retorna
um inteiro que representa o endere�o do bloco que foi usado para satisfazer a
chamada por mem�ria.
statistics_table: tabela de estat�sticas usada pelo algoritmo quick fit, cada linha
cont�m o tamanho da requisi��o de mem�ria e a quantidade de vezes que ela
aconteceu. A tabela � ordenada pelas ocorr�ncias.

quick_fit_free_blocks: listas especializadas de blocos livres gerenciadas pelo
algoritmo quick fit.

number_quick_lists: quantidade de listas a serem criadas pelo algoritmo de
aloca��o de mem�ria quick fit.

minimum_amount_calls: quantidade m�nima de requisi��es de mem�ria que o
algoritmo quick fit deve esperar acontecer antes de criar suas listas de blocos
livres.
*/

//#include "MemoryBlock.cpp"
//#include <list>
//#include <queue>
//
//#define FIRST_FIT 0
//#define BEST_FIT 1
//#define QUICK_FIT 2
//
//using namespace std;
//
//class MemoryManager
//{
//protected:
//    list<MemoryBlock*> memory;
//    queue<MemoryBlock*> free_blocks_list;
//	
//
//public:
//
//    MemoryBlock* malloc()
//    {
//	    
//    }
//
//	void free(MemoryBlock* block)
//    {
//	    
//    }
//
//	void set_allocation_algorithm(int algorithm)
//    {
//	    
//    }
//
//    int get_total_memory()
//    {
//	    
//    }
//	
//	int get_memory_overhead()
//    {
//	    
//    }
//
//	int get_available_memory()
//    {
//        return get_total_memory() - (get_memory_overhead() + get_occupied_memory());
//    }
//
//	int get_occupied_memory()
//    {
//	    
//    }
//};