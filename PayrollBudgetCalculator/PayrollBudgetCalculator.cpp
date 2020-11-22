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

    MenuContainer menuContainer = MenuContainer("Welcome to the payroll project budget calculator.\nPlease choose your option below.\n");
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Exit application", &menuContainer)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuStaffManagement("Manage Staff", &staffManager)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuCalculateBudget("Calculate Budget or view reports", &staffManager)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuSaveLoad("Save or load data", &staffManager)));

    while (!menuContainer.GetExitMenu()) {
        system("cls");
        menuContainer.Execute();
    }  
}

