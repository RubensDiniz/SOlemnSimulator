#ifndef KERNEL_CPP
#define KERNEL_CPP
#include <vector>
#include "Scheduler.cpp"
#include "Process.cpp"

class Kernel{
protected:
    std::vector<Process*> process_control_table; //TODO

    static Kernel* instance;

    Kernel(){
    	
    }

public:

    static Kernel* get_instance(){
        if (instance == nullptr)
            instance = new Kernel();
        return instance;
    }

    thread run(){
    	for(auto process : process_control_table)
    	{
            Scheduler::get_scheduler()->insert_process(process);
    	}

        return Scheduler::get_scheduler()->run();
    }

    Process* create_process(int total_time){
        int id = process_control_table.size();
        Process* proc = new Process(id, total_time);
        process_control_table.push_back(proc);

        cout << "CRIADO PROCESSO " << id << " -- TOTAL TIME: " << total_time << endl;
    	
        return proc;
    }

    void kill_process(Process* p){
        p->terminate();
        //int id = p->get_id();
        //process_control_table[id] == nullptr; //não remover da lista pra não bugar a relação id = indíce
        //delete p(?)
    }

    Process* get_process(int id){
        if (id < process_control_table.size()){
            return process_control_table[id];
        } else {
            return nullptr;
        }
    }

    //Process* run_process(Process* p){
    //    //Ver se é isso mesmo
    //    //p->tick();
    //}

    void scheduling_algorithm(int i){
        Scheduler::get_scheduler()->set_scheduling_algorithm(i);
    }
};
#endif