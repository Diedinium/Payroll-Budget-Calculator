#include "BudgetCalculator.h"

BudgetCalculator::BudgetCalculator(StaffManager* staffManager) {
	_ptrStaffManager = staffManager;
	_ptrVecSalariedStaff = staffManager->GetPtrSalariedStaff();
	_ptrVecContractStaff = staffManager->GetPtrContractStaff();
}