#include "spede.h"      // for IO_DELAY() needed here below
#include "extern.h"     // for current_run_pid needed here below
#include "proc.h"       // for prototypes of process functions
#include "syscall.h"    // for system calls

// IO_DELAY() should be encapsulated in a loop 1666000 times
// However, IO_DELAY() delays CPU by 0.65us
//   -> Therefore, we should loop 1s/0.65us = 1538461.53846 -> 1538462
#define DELAY_SECOND 1538462

void InitProc() {
    int i;

    while (1) {
        cons_printf("Init runs\n");

        for (i = 0; i < DELAY_SECOND; i++) {
            IO_DELAY();
        }
    }
}

void UserProc() {
    while(1){
	cons_printf("%d ",pid);   // Display the PID
	cons_printf("%d ",time);  // Display the PID, time
	
	sleep(pid % 5 + 1);       // sleep_time = pid % 5 + 1
    }
}
