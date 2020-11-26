#pragma once

#include "Menu.h"
#include "Utilities.h"
#include "InputValidator.h"

void MenuContainer::Execute()
{
	std::cout << _strText << "\n";
	util::for_each_iterator(_vecMenuItems.begin(), _vecMenuItems.end(), 0, [](int index, std::unique_ptr<MenuItem> const& item) {
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
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuUpdateStaff("Update staff member", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
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
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuUpdateStaff("Update staff member", _ptrStaffManager)));

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
			util::OutputSalariedStaffHeader();
			util::OutputSalariedStaff(ptrVecSalariedStaff);
			std::cout << "\n";

			if (_ptrStaffManager->CountSeniorStaff() < 3) std::cout << "Warning: You currently have less than 3 senior staff members. A normal project should contain at least 3 senior staff.\n";
			if (_ptrStaffManager->CountStandardStaff() < 5) std::cout << "Warning: You currently have less than 5 salaried staff members. A normal project should contain at least 5 salaried staff.\n";

			std::cout << "\n";
		}
		else {
			std::cout << "There are not currently any salaried staff to list.\nPlease note a 'normal' project usually has 3 senior staff and 5 salaried staff.\n";
		}

		if (ptrVecContractStaff->size() > 0) {
			std::cout << "Contract Staff\n";
			std::cout << "Count: " << ptrVecContractStaff->size() << "\n";
			util::OutputContractStaffHeader();
			util::OutputContractStaff(ptrVecContractStaff);
			std::cout << "\n";

			if (ptrVecContractStaff->size() < 5) std::cout << "Warning: You currently have less than 5 contracted staff. A normal project should contain at least 5 contracted staff.\n";
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
	std::cout << "Add Salaried Staff\n";

	std::string strFirstName, strLastName, strJobRole, strDepartment;
	int iSeniorStatus;
	SalariedStaff objSalariedStaff;
	
	std::cout << "First Name: ";
	strFirstName = InputValidator::ValidateString(15);
	std::cout << "Last Name: ";
	strLastName = InputValidator::ValidateString(15);
	std::cout << "Job Role: ";
	strJobRole = InputValidator::ValidateString(25);
	std::cout << "Department: ";
	strDepartment = InputValidator::ValidateString(20);

	objSalariedStaff.UpdateDetails(strFirstName, strLastName, strJobRole, strDepartment);

	std::cout << "Salary: ";
	objSalariedStaff.SetSalary(InputValidator::ValidateDouble());
	std::cout << "Senior (1 for senior, or 0 otherwise): ";
	iSeniorStatus = InputValidator::ValidateInt();

	if (iSeniorStatus == 1) {
		objSalariedStaff.SetSenior(true);
	}

	try {
		_ptrStaffManager->AddSalariedStaff(objSalariedStaff);
		std::cout << "\nStaff member " << objSalariedStaff.GetFullName() << " added.\n\n";
		util::Pause();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << "\n\n";
	}
};

void SubMenuAddContractStaff::Execute() {
	system("cls");
	std::cout << "Add Salaried Staff\n";

	std::string strFirstName, strLastName, strJobRole, strDepartment;
	ContractStaff objContractStaff;

	std::cout << "First Name: ";
	strFirstName = InputValidator::ValidateString(15);
	std::cout << "Last Name: ";
	strLastName = InputValidator::ValidateString(15);
	std::cout << "Job Role: ";
	strJobRole = InputValidator::ValidateString(25);
	std::cout << "Department: ";
	strDepartment = InputValidator::ValidateString(20);

	objContractStaff.UpdateDetails(strFirstName, strLastName, strJobRole, strDepartment);

	std::cout << "Wage (per hour): ";
	objContractStaff.SetWage(InputValidator::ValidateDouble());
	std::cout << "Weekly hours (max 20h): ";
	objContractStaff.SetWeeklyHours(InputValidator::ValidateDouble(20));
	std::cout << "Contracted Weeks (max 30 weeks): ";
	objContractStaff.SetWeeks(InputValidator::ValidateInt(30));

	try {
		_ptrStaffManager->AddContractStaff(objContractStaff);
		std::cout << "\nContract staff member " << objContractStaff.GetFullName() << " added.\n\n";
		util::Pause();
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << "\n\n";
		util::Pause();
	}
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
	bool boolExitWhile = false;
	do {
		system("cls");
		std::cout << "Remove Salaried staff menu\n\n";

		std::vector<SalariedStaff>* ptrVecSalariedStaff = _ptrStaffManager->GetPtrSalariedStaff();

		if (ptrVecSalariedStaff->size() < 1) {
			std::cout << "No salaried staff found.\n";
			boolExitWhile = true;
			util::Pause();
		} 
		else {
			util::OutputSalariedStaffHeader();
			util::OutputSalariedStaff(ptrVecSalariedStaff);
			std::cout << "\n";

			std::cout << "Note: Enter 0 to exit.\n";
			std::cout << "Full name of salaried staff to remove: ";
			std::string strFullName = InputValidator::ValidateString();

			if (strFullName == "0") {
				boolExitWhile = true;
			}
			else {
				try {
					_ptrStaffManager->RemoveSalariedStaff(strFullName);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << "\n";
					util::Pause();
				}
			}
		}
	} while (!boolExitWhile);
};

void SubMenuRemoveContractStaff::Execute() {
	bool boolExitWhile = false;
	do {
		system("cls");
		std::cout << "Remove contract staff menu\n\n";

		std::vector<ContractStaff>* ptrVecContractStaff = _ptrStaffManager->GetPtrContractStaff();

		if (ptrVecContractStaff->size() < 1) {
			std::cout << "No contract staff found.\n";
			boolExitWhile = true;
			util::Pause();
		}
		else {
			util::OutputContractStaffHeader();
			util::OutputContractStaff(ptrVecContractStaff);
			std::cout << "\n";

			std::cout << "Note: Enter 0 to exit.\n";
			std::cout << "Full name of contract staff to remove: ";
			std::string strFullName = InputValidator::ValidateString();

			if (strFullName == "0") {
				boolExitWhile = true;
			}
			else {
				try {
					_ptrStaffManager->RemoveContractStaff(strFullName);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << "\n";
					util::Pause();
				}
			}
		}
	} while (!boolExitWhile);
};

void MenuUpdateStaff::Execute() {
	MenuContainer objMenuContainer = MenuContainer("Choose Staff type to update.\n");
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Return to previous", &objMenuContainer)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuUpdateSalariedStaff("Update salaried staff members (including senior)", _ptrStaffManager)));
	objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new SubMenuUpdateContractStaff("Update contract staff members", _ptrStaffManager)));

	while (!objMenuContainer.GetExitMenu()) {
		system("cls");
		objMenuContainer.Execute();
	}
}

void SubMenuUpdateSalariedStaff::Execute() {
	bool boolExitWhile = false;
	do {
		system("cls");
		std::cout << "Current salaried staff\n\n";
		
		std::vector<SalariedStaff>* ptrVecSalariedStaff = _ptrStaffManager->GetPtrSalariedStaff();

		if (ptrVecSalariedStaff->size() < 1) {
			std::cout << "There are not currently any salaried staff in the system. To update staff details, you first must add at least one staff member\n";
			boolExitWhile = true;
			util::Pause();
			continue;
		}

		util::OutputSalariedStaffHeader();
		util::OutputSalariedStaff(ptrVecSalariedStaff);

		std::cout << "\nPlease enter the full name of the staff member you would like to update.\nNote: Enter 0 to exit this update screen and return.\n";
		std::cout << "Full name: ";
		std::string strFullName = InputValidator::ValidateString();

		if (strFullName == "0") {
			boolExitWhile = true;
			continue;
		}

		SalariedStaff* ptrSalariedStaff = _ptrStaffManager->GetSalariedStaff(strFullName);

		while (ptrSalariedStaff == NULL) {
			std::cout << "No staff member with this name found, please try again (enter 0 to cancel).\n";
			std::cout << "Full name: ";
			strFullName = InputValidator::ValidateString();
			if (strFullName == "0") {
				boolExitWhile = true;
				ptrSalariedStaff = new SalariedStaff();
				continue;
			}
			ptrSalariedStaff = _ptrStaffManager->GetSalariedStaff(strFullName);
		}

		MenuContainer objMenuContainer = MenuContainer("Choose action.\n");
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new MenuExit("Cancel", &objMenuContainer)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update first name", ptrSalariedStaff)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update second name", ptrSalariedStaff)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update Job Title", ptrSalariedStaff)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update Department", ptrSalariedStaff)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update Salary", ptrSalariedStaff)));
		objMenuContainer.AddMenuItem(std::unique_ptr<MenuItem>(new ActionMenuUpdateSalariedFirstName("Update Senior status", ptrSalariedStaff)));

		while (!objMenuContainer.GetExitMenu()) {
			std::cout << "\nUpdating: " << ptrSalariedStaff->GetFullName() << "\n";
			objMenuContainer.Execute();
		}
	} while (!boolExitWhile);
}

void SubMenuUpdateContractStaff::Execute() {
	std::cout << "Placeholder menu...\n";
	util::Pause();
}

void ActionMenuUpdateSalariedFirstName::Execute() {
	std::cout << "\nEnter new first name: ";
	std::string strFirstName = InputValidator::ValidateString(15);

	_ptrSalariedStaff->SetFirstName(strFirstName);
	std::cout << "First name updated\n";
}