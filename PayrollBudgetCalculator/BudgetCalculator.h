#pragma once

#include <string>
#include <vector>
#include "StaffManager.h"
#include "Staff.h"

#ifndef H_BUDGETCALCULATOR
#define H_BUDGETCALCULATOR
class BudgetCalculator {
private:
	std::vector<SalariedStaff>* _ptrVecSalariedStaff;
	std::vector<ContractStaff>* _ptrVecContractStaff;
	StaffManager* _ptrStaffManager;
	double _dMinBudgetOverPercent;
	double _dMaxBudgetOverPercent;
public:
	BudgetCalculator(StaffManager* _ptrStaffmanager);
	void Calculate();

	double GetMinOverPercent() { return _dMinBudgetOverPercent; }
	void SetMinOverPercent(double minOverPercent) { _dMinBudgetOverPercent = minOverPercent; }

	double GetMaxOverPercent() { return _dMaxBudgetOverPercent; }
	void SetMaxOverPercent(double maxOverPercent) { _dMaxBudgetOverPercent = maxOverPercent; }
};
#endif // !H_BUDGETCALCULATOR
