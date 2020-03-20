#ifndef PROCESS_CPP
#define PROCESS_CPP
#include <vector>
#include <iostream>

#define STATE_READY 0
#define STATE_RUNNING 1
#define STATE_TERMINATED 2

class Process {
protected:
    int process_id;
    int total_time;
    int state;
    int remaining_time;

public:
    Process(int id, int tt){
        process_id = id;
        total_time = tt;
        remaining_time = tt;
        state = STATE_READY;
    }

    void tick(){
        int old_time = remaining_time;
        remaining_time--;

        if (remaining_time <= 0){
            state = STATE_TERMINATED;
        } else {
            state = STATE_RUNNING;
        }

        std::cout << "    PROCESS TICK -- PROCESSO " << process_id << " -- TIME: " << old_time << " -> " << remaining_time << std::endl;
    }

    int get_state(){
        return state;
    }

    int get_total_time(){
        return total_time;
    }

    int get_id(){
        return process_id;
    }

    void terminate(){
        state = STATE_TERMINATED;
    }
};
#endif
