#include "report.h"
#include "profiler.h"

#include <iostream>

using namespace std;

/*
=====================================
Console Report
=====================================
*/

void ReportGenerator::generateConsoleReport()
{
    profiler_print_report();
}

/*
=====================================
CSV Report
=====================================
*/

void ReportGenerator::generateCSVReport(
    const string& filename
)
{
    profiler_export_csv(
        filename.c_str()
    );

    cout
        << "CSV report generated: "
        << filename
        << endl;
}

/*
=====================================
Summary Statistics
=====================================
*/

void ReportGenerator::generateSummary()
{
    cout << "\n";
    cout << "=====================================\n";
    cout << "PROFILING SUMMARY\n";
    cout << "=====================================\n";

    cout
        << "Functions Profiled: "
        << profileCount
        << endl;

    int totalCalls = 0;
    double totalTime = 0.0;

    for(int i = 0; i < profileCount; i++)
    {
        totalCalls +=
            profileTable[i].callCount;

        totalTime +=
            profileTable[i].totalExecutionTime;
    }

    cout
        << "Total Calls: "
        << totalCalls
        << endl;

    cout
        << "Total Time (ms): "
        << totalTime * 1000.0
        << endl;

    cout << "=====================================\n";
}