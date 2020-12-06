#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "Staff.h"

#ifndef STAFFMANAGER_H
#define STAFFMANAGER_H
/// <summary>
/// Stores and contains functions to manage staff.
/// </summary>
class StaffManager {
	std::vector<SalariedStaff> _vecSalariedStaff;
	std::vector<ContractStaff> _vecContractStaff;
public:
	/// <summary>
	/// Takes salaried staff member object and adds to vector within staff manager.
	/// </summary>
	/// <param name="objSalariedStaff"></param>
	void AddSalariedStaff(SalariedStaff objSalariedStaff);

	/// <summary>
	/// Takes contract staff member object and adds to vector within staff manager.
	/// </summary>
	/// <param name="objContractStaff"></param>
	void AddContractStaff(ContractStaff objContractStaff);

	/// <summary>
	/// Takes full name and attempts to find and remove salaried staff member with this name.
	/// Note to self: This could be improved via polymorphism; a remove function that is generic to either staff member type could be made. SalariedStaff and ContractStaff can be cast to a pointer 
	/// of staff, allowing same remove function to remove either. Would require other changes as well though, such as storing all staff in same vector... maybe a change for another day.
	/// </summary>
	/// <param name="strFullName"></param>
	void RemoveSalariedStaff(std::string strFullName);

	/// <summary>
	/// Takes full name and tries to find and remove contract staff memember with this name
	/// </summary>
	/// <param name="strFullName"></param>
	void RemoveContractStaff(std::string strFullName);

	/// <summary>
	/// Returns pointer to salaried staff member, finds using full name.
	/// </summary>
	/// <param name="strFullName"></param>
	/// <returns>SalariedStaff*</returns>
	SalariedStaff* GetSalariedStaff(std::string strFullName);

	/// <summary>
	/// Returns pointer to contract staff member, finds using full name.
	/// </summary>
	/// <param name="strFullName"></param>
	/// <returns>ContractStaff*</returns>
	ContractStaff* GetContractStaff(std::string strFullName);
	
	/// <summary>
	/// Gets pointer to the vector storing salaried staff.
	/// </summary>
	/// <returns></returns>
	std::vector<SalariedStaff>* GetPtrSalariedStaff() { return &_vecSalariedStaff; }

	/// <summary>
	/// Gets pointer to the vector storing contract staff.
	/// </summary>
	/// <returns></returns>
	std::vector<ContractStaff>* GetPtrContractStaff() { return &_vecContractStaff; }

	/// <summary>
	/// Returns number of senior salaried staff currently in the staff manager.
	/// </summary>
	/// <returns>size_t</returns>
	size_t CountSeniorStaff();

	/// <summary>
	/// Returns number of standard salaried staff currently in the staff manager.
	/// </summary>
	/// <returns>size_t</returns>
	size_t CountStandardStaff();

	/// <summary>
	/// Returns the number of contract staff currently in the staff manager, implemeneted to avoid need to return pointer to contract staff vector just to get size.
	/// </summary>
	/// <returns></returns>
	size_t CountContractStaff();

	/// <summary>
	/// Empties the vectors storing staff.
	/// </summary>
	void Reset();
};

#endif // STAFFMANAGER_H
