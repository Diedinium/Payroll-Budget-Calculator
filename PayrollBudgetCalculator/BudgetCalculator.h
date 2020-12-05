#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <nlohmann/json.hpp>
#include "StaffManager.h"
#include "Staff.h"

#ifndef H_BUDGETCALCULATOR
#define H_BUDGETCALCULATOR
/// <summary>
/// Uses StaffManager and the lists of Staff the instance contains to calculate budget reports; all calculated values are 0 until Calculate is called.
/// </summary>
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
	double _dTotalPayroll;
	double _dMinimumOverBudget;
	double _dMaximumOverBudget;

	bool _boolProjectIsDefaultDuration;
	double _dProjLenSeniorSalaryTotal;
	double _dProjLenSalariedSalaryTotal;
	double _dProjLenContractPayTotal;
	double _dProjLenTotalPayroll;
	double _dProjLenMinimumOverBudget;
	double _dProjLenMaximumOverBudget;
	void EvaluateProjectDuration();
public:
	BudgetCalculator();
	BudgetCalculator(StaffManager* _ptrStaffmanager);
	void Calculate();

	double GetMinOverPercent() { return _dMinBudgetOverPercent; }
	void SetMinOverPercent(double minOverPercent) { _dMinBudgetOverPercent = minOverPercent; }

	double GetMaxOverPercent() { return _dMaxBudgetOverPercent; }
	void SetMaxOverPercent(double maxOverPercent) { _dMaxBudgetOverPercent = maxOverPercent; }

	double GetProjectLength() { return _dProjectLength; }
	void SetProjectLength(double projectLength);

	StaffManager* GetStaffManagerPtr() { return _ptrStaffManager; }

	double GetSeniorSalaryTotal() { return _dSeniorSalaryTotal; }
	double GetSeniorSalaryAverage() { return _dSeniorSalaryAverage; }

	double GetSalariedSalaryTotal() { return _dSalariedSalaryTotal; }
	double GetSalariedSalaryAverage() { return _dSalariedSalaryAverage; }

	double GetContractorCostTotal() { return _dContractPayTotal; }
	double GetContractorCostAverage() { return _dContractPayAverage; }

	double GetTotalPayroll() { return _dTotalPayroll; }
	double GetMinimumOverBudget() { return _dMinimumOverBudget; }
	double GetMaximumOverBudget() { return _dMaximumOverBudget; }
	
	double GetProjectIsDefaultDuration() { return _boolProjectIsDefaultDuration; }
	double GetProjLenSeniorSalaryTotal() { return _dProjLenSeniorSalaryTotal; }
	double GetProjLenSalariedSalaryTotal() { return _dProjLenSalariedSalaryTotal; }
	double GetProjLenContractPayTotal() { return _dProjLenContractPayTotal; }
	double GetProjLenTotalPayroll() { return _dProjLenTotalPayroll; }
	double GetProjLenMinimumOverBudget() { return _dProjLenMinimumOverBudget; }
	double GetProjLenMaximumOverBudget() { return _dProjLenMaximumOverBudget; }

	// Macro from nlohmann json library that defines a to and from json for BudgetCalculator - avoids a lot of boilerplate.
	// See: https://github.com/nlohmann/json#arbitrary-types-conversions
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(BudgetCalculator, _dMinBudgetOverPercent, _dMaxBudgetOverPercent, _dProjectLength)
};
#endif // !H_BUDGETCALCULATOR
