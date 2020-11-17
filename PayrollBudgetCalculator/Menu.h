#pragma once

#include <iostream>
#include <string>
#include "StaffManager.h"
#include "InputValidator.h"

#ifndef MENU_H
#define MENU_H
class Menu {
public:
	int MainMenu(StaffManager* staffManager);
	int ManageStaffMenu(StaffManager* staffManager);
	int CalculateCostsMenu(StaffManager* staffManager);
	int SaveLoadMenu(StaffManager* staffManager);
	int ExitMenu(StaffManager* staffManager);
};
#endif // !MENU_H
