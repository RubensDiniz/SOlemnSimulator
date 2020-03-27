#ifndef CPU_CPP
#define  CPU_CPP
#include <vector>
#include <list>
#include "Core.cpp"

class CPU {
protected:
    std::list<Core*> cores;
    static CPU* cpu;

    CPU() = default;

public:
    static CPU* get_cpu() {
        if (cpu == nullptr)
            cpu = new CPU();
        return cpu;
    };

    std::list<Core*> get_cores() {
        return cores;
    }

    void set_cores(int number) {
        if (!cores.empty())
            return;

        for (int i = 0; i < number; i++) {
            std::cout << "CPU -- Criando Core " << i << std::endl;
            cores.push_back(new Core(i));
        }
    }

    void set_cores(int number, int quantum) {
        if (!cores.empty())
            return;

        for (int i = 0; i < number; i++) {
            std::cout << "CPU -- Criando Core " << i << std::endl;
            cores.push_back(new Core(i, quantum));
        }
    }
};
#endif