#pragma once

#include "Menu.h"
#include "Templates.h"
#include "InputValidator.h"

void MenuContainer::Execute()
{
	std::cout << _strText << "\n";
	tmplt::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [](unsigned index, std::unique_ptr<MenuItem> const& item) {
		std::cout << "\t" << index << " - " << item->ItemText() << "\n";
		});
	std::cout << "\nChoice: ";
	int iChoice = InputValidator::ValidateInt();
	if (_vecMenuItems.size() > iChoice && iChoice >= 0) {
		_vecMenuItems[iChoice]->Execute();
	}
	else {
		std::cout << "Not a valid option, please try again.\n";
	}
};

void MenuContainer::AddMenuItem(std::unique_ptr<MenuItem> item) {
	_vecMenuItems.push_back(std::move(item));
};

GeneralMenuItem::GeneralMenuItem(std::string output, StaffManager* staffManager)
{
	_output = output;
	_ptrStaffManager = staffManager;
};

void MenuStaffManagement::Execute() {
	MenuContainer objMenuContainer = MenuContainer("Staff management menu.\nChoose one of the below options.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to menu", &objMenuContainer)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuAddStaffMember("Add staff member", _ptrStaffManager)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuRemoveStaffMember("Remove staff member", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}

	/*std::string strNameInput = InputValidator::ValidateString();
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
	tmplt::Pause();*/
};

MenuExit::MenuExit(std::string output, MenuContainer* menuContainer) : GeneralMenuItem(output, NULL) {
	_ptrMenuContainer = menuContainer;
};

void MenuExit::Execute() {
	_ptrMenuContainer->SetExitMenu(true);
};

void MenuCalculateBudget::Execute() {
	system("cls");
	std::cout << "Calculate budget or view reports menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};

void MenuSaveLoad::Execute() {
	system("cls");
	std::cout << "Save or Load menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};

void SubMenuAddStaffMember::Execute() {
	MenuContainer objMenuContainer = MenuContainer("Choose Staff type to add.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to staff management menu", &objMenuContainer)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuAddSalariedStaff("Add salaried staff member (including senior)", _ptrStaffManager)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuAddContractStaff("Add contract staff member", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
};

void SubMenuAddSalariedStaff::Execute() {
	system("cls");
	std::cout << "Add Salaried Staff menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};

void SubMenuAddContractStaff::Execute() {
	system("cls");
	std::cout << "Add Contract Staf menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};

void SubMenuRemoveStaffMember::Execute() {
	
	MenuContainer objMenuContainer = MenuContainer("Choose Staff type to add.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to staff management menu", &objMenuContainer)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuRemoveSalariedStaffMember("Remove salaried staff member (including senior)", _ptrStaffManager)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuRemoveContractStaff("Remove contract staff member", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
};

void SubMenuRemoveSalariedStaffMember::Execute() {
	system("cls");
	std::cout << "Remove Salaried staff menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};

void SubMenuRemoveContractStaff::Execute() {
	system("cls");
	std::cout << "Remove Contract staff menu\nThis is a placeholder menu option...\n";
	tmplt::Pause();
};