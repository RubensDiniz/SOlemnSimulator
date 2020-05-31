#ifndef KERNEL_CPP
#define KERNEL_CPP
#include <vector>
#include "Scheduler.cpp"
#include "Process.cpp"
#include "MemoryManager.cpp"

using namespace std;

class Kernel{
protected:
    vector<Process*> process_control_table;
    MemoryManager* memory_manager;

    static Kernel* instance;

    Kernel(){
        memory_manager = new MemoryManager();
        memory_manager->set_algorithm(FIRST_FIT);
    }

    void create_process_thread(){
        int min = 5;
        int max = 20;

        while(true) { //while !stop_queued
            int time = rand() % (max-min) + min;
            auto proc = create_process(time);
            Scheduler::get_scheduler()->insert_process(proc);
            //cout << "KERNEL: PROCESSO CRIADO COM ID: " << proc->get_id() << ", TOTAL TIME: " << time << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

public:

    static Kernel* get_instance(){
        if (instance == nullptr)
            instance = new Kernel();
        return instance;
    }

    thread run(){
        thread t = thread(&Kernel::create_process_thread, this);
        return t;
    }

    Process* create_process(int total_time){
        int id = process_control_table.size();
        Process* proc = new Process(id, total_time); // TODO mais parâmetros
        process_control_table.push_back(proc);

        //cout << "CRIADO PROCESSO " << id << " -- TOTAL TIME: " << total_time << endl;
    	
        return proc;
    }

    void scheduling_algorithm(int i){
        Scheduler::get_scheduler()->set_scheduling_algorithm(i);
    }

    Process* get_process_by_id(int id){
        if (id < process_control_table.size()){
            return process_control_table[id];
        } else {
            return nullptr;
        }
    }

    void kill_process(Process* p){
        p->terminate();
    }

    MemoryBlock* memory_allocation(int requested_memory){
        /*
        método que simula uma chamada de sistema por memória, tem como parâmetro um
        inteiro que representa a quantidade de memória solicitada em bytes. Tem como
        retorno o endereço do bloco de memória que foi usado para satisfazer a chamada
         */
        //return NULL;
        return memory_manager->malloc(requested_memory);
    }

    void free_memory(MemoryBlock* address){
        /*
        simula uma chamada de sistema solicitando a desalocação de
        um dado endereço de memória (parâmetro).
         */

        //TODO delete?
        memory_manager->free(address);
    }
};

/*
dentro do run, old:
for(auto process : process_control_table) {
    Scheduler::get_scheduler()->insert_process(process);
}
return Scheduler::get_scheduler()->run();*/

//Process* run_process(Process* p){
//    //Ver se é isso mesmo
//    //p->tick();
//}
#endif