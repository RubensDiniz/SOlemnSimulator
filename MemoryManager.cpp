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
        //void ou não? por mim tanto faz, imaginei como um list.pop();
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
-----memory_manager: classe que implementa o gerenciador de memória, suas estruturas
de dados e algoritmos:

memory: estrutura de dados usada para representar a memória RAM instalada
no sistema, é composta por memory_blocks.

free_blocks_list: ponteiro para o primeiro bloco de memória livre, o qual deve
fazer parte da lista de blocos livres.

malloc: método que simula uma chamada de sistema por memória, tem como
parâmetro um inteiro que representa a quantidade de memória solicitada em
bytes. Tem como retorno o endereço do bloco de memória que foi usado para
satisfazer a chamada. Chama um algoritmo de alocação de memória para
efetuar a alocação de um bloco.

free: simula uma chamada de sistema solicitando a desalocação de um dado
endereço de memória (parâmetro). O bloco é marcado como livre por meio da
sua inserção na lista de blocos livres.

set_allocation_algorithm: método que seleciona o algoritmo de alocação de
memória a ser usado.

total_memory: quantidade de memória RAM instalada no sistema em bytes.

memory_overhead: quantidade de memória utilizada pelo próprio
memory_manager.

available_memory: quantidade de memória livre disponível para os processos
num dado instante de tempo. available = total - (occupied + overhead).

occupied_memory: total de memória ocupada pelos processos, não leva em
consideração o overhead.

check_free_memory: checa se é possível resolver uma requisição de memória
por X bytes. Leva em consideração a memória numericamente disponível e a
disposição dos blocos (fragmentação externa).

first_fit: método que implementa o algoritmo de alocação de memória first fit.
Recebe um inteiro representando a quantidade de memória desejada e retorna
um inteiro que representa o endereço do bloco que foi usado para satisfazer a
chamada por memória.

best_fit: método que implementa o algoritmo de alocação de memória best fit.
Recebe um inteiro representando a quantidade de memória desejada e retorna
um inteiro que representa o endereço do bloco que foi usado para satisfazer a
chamada por memória.

quick_fit: método que implementa o algoritmo de alocação de memória quick fit.
Recebe um inteiro representando a quantidade de memória desejada e retorna
um inteiro que representa o endereço do bloco que foi usado para satisfazer a
chamada por memória.
statistics_table: tabela de estatísticas usada pelo algoritmo quick fit, cada linha
contém o tamanho da requisição de memória e a quantidade de vezes que ela
aconteceu. A tabela é ordenada pelas ocorrências.

quick_fit_free_blocks: listas especializadas de blocos livres gerenciadas pelo
algoritmo quick fit.

number_quick_lists: quantidade de listas a serem criadas pelo algoritmo de
alocação de memória quick fit.

minimum_amount_calls: quantidade mínima de requisições de memória que o
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