#include "BudgetCalculator.h"

BudgetCalculator::BudgetCalculator() {
	_ptrStaffManager = NULL;
	_ptrVecSalariedStaff = NULL;
	_ptrVecContractStaff = NULL;
	_dMinBudgetOverPercent = 0;
	_dMaxBudgetOverPercent = 0;
	_dProjectLength = 0;
	_dSeniorSalaryTotal = 0;
	_dSeniorSalaryAverage = 0;
	_dSalariedSalaryTotal = 0;
	_dSalariedSalaryAverage = 0;
	_dContractPayTotal = 0;
	_dContractPayAverage = 0;
	_dTotalPayroll = 0;
	_dMinimumOverBudget = 0;
	_dMaximumOverBudget = 0;

	_boolProjectIsDefaultDuration = true;
	_dProjLenSeniorSalaryTotal = 0;
	_dProjLenSalariedSalaryTotal = 0;
	_dProjLenContractPayTotal = 0;
	_dProjLenTotalPayroll = 0;
	_dProjLenMinimumOverBudget = 0;
	_dProjLenMaximumOverBudget = 0;
}

BudgetCalculator::BudgetCalculator(StaffManager* staffManager) {
	_ptrStaffManager = staffManager;
	_ptrVecSalariedStaff = staffManager->GetPtrSalariedStaff();
	_ptrVecContractStaff = staffManager->GetPtrContractStaff();
	_dMinBudgetOverPercent = 10;
	_dMaxBudgetOverPercent = 35;
	_dProjectLength = 1.0;
	_dSeniorSalaryTotal = 0;
	_dSeniorSalaryAverage = 0;
	_dSalariedSalaryTotal = 0;
	_dSalariedSalaryAverage = 0;
	_dContractPayTotal = 0;
	_dContractPayAverage = 0;
	_dTotalPayroll = 0;
	_dMinimumOverBudget = 0;
	_dMaximumOverBudget = 0;

	_boolProjectIsDefaultDuration = true;
	_dProjLenSeniorSalaryTotal = 0;
	_dProjLenSalariedSalaryTotal = 0;
	_dProjLenContractPayTotal = 0;
	_dProjLenTotalPayroll = 0;
	_dProjLenMinimumOverBudget = 0;
	_dProjLenMaximumOverBudget = 0;
}

void BudgetCalculator::EvaluateProjectDuration() {
	if (_dProjectLength != 1.0) _boolProjectIsDefaultDuration = false;
	else _boolProjectIsDefaultDuration = true;
}

void BudgetCalculator::SetProjectLength(double projectLength) {
	_dProjectLength = projectLength;
	_boolProjectIsDefaultDuration = (_dProjectLength == 1.0);
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
			return d + ((obj.GetWage() * obj.GetWeeklyHours()) * (double)obj.GetWeeks());
		});
	_dContractPayAverage = (_dContractPayTotal > 0.0 ? _dContractPayTotal / _ptrStaffManager->CountContractStaff() : 0.0);

	_dTotalPayroll = _dSeniorSalaryTotal + _dSalariedSalaryTotal + _dContractPayTotal;
	_dMinimumOverBudget = _dTotalPayroll * ((_dMinBudgetOverPercent / 100.0) + 1.0);
	_dMaximumOverBudget = _dTotalPayroll * ((_dMaxBudgetOverPercent / 100.0) + 1.0);

	this->EvaluateProjectDuration();
	if (!_boolProjectIsDefaultDuration) {
		_dProjLenSeniorSalaryTotal = _dSeniorSalaryTotal * _dProjectLength;
		_dProjLenSalariedSalaryTotal = _dSalariedSalaryTotal * _dProjectLength;
		_dProjLenContractPayTotal = _dContractPayTotal * _dProjectLength;
		_dProjLenTotalPayroll = _dTotalPayroll * _dProjectLength;
		_dProjLenMinimumOverBudget = _dMinimumOverBudget * _dProjectLength;
		_dProjLenMaximumOverBudget = _dMaximumOverBudget * _dProjectLength;
	}
}