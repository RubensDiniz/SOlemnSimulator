#ifndef CORE_CPP
#define CORE_CPP
#include "Process.cpp"

class Core{
protected:
    Process* current_process;
    int quantum;
    int remaining_quantum;
    int core_id;

public:
    Core(int id) {
        current_process = nullptr;
        quantum = -1;
        remaining_quantum = quantum;
        core_id = id;
    }

    Core(int id, int q){
        current_process = nullptr;
        quantum = q;
        remaining_quantum = quantum;
        core_id = id;
    }

    int core_status(){
        if(current_process == nullptr){
            return -1;
        } else {
            return current_process->get_state();
        }
    }

    void tick(){
        std::cout << "CORE TICK: Core " << core_id << " -- ";
        if (current_process == nullptr){
            std::cout << "SEM PROCESSO" << std::endl;
            return;
        }

        std::cout << "CHAMANDO TICK DO PROCESSO " << current_process->get_id() << std::endl;
        if (quantum >= 0) remaining_quantum--;
        current_process->tick();
        if (quantum >= 0) std::cout << "    QUANTUM: " << (remaining_quantum + 1) << " -> " << remaining_quantum << std::endl;
    }

    void print_core_status(){
        if (has_process()){
            std::cout << "[P" << current_process->get_id() << ", " << current_process->get_remaining_time();
            if (quantum >= 0){
                std::cout << ", " << remaining_quantum;
            }
            std::cout << "] ";
        } else {
            std::cout << "[ ] ";
        }
    }

    Process* get_process(){
        return current_process;
    }

    void set_process(Process* process){
        remaining_quantum = quantum;
        current_process = process;
    }

    bool has_process(){
        return current_process != nullptr;
    }

    bool should_deschedule(){
        return (current_process->get_state() == STATE_TERMINATED || remaining_quantum == 0);
    }

    int get_process_status(){
        return current_process->get_state();
    }

	int get_id(){
        return core_id;
    }

    int get_remaining_quantum(){
        return remaining_quantum;
    }
};

#endif