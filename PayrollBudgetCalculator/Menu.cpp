#pragma once

#include "Menu.h"

int Menu::MainMenu(StaffManager* staffManager) {
	system("cls");
	std::cout << "Welcome to the Payroll Budget Calculator, please enter your choice.\n";
	std::cout << "1: Manage Staff\n";
	std::cout << "2: Calculate Costs\n";
	std::cout << "3: Save/Load\n";
	std::cout << "9: Exit\n";
	std::cout << "Choice: ";
	int choiceNum = InputValidator::ValidateInt();

	switch (choiceNum) {
	case 1:
		ManageStaffMenu(staffManager);
		break;
	case 2:
		CalculateCostsMenu(staffManager);
		break;
	case 3:
		SaveLoadMenu(staffManager);
		break;
	case 9:
		ExitMenu(staffManager);
	}
}

int Menu::ManageStaffMenu(StaffManager* staffManager) {
	std::cout << "Reached staff menu\n";
}

int Menu::CalculateCostsMenu(StaffManager* staffManager) {
	std::cout << "Reached staff menu\n";
}

int Menu::SaveLoadMenu(StaffManager* staffManager) {
	std::cout << "Reached staff menu\n";
}

int Menu::ExitMenu(StaffManager* staffManager) {
	std::cout << "Reached staff menu\n";
}