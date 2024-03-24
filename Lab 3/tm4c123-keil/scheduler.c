#include "scheduler.h"
//#include <stdint.h>  /* Standard integers. WG14/N843 C99 Standard */

osThread tasks_keteer[NUM_OF_TASKS];
volatile int counter = 0;
extern int flag;
extern int l_tickCtr;
void create_task (void (*Task)(), uint32_t ms_periodicity )
{
	osThread taskaya_wa7da;
	taskaya_wa7da.sp = Task;
	taskaya_wa7da.periodicity = ms_periodicity;
	tasks_keteer[counter] = taskaya_wa7da;
	counter++;
	
}
void Tasks_Scheduler  (void)
{
	while(1){
	if(flag == 1)
	{
		flag = 0;
		__asm("cpsid i");
		 for(int i = 0; i<NUM_OF_TASKS; i++)
		{
			if(l_tickCtr%tasks_keteer[i].periodicity == 0)
			{
				tasks_keteer[i].sp();
			}
		}
			
		__asm("cpsie i");

		
		
	}
	
	
}
	
}