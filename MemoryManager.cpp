#ifndef MEMORYMANAGER_CPP
#define MEMORYMANAGER_CPP
#include "MemoryBlock.cpp"
#include <list>
#include <queue>
#include <map>

#define FIRST_FIT 0
#define BEST_FIT 1
#define QUICK_FIT 2

using namespace std;

class MemoryManager {
protected:
    static MemoryManager* instance;

    list<MemoryBlock*> memory;          // RAM instalada no sistema
    MemoryBlock* free_blocks_list;      // Primeiro bloco de memória livre
    int allocation_algorithm;
    int total_memory;
    int memory_overhead;
    int occupied_memory;                // TODO inicializar ela como total_memory e mudar dinamicamente
    map<int, int> statistics_table;     // TODO "tabela de estatísticas" + get/set? - ver item N / tamanho da requisição x quantia que acontece
    // ??? quick_fit_free_blocks;       // TODO "listas especializadas" + get/set? - ver item O / lista de listas?
    int number_quick_lists;
    int minimum_amount_calls;

public:

    //classe que implementa o gerenciador de memória, suas estruturas de dados e algoritmos
    MemoryManager(){

    }

    static MemoryManager* get_instance(){
        if (instance == nullptr)
            instance = new MemoryManager();
        return instance;
    }

    MemoryBlock* malloc(int requested_memory) {
        /*
        método que simula uma chamada de sistema por memória, tem como
        parâmetro um inteiro que representa a quantidade de memória solicitada em
        bytes. Tem como retorno o endereço do bloco de memória que foi usado para
        satisfazer a chamada. Chama um algoritmo de alocação de memória para
        efetuar a alocação de um bloco
         */
        return nullptr;
    }

    MemoryBlock* free(MemoryBlock* block) {
        //void ou nao? por mim tanto faz, imaginei como um list.pop();

        /*
        simula uma chamada de sistema solicitando a desalocação de um dado
        endereço de memória (parâmetro). O bloco é marcado como livre por meio da
        sua inserção na lista de blocos livres.
         */

        return nullptr;
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

    int first_fit(int requested_memory) {
        /*
        implementa first_fit e retorna um inteiro que representa o endereço (na lista) do bloco
        que foi usado para satisfazer a chamada por memória. (pode retornar um ponteiro MemoryBlock* iirc)
         */
        return 0;
    }

    int best_fit(int requested_memory) {
        /*
        implementa best_fit e retorna um inteiro que representa o endereço (na lista) do bloco
        que foi usado para satisfazer a chamada por memória. (pode retornar um ponteiro MemoryBlock* iirc)
         */
        return 0;
    }

    int quick_fit(int requested_memory) {
        /*
        implementa quick_fit e retorna um inteiro que representa o endereço (na lista) do bloco
        que foi usado para satisfazer a chamada por memória. (pode retornar um ponteiro MemoryBlock* iirc)
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

        // TODO atualizar variável constantemente... iniciar ela como == total memory?
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
};

#endif

//TODO aqui em baixo tem anotações que o caio fez
/*
Celulas
blocos: Projeto 2
Paginas :
	Representada com chaves
	Dentro de uma pagina pode ter varios blocos, dentro de um bloco tem varias celulas
	O disco rigido contem paginas;

	Caso todos os blocos das paginas estejam ocupadas um novo processo nao consegue ser criado( ele e abortado), para
	corrigir isso, podemos decidir um limiar( ex: 80% ) pegar uma pagina que esteja ociosa e liberar a pagina que estava ociosa para tentar alocar o novo processo.

Swap-out: Tirar da ram e coloca no HD
Swap-in : Tira do HD e coloca na RAM

NAO EXISTE EXECUCAO DE PROCESSO SEM OS DADOS DELE ESTA NA RAM - ENFASE

PQ a inicializacao do SO é lenta? Pois existe um ciclo de ficar sempre lendo/escrevendo no HD e lendo/escrevendo na RAM, como melhorar? Dando upgrade na quantidade de memoria RAM e/ou colcoando um SSD.


Thread pro gerenciador de memoria pode ajudar TODO

Gerenciador de memoria: responsavel por alocar e desalocar os blocos( Contem uma lista de blocos livres)

faixa de valores 1 byte ate 4096 byte pro generate_random_statc_memory_call

Projeto 3: Lidar com arquivos


processo -> kernel -> Gerenciador de memoria ---

quem gera requisicao por memoria é o processo, o processo tem 2 metodos ( generate random static e dinamic ), quando ele gera o numero aleatorio (represta o quanto de memoria vai precisar pro processo) dai ele pede pro kernel essa quantidade memoria, e o kernel pede a memoria pro gerenciador de memoria
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