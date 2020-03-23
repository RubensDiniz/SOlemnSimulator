#include <algorithm>
#ifndef SIMULATOR_CPP
#define SIMULATOR_CPP
#include "Kernel.cpp"

class Simulator{
protected:
    Kernel* kernel;
    int processor_cores_number;
    int quantum;

public:

    Simulator(int cores, int qnt){
        processor_cores_number = cores;
        quantum = qnt;
        kernel = Kernel::get_instance();
        //CPU::get_cpu()->set_cores(cores);
    }

    void scheduling_algorithm(int i){
    	Kernel::get_instance()->scheduling_algorithm(i);
    }

    void run(){
        //int algorithm = FIFO_SCHEDULER;
        //int algorithm = SHORTEST_JOB_FIRST;
        int algorithm = ROUND_ROBIN;

        scheduling_algorithm(algorithm);
        if (algorithm == ROUND_ROBIN){
            CPU::get_cpu()->set_cores(processor_cores_number, quantum); // TODO alterar quantum na linha 63?
        } else {
            CPU::get_cpu()->set_cores(processor_cores_number);
        }

        batch_process_init(20);

        auto add_proc = kernel->run();
        auto run_proc = Scheduler::get_scheduler()->run();

        add_proc.join();
        run_proc.join();
    }

    void create_random_process(int min, int max){
        int time = rand() % max + min;
        Kernel::get_instance()->create_process(time);
    }

    void batch_process_init(int amount){
        int min = 5;
        int max = 20;

        for (int i = 0; i < amount; ++i) {
            create_random_process(min, max);
        }
    }
};

CPU* CPU::cpu = nullptr;
Kernel* Kernel::instance = nullptr;
Scheduler* Scheduler::scheduler = nullptr;

int main(){
    Simulator* sim = new Simulator(4,10);

    /*thread t = sim->run();

    t.join();*/

    sim->run();

    cout << "End" << endl;
}

#endif