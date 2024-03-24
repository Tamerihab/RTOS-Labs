#ifndef scheduler_h
#define scheduler_h
#include <stdint.h>
#define NUM_OF_TASKS 3

/*Creating a Thread Control Block*/
typedef struct{
    void (*sp)(); //Pointer to function
    uint32_t periodicity;   
}osThread;

void create_task (void (*Task)(), uint32_t ms_periodicity );
void Tasks_Scheduler  (void);

#endif