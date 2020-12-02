#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "StaffManager.h"
#include "InputValidator.h"
#include "BudgetCalculator.h"
#include "FileManager.h"

#ifndef MENU_H
#define MENU_H
// Making use of the adapter design pattern here 

/// <summary>
/// Abstract menu item class so that the "adapter" design pattern can be used. 
/// All classes that ultimately inherit from MenuItem can have the Execute function called, which makes polymorphism possible.
/// </summary>
class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string ItemText() const = 0;
    virtual void Execute() = 0;
};

/// <summary>
/// Stores a list of menu item pointers (as unique pointers), when execute is called it iterates through this and calls the execute for each menu item.
/// This allows menus to be dynamically created, and allows menus to be within menus (as the Execute function of a MenuItem can just instantiate a new menu container).
/// </summary>
class MenuContainer {
private:
    std::string _strText;
    std::vector<std::unique_ptr<MenuItem>> _vecMenuItems;
    bool _boolExitMenu;
public:
    MenuContainer(std::string const& text) : _strText(text), _vecMenuItems() { _boolExitMenu = false; }
    void AddMenuItem(std::unique_ptr<MenuItem> item);
    void Execute();
    bool GetExitMenu() { return _boolExitMenu; }
    void SetExitMenu(bool exitMenu) { _boolExitMenu = exitMenu; }
};

/// <summary>
/// Each menu item will need a process to handle the output (ItemText), so a general menu item is created to implement this - most other menu items then inherit this class 
/// and use it's base constructor.
/// </summary>
class GeneralMenuItem : public MenuItem {
private:
    std::string _output;
protected:
    StaffManager* _ptrStaffManager;
public:
    GeneralMenuItem(std::string output, StaffManager* staffManager);
    std::string ItemText() const { return _output; }
};

class MenuStaffManagement : public GeneralMenuItem {
public:
    MenuStaffManagement(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class MenuExit : public GeneralMenuItem {
private:
    MenuContainer* _ptrMenuContainer;
public:
    MenuExit(std::string output, MenuContainer* menuContainer);
    void Execute();
};

class MenuCalculateBudget : public GeneralMenuItem {
    BudgetCalculator* _ptrBudgetCalculator;
    FileManager* _ptrFileManager;
public:
    MenuCalculateBudget(std::string output, BudgetCalculator* budgetCalculator, FileManager* fileManager);
    void Execute();
};

class MenuSaveLoadBase : public GeneralMenuItem {
protected:
    FileManager* _ptrFileManager;
public:
    MenuSaveLoadBase(std::string output, StaffManager* staffManager, FileManager* fileManager) : GeneralMenuItem(output, staffManager) { _ptrFileManager = fileManager; }
};

class MenuSaveLoad : public MenuSaveLoadBase {
public:
    MenuSaveLoad(std::string output, StaffManager* staffManager, FileManager* fileManager) : MenuSaveLoadBase(output, staffManager, fileManager) {};
    void Execute();
};

class SubMenuLoadProject : public MenuSaveLoadBase {
public:
    SubMenuLoadProject(std::string output, StaffManager* staffManager, FileManager* fileManager) : MenuSaveLoadBase(output, staffManager, fileManager) {};
    void Execute();
};

class SubMenuSaveProject : public MenuSaveLoadBase {
public:
    SubMenuSaveProject(std::string output, StaffManager* staffManager, FileManager* fileManager) : MenuSaveLoadBase(output, staffManager, fileManager) {};
    void Execute();
};

class MenuViewStaff : public GeneralMenuItem {
public:
    MenuViewStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuAddStaffMember : public GeneralMenuItem {
public:
    SubMenuAddStaffMember(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuAddSalariedStaff : public GeneralMenuItem {
public:
    SubMenuAddSalariedStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuAddContractStaff : public GeneralMenuItem {
public:
    SubMenuAddContractStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuRemoveStaffMember : public GeneralMenuItem {
public:
    SubMenuRemoveStaffMember(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuRemoveSalariedStaffMember : public GeneralMenuItem {
public:
    SubMenuRemoveSalariedStaffMember(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuRemoveContractStaff : public GeneralMenuItem {
public:
    SubMenuRemoveContractStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class MenuUpdateStaff : public GeneralMenuItem {
public:
    MenuUpdateStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class SubMenuUpdateSalariedStaff : public GeneralMenuItem {
private:
    std::vector<SalariedStaff>* _ptrVecSalariedStaff;
public:
    SubMenuUpdateSalariedStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) { _ptrVecSalariedStaff = _ptrStaffManager->GetPtrSalariedStaff(); }
    void Execute();
};

class SubMenuUpdateContractStaff : public GeneralMenuItem {
private:
    std::vector<ContractStaff>* _ptrVecContractStaff;
public:
    SubMenuUpdateContractStaff(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) { _ptrVecContractStaff = _ptrStaffManager->GetPtrContractStaff(); }
    void Execute();
};

class ActionMenuStaffBase : public GeneralMenuItem {
protected:
    Staff* _ptrStaff;
public:
    ActionMenuStaffBase(std::string output, Staff* staff) : GeneralMenuItem(output, NULL) { _ptrStaff = staff; }
};

// Below 4 menus use the staff pointer, meaning they can handle updating either Salaried or Contract staff details, for the shared properties/methods these classes have
class ActionMenuUpdateStaffFirstName : public ActionMenuStaffBase {
public: 
    ActionMenuUpdateStaffFirstName(std::string output, Staff* staff) : ActionMenuStaffBase(output, staff) {}
    void Execute();
};

class ActionMenuUpdateStaffLastName : public ActionMenuStaffBase {
public:
    ActionMenuUpdateStaffLastName(std::string output, Staff* staff) : ActionMenuStaffBase(output, staff) {}
    void Execute();
};

class ActionMenuUpdateStaffJobRole : public ActionMenuStaffBase {
public:
    ActionMenuUpdateStaffJobRole(std::string output, Staff* staff) : ActionMenuStaffBase(output, staff) {}
    void Execute();
};

class ActionMenuUpdateStaffDepartment : public ActionMenuStaffBase {
public:
    ActionMenuUpdateStaffDepartment(std::string output, Staff* staff) : ActionMenuStaffBase(output, staff) {}
    void Execute();
};

class ActionMenuSalariedStaffBase : public GeneralMenuItem {
protected:
    SalariedStaff* _ptrSalariedStaff;
public:
    ActionMenuSalariedStaffBase(std::string output, SalariedStaff* salariedStaff) : GeneralMenuItem(output, NULL) { _ptrSalariedStaff = salariedStaff; }
};

class ActionMenuUpdateSalariedSalary : public ActionMenuSalariedStaffBase {
public:
    ActionMenuUpdateSalariedSalary(std::string output, SalariedStaff* salariedStaff) : ActionMenuSalariedStaffBase(output, salariedStaff) { }
    void Execute();
};

class ActionMenuUpdateSalariedSeniorStatus : public ActionMenuSalariedStaffBase {
public:
    ActionMenuUpdateSalariedSeniorStatus(std::string output, SalariedStaff* salariedStaff) : ActionMenuSalariedStaffBase(output, salariedStaff) { }
    void Execute();
};

class ActionMenuContractStaffBase : public GeneralMenuItem {
protected:
    ContractStaff* _ptrContractStaff;
public:
    ActionMenuContractStaffBase(std::string output, ContractStaff* contractStaff) : GeneralMenuItem(output, NULL) { _ptrContractStaff = contractStaff; }
};

class ActionMenuUpdateContractWage : public ActionMenuContractStaffBase {
public:
    ActionMenuUpdateContractWage(std::string output, ContractStaff* contractStaff) : ActionMenuContractStaffBase(output, contractStaff) { }
    void Execute();
};

class ActionMenuUpdateContractHours : public ActionMenuContractStaffBase {
public:
    ActionMenuUpdateContractHours(std::string output, ContractStaff* contractStaff) : ActionMenuContractStaffBase(output, contractStaff) { }
    void Execute();
};

class ActionMenuUpdateContractWeeks : public ActionMenuContractStaffBase {
public:
    ActionMenuUpdateContractWeeks(std::string output, ContractStaff* contractStaff) : ActionMenuContractStaffBase(output, contractStaff) { }
    void Execute();
};

/// <summary>
/// Base class for menu items that will be involved in the budget calculation process, requires a BudgetCalculator instance instead of a staff manager instance, gets staff manager pointer 
/// from the budget calculator.
/// </summary>
class MenuCalculateBudgetBase : public GeneralMenuItem {
protected:
    BudgetCalculator* _ptrBudgetCalculator;
public:
    MenuCalculateBudgetBase(std::string output, BudgetCalculator* budgetCalculator) : GeneralMenuItem(output, budgetCalculator->GetStaffManagerPtr()) { _ptrBudgetCalculator = budgetCalculator; }
};

/// <summary>
/// Uses the BudgetCalculator and StaffManager to display a report on the payroll budget.
/// </summary>
class SubMenuViewPayrollBudgetReport : public MenuCalculateBudgetBase {
    std::vector<SalariedStaff>* _ptrSalariedStaff;
    std::vector<ContractStaff>* _ptrContractStaff;
    FileManager* _ptrFileManager;
public:
    SubMenuViewPayrollBudgetReport(std::string output, BudgetCalculator* budgetCalculator, FileManager* fileManager);
    void Execute();
};

/// <summary>
/// Allows user to set the minimum budget overun percentage
/// </summary>
class SubMenuUpdateMinOverrun : public MenuCalculateBudgetBase {
public:
    SubMenuUpdateMinOverrun(std::string output, BudgetCalculator* budgetCalculator) : MenuCalculateBudgetBase(output, budgetCalculator) {}
    void Execute();
};

/// <summary>
/// Allows user to set the max budget overrun percentage.
/// </summary>
class SubMenuUpdateMaxOverrun : public MenuCalculateBudgetBase {
public:
    SubMenuUpdateMaxOverrun(std::string output, BudgetCalculator* budgetCalculator) : MenuCalculateBudgetBase(output, budgetCalculator) {}
    void Execute();
};

/// <summary>
/// Allows user to change the project length (in years), value from this is stored in BudgetCalculator and is simply used like a multiplier for the relevant costs.
/// </summary>
class SubMenuUpdateProjectLength : public MenuCalculateBudgetBase {
public:
    SubMenuUpdateProjectLength(std::string output, BudgetCalculator* budgetCalculator) : MenuCalculateBudgetBase(output, budgetCalculator) {}
    void Execute();
};
#endif // !MENU_H
