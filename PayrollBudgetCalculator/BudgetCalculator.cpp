#include "BudgetCalculator.h"

BudgetCalculator::BudgetCalculator(StaffManager* staffManager) {
	_ptrStaffManager = staffManager;
	_ptrVecSalariedStaff = staffManager->GetPtrSalariedStaff();
	_ptrVecContractStaff = staffManager->GetPtrContractStaff();
	_dMinBudgetOverPercent = 10;
	_dMaxBudgetOverPercent = 35;
	_dProjectLength = 1;
	_dSeniorSalaryTotal = 0;
	_dSeniorSalaryAverage = 0;
	_dSalariedSalaryTotal = 0;
	_dSalariedSalaryAverage = 0;
	_dContractPayTotal = 0;
	_dContractPayAverage = 0;
}

void BudgetCalculator::Calculate() {
	_dSeniorSalaryTotal = std::accumulate(_ptrVecSalariedStaff->begin(), _ptrVecSalariedStaff->end(), 0.0, [](double d, SalariedStaff& obj) 
		{ 
			if (obj.GetSenior()) return obj.GetSalary() + d;
			else return 0.0;
		});
	_dSeniorSalaryAverage = std::accumulate(_ptrVecSalariedStaff->begin(), _ptrVecSalariedStaff->end(), 0.0, [](double d, SalariedStaff& obj) 
		{ 
			if (obj.GetSenior()) return obj.GetSalary() + d;
			else return 0.0;
		});
	_dSeniorSalaryAverage = (_dSeniorSalaryAverage > 0.0 ? _dSeniorSalaryAverage / _ptrStaffManager->CountSeniorStaff() : 0.0);
}