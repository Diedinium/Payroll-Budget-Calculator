#include <iostream>
#include <string>
#include <vector>
#include "Staff.h"
#include "StaffManager.h"
#include "InputValidator.h"
#include "Menu.h"

int main()
{
    StaffManager staffManager;

    staffManager.AddContractStaff(ContractStaff("Tobi", "Biddle", "Analyst", "IT", 15.25, 17, 25));

    staffManager.AddSalariedStaff(SalariedStaff("Luke", "Boyle", "Junior Developer", "IT", 20252, false));
    staffManager.AddSalariedStaff(SalariedStaff("Jake", "Hall", "Senior Developer", "IT", 35050, true));

    ContractStaff* cont = staffManager.GetContractStaff("Tobi Biddle");
    SalariedStaff* sal = staffManager.GetSalariedStaff("Luke Boyle");
    SalariedStaff* sal1 = staffManager.GetSalariedStaff("Jake Hall");

    std::cout << "Name: " << sal->GetFullName() <<
        "\nRole: " << sal->GetDepartment() << ", " << sal->GetJobRole() <<
        "\nSalary: " << sal->GetSalary() <<
        "\nSenior? " << (sal->GetSenior() == true ? "Yes" : "No")
        << "\n\n";

    std::cout << "Name: " << sal1->GetFullName() <<
        "\nRole: " << sal1->GetDepartment() << ", " << sal1->GetJobRole() <<
        "\nSalary: " << sal1->GetSalary() <<
        "\nSenior? " << (sal1->GetSenior() == true ? "Yes" : "No")
        << "\n\n";

    std::cout << "Name: " << cont->GetFullName() <<
        "\nRole: " << cont->GetDepartment() << ", " << cont->GetJobRole() <<
        "\nWage: " << cont->GetWage() <<
        "\nContract Cost? " << cont->GetContractCost()
        << "\n";

    std::cout << "\nInput an int: ";
    int testInput = InputValidator::ValidateInt();
    std::cout << "\nYou input " << testInput << "\n";

    std::cout << "\nInput an double: ";
    double testInput1 = InputValidator::ValidateDouble();
    std::cout << "\nYou input " << testInput1 << "\n";
}

