#ifndef CORE_CPP
#define CORE_CPP
#include "Process.cpp"

class Core{
protected:
    Process* current_process; // Checa o estado por este processo ser nulo ou não
    int quantum;
    int aux_quantum;
    int core_id;

public:
    Core(int id) {
        current_process = nullptr;
        quantum = -1;
        aux_quantum = quantum;
        core_id = id;
    }

    Core(int id, int q){
        current_process = nullptr;
        quantum = q;
        aux_quantum = quantum;
        core_id = id;
    }

    int core_status(){
        if(current_process == nullptr){
            return -1;
        } else {
            return current_process->get_state();
        }
    }

    void set_process(Process* process){
        aux_quantum = quantum;
        current_process = process;
    }

    Process* get_process(){
        return current_process;
    }

    bool has_process(){
        return current_process != nullptr;
    }

    bool should_deschedule(){
        return (current_process->get_state() == STATE_TERMINATED || aux_quantum == 0);
    }

    void tick(){
        std::cout << "CORE TICK: Core " << core_id << " -- ";
        if (current_process == nullptr){
            std::cout << "SEM PROCESSO" << std::endl;
            return;
        }

        std::cout << "CHAMANDO TICK DO PROCESSO " << current_process->get_id() << std::endl;
        if (quantum >= 0) aux_quantum--;
        current_process->tick();
    }

    int get_process_status(){
        return current_process->get_state();
    }

	int get_id(){
        return core_id;
    }
};

#endif