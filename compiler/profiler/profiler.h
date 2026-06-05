#ifndef PROFILER_H
#define PROFILER_H

#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
=====================================
Profiling Information
=====================================
*/

#define MAX_FUNCTIONS 100

typedef struct
{
    char functionName[100];

    int callCount;

    double totalExecutionTime;

    struct timespec startTime;

} ProfileEntry;

/*
=====================================
Global Profiling Table
=====================================
*/

extern ProfileEntry profileTable[MAX_FUNCTIONS];

extern int profileCount;

/*
=====================================
Runtime API
=====================================
*/

/*
    Called at function entry
*/
void profiler_start(
    const char* functionName
);

/*
    Called at function exit
*/
void profiler_end(
    const char* functionName
);

/*
    Print report to console
*/
void profiler_print_report();

/*
    Export report to CSV
*/
void profiler_export_csv(
    const char* filename
);

#ifdef __cplusplus
}
#endif

#endif