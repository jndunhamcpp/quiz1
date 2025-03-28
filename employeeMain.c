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
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double numberToFind);

    int id_search = 1045;
    char name_search[20] = "Tammy Franklin";
    char phone_search[20] = "909-555-2134";
    double salary_search = 6.34;

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;
    PtrToEmployee matchPtr; //Declaration

    // Search for name
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, id_search);
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

    //search by phone number
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, phone_search);
    if (matchPtr != NULL)
    {
        printf("Phone number %s is in record %d\n", phone_search, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Phone number is NOT found in the record\n");
    }

    // Search by salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary_search);
    if (matchPtr != NULL)
    {
        printf("Salary %.2f is in record %ld\n", salary_search, matchPtr - EmployeeTable);
    }
    else
    {
        printf("Salary is NOT found in the record\n");
    }
}