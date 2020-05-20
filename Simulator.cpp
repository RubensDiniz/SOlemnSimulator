#include <algorithm>
#ifndef SIMULATOR_CPP
#define SIMULATOR_CPP
#include "Kernel.cpp"

#define FIRST_FIT 0
#define BEST_FIT 1
#define QUICK_FIT 2

class Simulator{
protected:
    Kernel* kernel;
    int processor_cores_number;
    int quantum;
    int total_installed_memory;     // quantidade total de memória RAM instalada no sistema. TODO passar isso p/ manager?
    int number_quick_lists;         // quantidade de listas a serem criadas pelo algoritmo quick_fit TODO passar isso p/ manager?
    int number_memory_calls;        // quantidade de requisições de memória que o quick fit deve acumular em sua tabela de estatísticas antes de construir suas listas TODO passar isso p/ manager?

public:
    Simulator(int pcn, int q, int tim, int nql, int nmc){
        processor_cores_number = pcn;
        quantum = q;
        kernel = Kernel::get_instance();
        total_installed_memory = tim;
        number_quick_lists = nql;
        number_memory_calls = nmc;
        //CPU::get_cpu()->set_cores(cores);
    }

    void scheduling_algorithm(int i){
    	Kernel::get_instance()->scheduling_algorithm(i);
    }

    void memory_allocation_algorithm(int i){
        /*
        algoritmo de alocação de memória a ser usado pelo memory_manager,
        deve ser selecionado e definido a partir dessa classe.
         */
        // TODO memoryManager singleton?
        //something something MemoryManager::get_instance()->set_allocation_algorithm(i);
    }

    void run(){
        //int algorithm = FIFO_SCHEDULER;
        //int algorithm = SHORTEST_JOB_FIRST;
        int algorithm = ROUND_ROBIN;

        //TODO ----- setar algoritmo de aloca��o de mem�ria!

        scheduling_algorithm(algorithm);

        if (algorithm == ROUND_ROBIN){
            CPU::get_cpu()->set_cores(processor_cores_number, quantum); // alterar quantum na linha 66~
        } else {
            CPU::get_cpu()->set_cores(processor_cores_number);
        }

        //batch_process_init(20);

        auto add_proc = kernel->run();
        auto run_proc = Scheduler::get_scheduler()->run();

        add_proc.join();
        run_proc.join();
    }

    void create_random_process(int min, int max){
        int time = rand() % max + min;
        Kernel::get_instance()->create_process(time);
    }

//    void batch_process_init(int amount){
//        TODO reimplementar? criar processos que já estarão lá no início da aplicação
//        int min = 5;
//        int max = 20;
//
//        for (int i = 0; i < amount; ++i) {
//            create_random_process(min, max);
//        }
//    }
};

CPU* CPU::cpu = nullptr;
Kernel* Kernel::instance = nullptr;
Scheduler* Scheduler::scheduler = nullptr;

int main(){
    Simulator* sim = new Simulator(4,10); // TODO preencher os outros parâmetros...

    sim->run();

    cout << "End" << endl;
}

/*
thread t = sim->run();
t.join();
 */

#endif