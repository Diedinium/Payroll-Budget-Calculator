#include <iostream>
#include <string>
#include <vector>
#include "Staff.h"
#include "StaffManager.h"
#include "InputValidator.h"
#include "Menu.h"
#include "FileManager.h"

int main()
{
    StaffManager staffManager;
    BudgetCalculator budgetCalculator = BudgetCalculator(&staffManager);
    FileManager fileManager = FileManager(&budgetCalculator);
    fileManager.EnsureDirectoriesExist();

    // NOTE TO TESTERS: Uncomment this code to quickly add an collection of staff if you don't want to waste lots of time adding staff members.
    // Any references to famous characters are completely coincidental ;)

    /*staffManager.AddContractStaff(ContractStaff("Obi-wan", "Kenobi", "Jedi Master", "Jedi Order", 28.50, 5, 29));
    staffManager.AddContractStaff(ContractStaff("Anakin", "Skywalker", "Jedi Knight", "Jedi Order", 10.50, 10, 22));
    staffManager.AddContractStaff(ContractStaff("Ben", "Kenobi", "Jedi Master", "Jedi Order", 23, 17, 5));
    staffManager.AddContractStaff(ContractStaff("Jango", "Fett", "Bounty Hunter", "Himself", 18.25, 17, 15));
    staffManager.AddContractStaff(ContractStaff("Boba", "Fett", "Bounty Hunter", "Himself", 25.25, 17, 30));

    staffManager.AddSalariedStaff(SalariedStaff("Mace", "Windu", "Jedi Master", "Jedi Order", 20252, false));
    staffManager.AddSalariedStaff(SalariedStaff("Ahsoka", "tano", "Jedi Knight", "Jedi Order", 42425.24, false));
    staffManager.AddSalariedStaff(SalariedStaff("Viceroy", "Gunray", "Viceroy", "Trade Federation", 54000.25, false));
    staffManager.AddSalariedStaff(SalariedStaff("Darth", "Maul", "Sith", "Sith Order", 35050, false));
    staffManager.AddSalariedStaff(SalariedStaff("Darth", "Sidious", "Sith", "Sith Order", 52452.24, false));

    staffManager.AddSalariedStaff(SalariedStaff("Jabba", "The Hut", "Crime lord", "Hutt gang", 89224.42, true));
    staffManager.AddSalariedStaff(SalariedStaff("Luke", "Skywalker", "Jedi Knight", "Jedi Order", 80824.24, true));
    staffManager.AddSalariedStaff(SalariedStaff("Leia", "Organa", "Princess", "Rebel Alliance", 252452, true));*/

    MenuContainer menuContainer = MenuContainer("Welcome to the payroll project budget calculator.\nPlease choose your option below.\n");
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Exit application", &menuContainer)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuStaffManagement("Manage Staff", &staffManager)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuCalculateBudget("Calculate Budget or view reports", &budgetCalculator, &fileManager)));
    menuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuSaveLoad("Save or load data", &staffManager, &fileManager)));

    while (!menuContainer.GetExitMenu()) {
        system("cls");
        menuContainer.Execute();
    }  
}

