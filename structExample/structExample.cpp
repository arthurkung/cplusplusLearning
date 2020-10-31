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

// Nested struct example
struct Company
{
    Employee CEO; // Employee is a struct within the Company struct
    int numberOfEmployees;
};

Company createCompanyEntry(Employee CEO, int numberOfEmployees)
{
    return { CEO, numberOfEmployees };// type company is already specified
}
int main()
{
    Employee joe{ 
        14,     //ID
        32,     //age
        24.15   //wage
    };
    Employee frank{ 
        15,     //ID
        28,     //age
        18.27   //wage
    };

    // Print Joe's information
    std::cout << "Information of employee Joe:\n";
    printEmployeeInformation(joe);

    // Three methods of creating a company entry
    Company myCompany1{ { 1, 42, 60000.0 }, 5 };
    Company myCompany2{ joe, 12 };
    Company myCompany3{ };
    myCompany3 = createCompanyEntry(frank, 120);

    //print the information of CEO of mycompany3
    std::cout << "Information of CEO of mycompany3:\n";
    printEmployeeInformation(myCompany3.CEO);
    return 0;
}
