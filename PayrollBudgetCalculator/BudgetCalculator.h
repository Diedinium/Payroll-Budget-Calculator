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

	/// <summary>
	/// When called, updates the projectIsDefaultDuration member to true or false based on if the project length is or is not 1 year long.
	/// </summary>
	void EvaluateProjectDuration();
public:
	/// <summary>
	/// BudgetCalculator default constructor, initialises values. Needed to allow JSON to/from serialisation to work.
	/// </summary>
	BudgetCalculator();

	/// <summary>
	/// BudgetCalculator parameter constructor, initialises with default values and stores pointer to staff manager
	/// </summary>
	/// <param name="staffManager"></param>
	BudgetCalculator(StaffManager* _ptrStaffmanager);

	/// <summary>
	/// Performs the necessary calculations to populate values for the payroll budget reports.
	/// </summary>
	void Calculate();

	double GetMinOverPercent() { return _dMinBudgetOverPercent; }
	void SetMinOverPercent(double minOverPercent) { _dMinBudgetOverPercent = minOverPercent; }

	double GetMaxOverPercent() { return _dMaxBudgetOverPercent; }
	void SetMaxOverPercent(double maxOverPercent) { _dMaxBudgetOverPercent = maxOverPercent; }

	double GetProjectLength() { return _dProjectLength; }

	/// <summary>
	/// Used to set the project length, re-evaluates the project default duration once set.
	/// </summary>
	/// <param name="projectLength"></param>
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
