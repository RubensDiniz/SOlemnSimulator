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
    // TODO constructors etc

    Simulator(int cores, int qnt){
        processor_cores_number = cores;
        quantum = qnt;
        kernel = Kernel::get_instance();
        CPU::get_cpu()->set_cores(cores);
    }

    void scheduling_algorithm(int i){
    	Kernel::get_instance()->scheduling_algorithm(i);
    }

    thread run(){
        CPU::get_cpu()->set_cores(processor_cores_number);
        batch_process_init(20);
        scheduling_algorithm(0);

        return kernel->run();
    }

    void create_random_process(int min, int max){
        int time = rand() % max + min;
        Kernel::get_instance()->create_process(time);
    }

    void batch_process_init(int amount){
        int min = 5;
        int max = 15;

        for (int i = 0; i < amount; ++i) {
            create_random_process(min, max);
        }
    }
};

//perfeito
CPU* CPU::cpu = nullptr;
Kernel* Kernel::instance = nullptr;
Scheduler* Scheduler::scheduler = nullptr;

int main(){
    Simulator* sim = new Simulator(4,0);

    thread t = sim->run();

    t.join();

    cout << "End" << endl;
}

#endif