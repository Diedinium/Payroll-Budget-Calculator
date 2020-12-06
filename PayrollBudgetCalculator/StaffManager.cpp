#include "StaffManager.h"

/// <summary>
/// Takes salaried staff member object and adds to vector within staff manager.
/// </summary>
/// <param name="objSalariedStaff"></param>
void StaffManager::AddSalariedStaff(SalariedStaff objSalariedStaff) {
	auto position = std::find_if(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&objSalariedStaff](SalariedStaff& obj) { return obj.GetFullName() == objSalariedStaff.GetFullName(); });

	if (position == _vecSalariedStaff.end()) {
		_vecSalariedStaff.push_back(objSalariedStaff);
	}
	else {
		throw std::exception("Cannot add salaried staff member as staff member with this name already exists.");
	}
}

/// <summary>
/// Takes contract staff member object and adds to vector within staff manager.
/// </summary>
/// <param name="objContractStaff"></param>
void StaffManager::AddContractStaff(ContractStaff objContractStaff) {
	auto position = std::find_if(_vecContractStaff.begin(), _vecContractStaff.end(), [&objContractStaff](ContractStaff& obj) { return obj.GetFullName() == objContractStaff.GetFullName(); });

	if (position == _vecContractStaff.end()) {
		_vecContractStaff.push_back(objContractStaff);
	}
	else {
		throw std::exception("Cannot add contract staff member as staff member with this name already exists.");
	}
}

/// <summary>
/// Takes full name and attempts to find and remove salaried staff member with this name.
/// Note to self: This could be improved via polymorphism; a remove function that is generic to either staff member type could be made. SalariedStaff and ContractStaff can be cast to a pointer 
/// of staff, allowing same remove function to remove either. Would require other changes as well though, such as storing all staff in same vector... maybe a change for another day.
/// </summary>
/// <param name="strFullName"></param>
void StaffManager::RemoveSalariedStaff(std::string strFullName) {
	auto position = std::find_if(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&strFullName](SalariedStaff& obj) { return obj.GetFullName() == strFullName; });

	if (position != _vecSalariedStaff.end()) {
		_vecSalariedStaff.erase(position);
	}
	else {
		throw std::invalid_argument("Cannot remove " + strFullName + ", staff member not found");
	}
}

/// <summary>
/// Takes full name and tries to find and remove contract staff memember with this name
/// </summary>
/// <param name="strFullName"></param>
void StaffManager::RemoveContractStaff(std::string strFullName) {
	auto position = std::find_if(_vecContractStaff.begin(), _vecContractStaff.end(), [&strFullName](ContractStaff& obj) { return obj.GetFullName() == strFullName; });

	if (position != _vecContractStaff.end()) {
		_vecContractStaff.erase(position);
	}
	else {
		throw std::invalid_argument("Cannot remove " + strFullName + ", staff member not found");
	}
}

/// <summary>
/// Returns pointer to salaried staff member, finds using full name.
/// </summary>
/// <param name="strFullName"></param>
/// <returns></returns>
SalariedStaff* StaffManager::GetSalariedStaff(std::string strFullname) {
	auto position = std::find_if(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&strFullname](SalariedStaff& obj) { return obj.GetFullName() == strFullname; });

	if (position != _vecSalariedStaff.end()) {
		return &*position;
	}
	else {
		return NULL;
	}
}

/// <summary>
/// Returns pointer to contract staff member, finds using full name.
/// </summary>
/// <param name="strFullName"></param>
/// <returns>ContractStaff*</returns>
ContractStaff* StaffManager::GetContractStaff(std::string strFullname) {
	auto position = std::find_if(_vecContractStaff.begin(), _vecContractStaff.end(), [&strFullname](ContractStaff& obj) { return obj.GetFullName() == strFullname; });

	if (position != _vecContractStaff.end()) {
		return &*position;
	}
	else {
		return NULL;
	}
}

/// <summary>
/// Returns number of senior salaried staff currently in the staff manager.
/// </summary>
/// <returns>size_t</returns>
size_t StaffManager::CountSeniorStaff() {
	size_t count = 0;
	std::for_each(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&count](SalariedStaff& item) {
		if (item.GetSenior()) count++;
	});
	return count;
}

/// <summary>
/// Returns number of standard salaried staff currently in the staff manager.
/// </summary>
/// <returns>size_t</returns>
size_t StaffManager::CountStandardStaff() {
	size_t count = 0;
	std::for_each(_vecSalariedStaff.begin(), _vecSalariedStaff.end(), [&count](SalariedStaff& item) {
		if (!item.GetSenior()) count++;
	});
	return count;
}

/// <summary>
/// Returns the number of contract staff currently in the staff manager, implemeneted to avoid need to return pointer to contract staff vector just to get size.
/// </summary>
/// <returns></returns>
size_t StaffManager::CountContractStaff() {
	return _vecContractStaff.size();
}

/// <summary>
/// Empties the vectors storing staff.
/// </summary>
void StaffManager::Reset() {
	_vecSalariedStaff.clear();
	_vecContractStaff.clear();
}
