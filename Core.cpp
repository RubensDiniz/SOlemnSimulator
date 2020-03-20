#ifndef CORE_CPP
#define CORE_CPP
#include "Process.cpp"

class Core{
protected:
    Process* current_process; // Checa o estado por este processo ser nulo ou não
    int quantum;
    int core_id;

public:
    Core(int id) {
        current_process = nullptr;
        quantum = 1;
        core_id = id;
    }

    Core(int id, int q){
        current_process = nullptr;
        quantum = q;
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
        current_process = process;
    }

    Process* get_process(){
        return current_process;
    }

    bool has_process(){
        return current_process != nullptr;
    }

    void tick(){
        std::cout << "CORE TICK: Core " << core_id << " -- ";
        if (current_process == nullptr)
        {
            std::cout << "SEM PROCESSO" << std::endl;
            return;
        }
            
        std::cout << "CHAMANDO TICK DO PROCESSO " << current_process->get_id() << std::endl;
        current_process->tick();
    }

    int get_process_status(){
        return current_process->get_state();
    }

	int get_id()
    {
        return core_id;
    }
};

#endif