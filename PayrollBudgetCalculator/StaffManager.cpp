#include "StaffManager.h"

void StaffManager::AddSalariedStaff(SalariedStaff objSalariedStaff) {
	auto position = std::find_if(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&objSalariedStaff](SalariedStaff& obj) { return obj.GetFullName() == objSalariedStaff.GetFullName(); });

	if (position == _vecSalariedStaff.end()) {
		_vecSalariedStaff.push_back(objSalariedStaff);
	}
	else {
		throw std::exception("Cannot add salaried staff member as staff member with this name already exists.");
	}
}

void StaffManager::AddContractStaff(ContractStaff objContractStaff) {
	auto position = std::find_if(_vecContractStaff.begin(), _vecContractStaff.end(), [&objContractStaff](ContractStaff& obj) { return obj.GetFullName() == objContractStaff.GetFullName(); });

	if (position == _vecContractStaff.end()) {
		_vecContractStaff.push_back(objContractStaff);
	}
	else {
		throw std::exception("Cannot add contract staff member as staff member with this name already exists.");
	}
}

SalariedStaff* StaffManager::GetSalariedStaff(std::string strFullname) {
	auto position = std::find_if(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&strFullname](SalariedStaff& obj) { return obj.GetFullName() == strFullname; });

	if (position != _vecSalariedStaff.end()) {
		return &*position;
	}
	else {
		return NULL;
	}
}

ContractStaff* StaffManager::GetContractStaff(std::string strFullname) {
	auto position = std::find_if(_vecContractStaff.begin(), _vecContractStaff.end(), [&strFullname](ContractStaff& obj) { return obj.GetFullName() == strFullname; });

	if (position != _vecContractStaff.end()) {
		return &*position;
	}
	else {
		return NULL;
	}
}

size_t StaffManager::CountSeniorStaff() {
	size_t count = 0;
	std::for_each(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&count](SalariedStaff& item) {
		if (item.GetSenior()) count++;
	});
	return count;
}

size_t StaffManager::CountStandardStaff() {
	size_t count = 0;
	std::for_each(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&count](SalariedStaff& item) {
		if (!item.GetSenior()) count++;
	});
	return count;
}