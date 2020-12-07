#pragma once

#include <string>
#include <nlohmann/json.hpp>

#ifndef STAFF_H
#define STAFF_H
/// <summary>
/// Base class for Salaried and Contract staff - contains common details shared between the two.
/// </summary>
class Staff {
protected:
	std::string _strFirstName;
	std::string _strLastName;
	std::string _strJobRole;
	std::string _strDepartment;
public:
	/// <summary>
	/// Staff default constructor, initialises common fields as empty strings.
	/// </summary>
	Staff();

	/// <summary>
	/// Staff parameter constructor, allows all common fields to be set.
	/// </summary>
	/// <param name="strFirstName"></param>
	/// <param name="strLastName"></param>
	/// <param name="strJobRole"></param>
	/// <param name="strDepartment"></param>
	Staff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment);

	std::string GetFullName() { return _strFirstName + " " + _strLastName; }

	std::string GetFirstName() { return _strFirstName; }
	void SetFirstName(std::string strFirstName) { _strFirstName = strFirstName; }

	std::string GetLastName() { return _strLastName; }
	void SetLastName(std::string strLastName) { _strLastName = strLastName; }

	std::string GetJobRole() { return _strJobRole; }
	void SetJobRole(std::string strJobRole) { _strJobRole = strJobRole; }

	std::string GetDepartment() { return _strDepartment; }
	void SetDepartment(std::string strDepartment) { _strDepartment = strDepartment; }

	/// <summary>
	/// Combined update function that sets the main staff details at same time.
	/// </summary>
	/// <param name="strFirstName"></param>
	/// <param name="strLastName"></param>
	/// <param name="strJobRole"></param>
	/// <param name="strDepartment"></param>
	void UpdateDetails(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment);
};

/// <summary>
/// Stores details for a salaried staff member, inherits base details from Staff class.
/// </summary>
class SalariedStaff : public Staff {
	double _dSalary;
	bool _boolIsSenior;
public:
	/// <summary>
	/// SalariedStaff default constructor, initialises SalariedStaff specific fields and uses Staff base constructor to initialise the rest.
	/// </summary>
	SalariedStaff();

	/// <summary>
	/// SalariedStaff parameter constructor, allows all fields for SalariedStaff to be set at once. Uses Staff default constructor to set common fields.
	/// </summary>
	/// <param name="strFirstName"></param>
	/// <param name="strLastName"></param>
	/// <param name="strJobRole"></param>
	/// <param name="strDepartment"></param>
	/// <param name="dSalary"></param>
	/// <param name="boolIsSenior"></param>
	SalariedStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dSalary, bool boolIsSenior);

	double GetSalary() { return _dSalary; }
	void SetSalary(double dSalary) { _dSalary = dSalary; }

	bool GetSenior() { return _boolIsSenior; }
	void SetSenior(bool boolIsSenior) { _boolIsSenior = boolIsSenior; }

	// Macro from nlohmann json library that defines a to and from json for SalariedStaff - avoids a lot of boilerplate code.
	// See: https://github.com/nlohmann/json#arbitrary-types-conversions
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(SalariedStaff, _strFirstName, _strLastName, _strJobRole, _strDepartment, _dSalary, _boolIsSenior)
};

/// <summary>
/// Stores details for a contract staff member, inherits base details from Staff class.
/// </summary>
class ContractStaff : public Staff {
	double _dWage;
	double _dWeeklyHours;
	int _iWeeks;
public:
	/// <summary>
	/// ContractStaff default constructor, initialises ContractStaff specific fields and uses Staff base constructor to initialise the rest.
	/// </summary>
	ContractStaff();

	/// <summary>
	/// ContractStaff parameter constructor, allows all fields for ContractStaff to be set at once. Uses Staff default constructor to set common fields.
	/// </summary>
	/// <param name="strFirstName"></param>
	/// <param name="strLastName"></param>
	/// <param name="strJobRole"></param>
	/// <param name="strDepartment"></param>
	/// <param name="dWage"></param>
	/// <param name="dWeeklyHours"></param>
	/// <param name="iWeeks"></param>
	ContractStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dWage, double dWeeklyHours, int iWeeks);

	double GetWage() { return _dWage; }
	void SetWage(double dWage) { _dWage = dWage; }
	
	double GetWeeklyHours() { return _dWeeklyHours; }
	void SetWeeklyHours(double dWeeklyHours) { _dWeeklyHours = dWeeklyHours; }

	int GetWeeks() { return _iWeeks; }
	void SetWeeks(int iWeeks) { _iWeeks = iWeeks; }

	std::string GetWeeksFormatted() { return std::to_string(_iWeeks) + " weeks"; }
	
	/// <summary>
	/// Returns contract cost for a contract staff member.
	/// </summary>
	/// <returns></returns>
	double GetContractCost();

	// Macro from nlohmann json library that defines a to and from json for ContractStaff - avoids a lot of boilerplate code.
	// See: https://github.com/nlohmann/json#arbitrary-types-conversions
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(ContractStaff, _strFirstName, _strLastName, _strJobRole, _strDepartment, _dWage, _dWeeklyHours, _iWeeks)
};

#endif // STAFF_H