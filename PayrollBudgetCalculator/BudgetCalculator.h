#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "StaffManager.h"
#include "Staff.h"

#ifndef H_BUDGETCALCULATOR
#define H_BUDGETCALCULATOR
class BudgetCalculator {

	std::vector<SalariedStaff>* _ptrVecSalariedStaff;
	std::vector<ContractStaff>* _ptrVecContractStaff;
	StaffManager* _ptrStaffManager;
	double _dMinBudgetOverPercent;
	double _dMaxBudgetOverPercent;
	double _dProjectLength;

	double _dSeniorSalaryTotal;
	double _dSeniorSalaryAverage;
	double _dSalariedSalaryTotal;
	double _dSalariedSalaryAverage;
	double _dContractPayTotal;
	double _dContractPayAverage;
public:
	BudgetCalculator(StaffManager* _ptrStaffmanager);
	void Calculate();

	double GetMinOverPercent() { return _dMinBudgetOverPercent; }
	void SetMinOverPercent(double minOverPercent) { _dMinBudgetOverPercent = minOverPercent; }

	double GetMaxOverPercent() { return _dMaxBudgetOverPercent; }
	void SetMaxOverPercent(double maxOverPercent) { _dMaxBudgetOverPercent = maxOverPercent; }

	double GetProjectLength() { return _dProjectLength; }
	void SetProjectLength(double projectLength) { _dProjectLength = projectLength; }

	StaffManager* GetStaffManagerPtr() { return _ptrStaffManager; }

	double GetSeniorSalaryTotal() { return _dSeniorSalaryTotal; }
	double GetSeniorSalaryAverage() { return _dSeniorSalaryAverage; }

	double GetSalariedSalaryTotal() { return _dSalariedSalaryTotal; }
	double GetSalariedSalaryAverage() { return _dSalariedSalaryAverage; }

	double GetContractorCostTotal() { return _dContractPayTotal; }
	double GetContractorCostAverage() { return _dContractPayAverage; }
};
#endif // !H_BUDGETCALCULATOR
