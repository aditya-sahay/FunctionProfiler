#ifndef REPORT_H
#define REPORT_H

#include <string>

using namespace std;

/*
=====================================
Profiling Report Generator
=====================================
*/

class ReportGenerator
{
public:

    /*
        Console Report
    */
    static void generateConsoleReport();

    /*
        CSV Export
    */
    static void generateCSVReport(
        const string& filename
    );

    /*
        Summary Statistics
    */
    static void generateSummary();
};

#endif