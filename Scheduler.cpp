#ifndef SCHEDULER_CPP
#define SCHEDULER_CPP

#define FIFO_SCHEDULER 0
#define SHORTEST_JOB_FIRST 1
#define ROUND_ROBIN 2

#include <vector>
#include <list>
#include <thread>
#include <chrono>
#include "Process.cpp"
#include "CPU.cpp"

using namespace std;

class Scheduler{
protected:
    list<Process*> ready_queue;
    static Scheduler* scheduler;
    void (*schedule)(list<Process*>);
    int operation_mode;

    void schedule_process(Core* core){
        if(ready_queue.empty())
        {
            cout << "NAO HA PROCESSO NA READY QUEUE PARA ALOCAR NO CORE " << core->get_id() << endl;
            return;
        }

        Process* p;

        switch(operation_mode){
            case FIFO_SCHEDULER:
                p = fifo_scheduler();
                break;

            case SHORTEST_JOB_FIRST:
                p = shortest_job_first();
                break;

            case ROUND_ROBIN:
                p = round_robin();
                break;

            default:
                p = nullptr;
        }

        core->set_process(p);
        cout << "ALOCADO PROCESSO " << p->get_id() << " AO CORE " << core->get_id() << endl;
    }

    void deschedule_process(Core* core){
        cout << "DESALOCADO PROCESSO " << core->get_process()->get_id() << " DO CORE " << core->get_id() << endl;
        core->set_process(nullptr);
    }

    Process* fifo_scheduler() {
        auto process = ready_queue.front();
        ready_queue.pop_front();
        return process;
    }

    Process* shortest_job_first(){
        auto it = ready_queue.begin();
        Process* p = *it;

        for(it = it; it != ready_queue.end(); it++){
            Process* c_p = *it;

            if (c_p->get_total_time() < p->get_total_time()){
                p = c_p;
            }
        }

        ready_queue.remove(p);
        return p;
    }

    Process* round_robin(){
        auto process = ready_queue.front();
        ready_queue.pop_front();
        return process;
    }

    //nome tbd
    void main_process(){
        CPU* cpu = CPU::get_cpu();

        int total_time = 0;
        auto processes = ready_queue;

        bool queue_has_process = !ready_queue.empty();
        int core_has_process = 0;

        cout << "ENTRANDO MAIN PROCESS" << endl;
        //while (queue_has_process || core_has_process > 0) {
    	while(true){ // while !stop_queued
            cout << "LOOP " << total_time << endl;
            core_has_process = 0;

            for (auto core : cpu->get_cores()){
                if (core->has_process()){
                    auto p = core->get_process();
                    cout << "CORE " << core->get_id() << " TEM PROCESSO " << p->get_id() << endl;

                    if (core->should_deschedule()){
                        deschedule_process(core);
                        if (operation_mode == ROUND_ROBIN && p->get_state() != STATE_TERMINATED) insert_process(p);
                    } else {
                        core->tick();
                    }
                } else {
                    schedule_process(core);
                }

                if (core->has_process())
                    core_has_process++;
            }

            std::this_thread::sleep_for(std::chrono::seconds(1));
            queue_has_process = !ready_queue.empty();
            total_time++;
        }
        cout << "FIM EM " << total_time << endl;
    }

public:
    void set_scheduling_algorithm(int mode){
        operation_mode = mode;
    }

    thread run(){
        thread t(&Scheduler::main_process, this);
        return t;
    }

    void insert_process(Process* process){
        ready_queue.push_back(process);
    }

    static Scheduler* get_scheduler(){
        if (scheduler == nullptr)
            scheduler = new Scheduler();
        return scheduler;
    }
};
#endif