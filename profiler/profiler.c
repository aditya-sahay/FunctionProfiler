#include "profiler.h"

#include <stdio.h>
#include <string.h>

ProfileEntry profileTable[MAX_FUNCTIONS];
int profileCount = 0;

/*
=====================================
Find Function Entry
=====================================
*/

static ProfileEntry* findEntry(
    const char* functionName
)
{
    for(int i = 0; i < profileCount; i++)
    {
        if(strcmp(
            profileTable[i].functionName,
            functionName
        ) == 0)
        {
            return &profileTable[i];
        }
    }

    return NULL;
}

/*
=====================================
Create Function Entry
=====================================
*/

static ProfileEntry* createEntry(
    const char* functionName
)
{
    if(profileCount >= MAX_FUNCTIONS)
    {
        return NULL;
    }

    ProfileEntry* entry =
        &profileTable[profileCount++];

    strcpy(
        entry->functionName,
        functionName
    );

    entry->callCount = 0;
    entry->totalExecutionTime = 0.0;

    return entry;
}

/*
=====================================
Function Entry Hook
=====================================
*/

void profiler_start(
    const char* functionName
)
{
    ProfileEntry* entry =
        findEntry(functionName);

    if(entry == NULL)
    {
        entry = createEntry(
            functionName
        );
    }

    if(entry == NULL)
    {
        return;
    }

    entry->callCount++;

    clock_gettime(
        CLOCK_MONOTONIC,
        &entry->startTime
    );
}

/*
=====================================
Function Exit Hook
=====================================
*/

void profiler_end(
    const char* functionName
)
{
    ProfileEntry* entry =
        findEntry(functionName);

    if(entry == NULL)
    {
        return;
    }

    struct timespec endTime;

    clock_gettime(
        CLOCK_MONOTONIC,
        &endTime
    );

    double elapsed =
        (endTime.tv_sec -
         entry->startTime.tv_sec)
        +
        (endTime.tv_nsec -
         entry->startTime.tv_nsec)
        / 1000000000.0;

    entry->totalExecutionTime +=
        elapsed;
}

/*
=====================================
Print Report
=====================================
*/

void profiler_print_report()
{
    printf("\n");
    printf("=====================================\n");
    printf("FUNCTION PROFILING REPORT\n");
    printf("=====================================\n");

    printf(
        "%-20s %-10s %-15s\n",
        "Function",
        "Calls",
        "Time(ms)"
    );

    for(int i = 0; i < profileCount; i++)
    {
        printf(
            "%-20s %-10d %-15.3f\n",
            profileTable[i].functionName,
            profileTable[i].callCount,
            profileTable[i].totalExecutionTime
            * 1000.0
        );
    }

    printf("=====================================\n");
}

/*
=====================================
Export CSV
=====================================
*/

void profiler_export_csv(
    const char* filename
)
{
    FILE* fp =
        fopen(filename, "w");

    if(fp == NULL)
    {
        return;
    }

    fprintf(
        fp,
        "Function,Calls,Time(ms)\n"
    );

    for(int i = 0; i < profileCount; i++)
    {
        fprintf(
            fp,
            "%s,%d,%.3f\n",
            profileTable[i].functionName,
            profileTable[i].callCount,
            profileTable[i].totalExecutionTime
            * 1000.0
        );
    }

    fclose(fp);
}