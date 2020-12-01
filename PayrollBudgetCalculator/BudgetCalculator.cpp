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
	std::for_each(_ptrVecSalariedStaff->begin(), _ptrVecSalariedStaff->end(), [&](SalariedStaff obj) {
		if (obj.GetSenior()) {
			_dSeniorSalaryTotal += obj.GetSalary();
		}
		else {
			_dSalariedSalaryTotal += obj.GetSalary();
		}
	});

	_dSeniorSalaryAverage = (_dSeniorSalaryTotal > 0.0 ? _dSeniorSalaryTotal / _ptrStaffManager->CountSeniorStaff() : 0.0);
	_dSalariedSalaryAverage = (_dSalariedSalaryTotal > 0.0 ? _dSalariedSalaryTotal / _ptrStaffManager->CountStandardStaff() : 0.0);

	_dContractPayTotal = std::accumulate(_ptrVecContractStaff->begin(), _ptrVecContractStaff->end(), 0.0, [](double d, ContractStaff obj)
		{
			return obj.GetWage() * obj.GetWeeklyHours() * (double)obj.GetWeeks();
		});
	_dContractPayAverage = std::accumulate(_ptrVecContractStaff->begin(), _ptrVecContractStaff->end(), 0.0, [&](double d, ContractStaff obj)
		{
			return (obj.GetWage() * obj.GetWeeklyHours() * (double)obj.GetWeeks()) / _ptrStaffManager->CountContractStaff();
		});
}