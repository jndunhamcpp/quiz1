//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);

    int id_search = 1045;
    char name_search[20] = "Tammy Franklin";

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
    PtrToEmployee matchPtr; //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, id_search);

    //Example not found
    if (matchPtr != NULL)
    {
        printf("\nEmployee ID %d is in record %ld\n", id_search, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee ID is NOT found in the record\n");
    }

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, name_search);
    if (matchPtr != NULL)
    {
        printf("Employee %s is in record %d\n", name_search, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Employee Tony Bobcat is NOT found in the record\n");
    }
}