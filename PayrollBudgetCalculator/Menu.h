#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "StaffManager.h"
#include "InputValidator.h"

#ifndef MENU_H
#define MENU_H
class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string ItemText() const = 0;
    virtual void Execute() = 0;
};

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
public:
    MenuCalculateBudget(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
    void Execute();
};

class MenuSaveLoad : public GeneralMenuItem {
public:
    MenuSaveLoad(std::string output, StaffManager* staffManager) : GeneralMenuItem(output, staffManager) {};
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
#endif // !MENU_H
