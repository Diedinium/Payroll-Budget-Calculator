#pragma once

#include "Menu.h"
#include "Utilities.h"
#include "InputValidator.h"

void MenuContainer::Execute()
{
	std::cout << _strText << "\n";
	util::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [](unsigned index, std::unique_ptr<MenuItem> const& item) {
		std::cout << "\t" << index << " - " << item->ItemText() << "\n";
		});
	std::cout << "\nChoice: ";
	int iChoice = InputValidator::ValidateInt();
	if ((int)_vecMenuItems.size() > iChoice && iChoice >= 0) {
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
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuViewStaff("View staff", _ptrStaffManager)));
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
	util::Pause();*/
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
	util::Pause();
};

void MenuSaveLoad::Execute() {
	system("cls");
	std::cout << "Save or Load menu\nThis is a placeholder menu option...\n";
	util::Pause();
};

void MenuViewStaff::Execute() {
	MenuContainer objMenuContainer = MenuContainer("");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to staff management menu", &objMenuContainer)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuAddStaffMember("Add staff member", _ptrStaffManager)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuRemoveStaffMember("Remove staff member", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");

		std::vector<SalariedStaff>* ptrVecSalariedStaff = _ptrStaffManager->GetPtrSalariedStaff();
		std::vector<ContractStaff>* ptrVecContractStaff = _ptrStaffManager->GetPtrContractStaff();

		std::cout << "View staff\n\n";

		if (ptrVecSalariedStaff->size() < 1 && ptrVecContractStaff->size() < 1) {
			std::cout << "There are not currently any staff in the system. Either add some or import them to use this menu.\n";
			objMenuContainer.SetExitMenu(true);
			util::Pause();
			continue;
		}

		if (ptrVecSalariedStaff->size() > 0) {
			std::cout << "Salaried Staff\n";
			std::cout << "Count: " << ptrVecSalariedStaff->size() << "\n";
			std::cout << "-------------------------------------------------------------------------------------------------------------\n";
			std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << "Job Role" << std::setw(15) << "Department" << std::setw(12) << "Salary" << std::setw(5) << "Senior?" << "\n";
			std::cout << "-------------------------------------------------------------------------------------------------------------\n";
			util::for_each_iterator(ptrVecSalariedStaff->begin(), ptrVecSalariedStaff->end(), 0, [](int index, SalariedStaff& item) {
				std::cout.precision(2);
				std::cout
					<< std::fixed << std::setw(4) << std::left << index
					<< std::fixed << std::setw(15) << std::left << item.GetFirstName()
					<< std::fixed << std::setw(15) << std::left << item.GetLastName()
					<< std::fixed << std::setw(25) << std::left << item.GetJobRole()
					<< std::fixed << std::setw(15) << std::left << item.GetDepartment()
					<< std::fixed << std::setw(12) << std::left << item.GetSalary()
					<< std::fixed << std::setw(10) << std::left << (item.GetSenior() == true ? "Yes" : "No") << "\n";
			});
			std::cout << "\n";

			if (_ptrStaffManager->CountSeniorStaff() < 3) std::cout << "Warning: You currently have than 3 senior staff members. A normal project should contain at least 3 senior staff.\n";
			if (_ptrStaffManager->CountStandardStaff() < 5) std::cout << "Warning: You currently have less than 5 salaried staff members. A normal project should contain at least 5 salaried staff.\n";

			std::cout << "\n";
		}
		else {
			std::cout << "There are not currently any salaried staff to list.\nPlease note a 'normal' project usually has 3 senior staff and 5 salaried staff.\n";
		}

		if (ptrVecContractStaff->size() > 0) {
			std::cout << "Contract Staff\n";
			std::cout << "Count: " << ptrVecContractStaff->size() << "\n";
			std::cout << "----------------------------------------------------------------------------------------------------------\n";
			std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << std::left << "Job Role" << std::setw(15) << std::left << "Department" << std::setw(8) << std::left << "Wage" << std::setw(12) << std::left << "Hours p/w" << std::setw(10) << std::left << "Contracted" << "\n";
			std::cout << "----------------------------------------------------------------------------------------------------------\n";
			util::for_each_iterator(ptrVecContractStaff->begin(), ptrVecContractStaff->end(), 0, [](int index, ContractStaff& item) {
				std::cout.precision(2);
				std::cout
					<< std::fixed << std::setw(4) << std::left << index
					<< std::fixed << std::setw(15) << std::left << item.GetFirstName()
					<< std::fixed << std::setw(15) << std::left << item.GetLastName()
					<< std::fixed << std::setw(25) << std::left << item.GetJobRole()
					<< std::fixed << std::setw(15) << std::left << item.GetDepartment()
					<< std::fixed << std::setw(8) << std::left << item.GetWage()
					<< std::fixed << std::setw(12) << std::left << item.GetWeeklyHours()
					<< std::fixed << std::setw(10) << std::left << item.GetWeeksFormatted() << "\n";
				});
			std::cout << "\n";

			if (ptrVecContractStaff->size() < 5) std::cout << "Warning: You currently have than 5 contracted staff. A normal project should contain at least 5 contracted staff.\n";
		}
		else {
			std::cout << "There are not currently any contract staff to list.\nPlease note a 'normal' project usually has 5 contract staff.\n";
		}

		objMenuContainer.Execute();
	}
}

void SubMenuAddStaffMember::Execute() {
	MenuContainer objMenuContainer = MenuContainer("Choose Staff type to add.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to previous", &objMenuContainer)));
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
	util::Pause();
};

void SubMenuAddContractStaff::Execute() {
	system("cls");
	std::cout << "Add Contract Staf menu\nThis is a placeholder menu option...\n";
	util::Pause();
};

void SubMenuRemoveStaffMember::Execute() {
	
	MenuContainer objMenuContainer = MenuContainer("Choose Staff type to add.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to previous", &objMenuContainer)));
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
	util::Pause();
};

void SubMenuRemoveContractStaff::Execute() {
	system("cls");
	std::cout << "Remove Contract staff menu\nThis is a placeholder menu option...\n";
	util::Pause();
};