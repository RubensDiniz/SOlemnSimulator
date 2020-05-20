#ifndef PROCESS_CPP
#define PROCESS_CPP
#include <list>
#include <iostream>
#include "MemoryBlock.cpp"

#define STATE_READY 0
#define STATE_RUNNING 1
#define STATE_TERMINATED 2

class Process {
protected:
    int process_id;
    int total_time;
    int state;
    int remaining_time;
    int total_memory_used;
    std::list<MemoryBlock*> memory_pointers; // lista com os endereços de blocos de memória ocupados por esse processo //TODO MB* -> int?

public:
    Process(int id, int tt, int tmu){
        process_id = id;
        total_time = tt;
        state = STATE_READY;
        remaining_time = tt;
        total_memory_used = tmu;
        //memory_pointers = NULL ? TODO
    }

    void tick(){
        int old_time = remaining_time;
        remaining_time--;

        if (remaining_time <= 0){
            state = STATE_TERMINATED;
        } else {
            state = STATE_RUNNING;
        }

        //std::cout << "    PROCESS TICK -- PROCESSO " << process_id << " -- TIME: " << old_time << " -> " << remaining_time << std::endl;
    }

    void terminate(){
        state = STATE_TERMINATED;
    }

    void generate_random_static_memory_call(){
        //TODO sinceramente não sei o que retornar nisso
        /*
        método que gera uma chamada de sistema por memória alocada estaticamente.
        Deve ser gerada pelo menos uma chamada antes do processo ser escalonado.
         */
    }

    void generate_random_dynamic_memory_call(){
        //TODO sinceramente não sei o que retornar nisso
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
};
#endif
