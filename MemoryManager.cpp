#define FIRST_FIT 0
#define BEST_FIT 1
#define QUICK_FIT 2

#include "MemoryBlock.cpp"
#include <list>
#include <queue>

class MemoryManager {
    //TODO singleton?

protected:
    std::list<MemoryBlock*> memory;     // RAM instalada no sistema TODO é assim mesmo que eu faço uma lista?
    MemoryBlock* free_blocks_list;      // Primeiro bloco de memória livre
    int allocation_algorithm;
    int total_memory;
    int memory_overhead;
    // ??? statistics_table             // TODO "tabela de estatísticas" + get/set? - ver item N
    // ??? quick_fit_free_blocks        // TODO "listas especializadas" + get/set? - ver item O
    int number_quick_lists;
    int minimum_amount_calls;

public:

    //classe que implementa o gerenciador de memória, suas estruturas de dados e algoritmos
    MemoryManager(){
        
    }
    
    MemoryBlock* malloc(int requested_memory){ //TODO MB* -> int?
        /*
        método que simula uma chamada de sistema por memória, tem como
        parâmetro um inteiro que representa a quantidade de memória solicitada em
        bytes. Tem como retorno o endereço do bloco de memória que foi usado para
        satisfazer a chamada. Chama um algoritmo de alocação de memória para
        efetuar a alocação de um bloco
         */
        return nullptr;
    }

    MemoryBlock* free(MemoryBlock* block){ //TODO MB* -> int?
        //void ou nao? por mim tanto faz, imaginei como um list.pop();
        /*
        simula uma chamada de sistema solicitando a desalocação de um dado
        endereço de memória (parâmetro). O bloco é marcado como livre por meio da
        sua inserção na lista de blocos livres.
         */
    }    

    void set_allocation_algorithm(int algorithm){
        allocation_algorithm = algorithm;
    }

    bool check_free_memory() {
        /*
        Checa se é possível resolver uma requisição de memória por X bytes.
        Leva em consideração a memória numericamente disponível e a disposição
        dos blocos (fragmentação externa).
         */
        return false;
    }

    int first_fit(int requested_memory) {//TODO int?
        /*
        implementa first_fit e retorna um inteiro que representa o endereço (na lista?) do bloco
        que foi usado para satisfazer a chamada por memória.
         */
        return 0;
    }

    int best_fit(int requested_memory) { //TODO int?
        /*
        implementa best_fit e retorna um inteiro que representa o endereço (na lista?) do bloco
        que foi usado para satisfazer a chamada por memória.
         */
        return 0;
    }

    int quick_fit(int requested_memory) { //TODO int?
        /*
        implementa quick_fit e retorna um inteiro que representa o endereço (na lista?) do bloco
        que foi usado para satisfazer a chamada por memória.
         */
        return 0;
    }

    int get_total_memory() {
        return total_memory;
    }

    int get_memory_overhead() {
        return memory_overhead;
    }

    int get_available_memory() {
        return get_total_memory() - (get_memory_overhead() + get_occupied_memory());
    }

    int get_occupied_memory() {
        /*
        total de memória ocupada pelos processos, não leva em
        consideração o overhead
         */

        // TODO a gente percorre o "memory" e vai checando? sepá faz um int que fica atualizando...
    }

    int get_number_quick_lists() {
        return number_quick_lists;
    }
    void set_number_quick_lists(int n) {
        number_quick_lists = n;
    }

    int get_minimum_amount_calls() {
        return minimum_amount_calls;
    }
    void set_minimum_amount_calls(int m) {
        minimum_amount_calls = m;
    }
}

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