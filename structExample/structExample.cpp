#include <iostream>

struct Employee
{
    short id;
    int age;
    double wage;
};


void printEmployeeInformation(Employee employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe{ 14, 32, 24.15 };
    Employee frank{ 15, 28, 18.27 };

    // Print Joe's information
    printEmployeeInformation(joe);

    // Nested struct example
    struct Company
    {
        Employee CEO; // Employee is a struct within the Company struct
        int numberOfEmployees;
    };

    Company myCompany{ { 1, 42, 60000.0 }, 5 };
    return 0;
}
