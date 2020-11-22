#pragma once

#include "Menu.h"
#include "Templates.h"
#include "InputValidator.h"

void MenuContainer::Execute()
{
	std::cout << _strText << "\n";
	tmplt::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [](unsigned index, std::unique_ptr<MenuItem> const& item) {
		std::cout << "\t" <<index << " - " << item->ItemText() << "\n";
	});
	std::cout << "\nChoice: ";
	int iChoice = InputValidator::ValidateInt();
	if (_vecMenuItems.size() > iChoice && iChoice >= 0) { 
		_vecMenuItems[iChoice]->Execute();
	}
	else {
		std::cout << "Not a valid option, please try again.\n";
	}
}

void MenuContainer::AddMenuItem(std::unique_ptr<MenuItem> item) {
	_vecMenuItems.push_back(std::move(item));
}

GeneralMenuItem::GeneralMenuItem(std::string output, StaffManager* staffManager)
{
	_output = output;
	_ptrStaffManager = staffManager;
}

MenuStaffManagement::MenuStaffManagement(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};

void MenuStaffManagement::Execute() {
	system("cls");
	std::cout << "Entered staff management menu...\n";
	std::cout << "Lets demo fetching staff details, enter a name: ";
	std::string strNameInput = InputValidator::ValidateString();
	ContractStaff* cont = _ptrStaffManager->GetContractStaff(strNameInput);
	SalariedStaff* sal = _ptrStaffManager->GetSalariedStaff(strNameInput);

	if (cont == NULL && sal == NULL) {
		std::cout << "No staff with these details found in contracted or salaried staff";
		return;
	}
	
	if (cont != NULL) {
		std::cout << "Contract staff member found: \n";
		std::cout << "Name: " << cont->GetFullName() <<
			"\nRole: " << cont->GetDepartment() << ", " << cont->GetJobRole() <<
			"\nWage: " << cont->GetWage() <<
			"\nContract Cost? " << cont->GetContractCost()
			<< "\n";
	}

	if (sal != NULL) {
		std::cout << "Salaried staff member found: \n";
		std::cout << "Name: " << sal->GetFullName() <<
			"\nRole: " << sal->GetDepartment() << ", " << sal->GetJobRole() <<
			"\nSalary: " << sal->GetSalary() <<
			"\nSenior? " << (sal->GetSenior() == true ? "Yes" : "No")
			<< "\n\n";
	}
	tmplt::Pause();
}

MenuExit::MenuExit(std::string output, MenuContainer* menuContainer) : GeneralMenuItem(output, NULL) {
	_ptrMenuContainer = menuContainer;
};

void MenuExit::Execute() {
	_ptrMenuContainer->SetExitMenu(true);
}

void MenuCalculateBudget::Execute() {
	system("cls");
	std::cout << "Calculate budget or view reports menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
}

void MenuSaveLoad::Execute() {
	system("cls");
	std::cout << "Save or Load menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
}
