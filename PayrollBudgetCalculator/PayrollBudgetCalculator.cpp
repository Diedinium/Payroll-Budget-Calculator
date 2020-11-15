#include <iostream>
#include <string>
#include "Staff.h"
#include "StaffManager.h"

int main()
{
    SalariedStaff sal = SalariedStaff("Jake", "Hall", "Senior Developer", "IT", 35050, true);
    SalariedStaff sal1 = SalariedStaff("Luke", "Boyle", "Junior Developer", "IT", 20252, false);
    ContractStaff cont = ContractStaff("Tobi", "Biddle", "Analyst", "IT", 15.25, 17, 25);

    std::cout << "Name: " << sal.GetFullName() <<
        "\nRole: " << sal.GetDepartment() << ", " << sal.GetJobRole() <<
        "\nSalary: " << sal.GetSalary() <<
        "\nSenior? " << (sal.GetSenior() == true ? "Yes" : "No")
        << "\n\n";

    std::cout << "Name: " << sal1.GetFullName() <<
        "\nRole: " << sal1.GetDepartment() << ", " << sal1.GetJobRole() <<
        "\nSalary: " << sal1.GetSalary() <<
        "\nSenior? " << (sal1.GetSenior() == true ? "Yes" : "No")
        << "\n\n";

    std::cout << "Name: " << cont.GetFullName() <<
        "\nRole: " << cont.GetDepartment() << ", " << cont.GetJobRole() <<
        "\nWage: " << cont.GetWage() <<
        "\nContract Cost? " << cont.GetContractCost()
        << "\n";
}

