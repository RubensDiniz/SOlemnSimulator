#ifndef PROCESS_CPP
#define PROCESS_CPP
#include <list>
#include <iostream>
#include "MemoryBlock.cpp"
#include "Kernel.cpp"

#define STATE_READY 0
#define STATE_RUNNING 1
#define STATE_TERMINATED 2

using namespace std;

class Process {
protected:
    int process_id;
    int total_time;
    int state;
    Kernel* kernel;
    int remaining_time;
    int total_memory_used;
    list<MemoryBlock*> memory_pointers; // lista com os endereços de blocos de memória ocupados por esse processo

public:
    Process(int id, int tt){
        process_id = id;
        total_time = tt;
        state = STATE_READY;
        remaining_time = tt;
        total_memory_used = 0;
        generate_random_static_memory_call();
    }

    void tick(){
        int old_time = remaining_time;
        remaining_time--;

        if (remaining_time <= 0){
            state = STATE_TERMINATED;
        } else {
            state = STATE_RUNNING;
        }

        //cout << "    PROCESS TICK -- PROCESSO " << process_id << " -- TIME: " << old_time << " -> " << remaining_time << endl;
    }

    void terminate(){
        state = STATE_TERMINATED;
    }

    void generate_random_static_memory_call(){
        //TODO chamam o malloc do memory manager, retorna endereço (ponteiro) do bloco, de 1 a 4096 bytes
		int requested_memory = rand() % 4097;	// 1 + 4096

		// TODO chamam kernel ou memory manager?

        /*
        método que gera uma chamada de sistema por memória alocada estaticamente.
        Deve ser gerada pelo menos uma chamada antes do processo ser escalonado.
         */

    	Kernel::get_instance()
    }

    void generate_random_dynamic_memory_call(){
        //TODO chamam o malloc do memory manager, retorna endereço (ponteiro) do bloco, de 1 a 4096 bytes
		int requested_memory = rand() % 4097;

		// TODO chamam kernel ou memory manager?

        /*
        método que gera uma chamada de sistema por memória alocada dinamicamente.
        Deve ser gerada pelo menos uma chamada depois que o processo é escalonado.
        Deve ter X% de chance de acontecer a cada segundo de quantum, no caso do round robin.
         */
    }

    int get_state(){
        return state;
    }

    int get_total_time(){
        return total_time;
    }

    int get_remaining_time(){
        return remaining_time;
    }

    int get_id(){
        return process_id;
    }

	void free_blocks()
    {
	    for(auto block : memory_pointers)
	    {
		    
	    }
    }
};
#endif
