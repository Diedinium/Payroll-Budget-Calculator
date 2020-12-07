#include "Staff.h"

/// <summary>
/// Combined update function that sets the main staff details at same time.
/// </summary>
/// <param name="strFirstName"></param>
/// <param name="strLastName"></param>
/// <param name="strJobRole"></param>
/// <param name="strDepartment"></param>
void Staff::UpdateDetails(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment) {
	_strFirstName = strFirstName;
	_strLastName = strLastName;
	_strJobRole = strJobRole;
	_strDepartment = strDepartment;
}

/// <summary>
/// Staff default constructor, initialises common fields as empty strings.
/// </summary>
Staff::Staff() {
	_strFirstName = "";
	_strLastName = "";
	_strJobRole = "";
	_strDepartment = "";
}

/// <summary>
/// Staff parameter constructor, allows all common fields to be set.
/// </summary>
/// <param name="strFirstName"></param>
/// <param name="strLastName"></param>
/// <param name="strJobRole"></param>
/// <param name="strDepartment"></param>
Staff::Staff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment) {
	_strFirstName = strFirstName;
	_strLastName = strLastName;
	_strJobRole = strJobRole;
	_strDepartment = strDepartment;
}

/// <summary>
/// SalariedStaff default constructor, initialises SalariedStaff specific fields and uses Staff base constructor to initialise the rest.
/// </summary>
SalariedStaff::SalariedStaff() : Staff() {
	_dSalary = 0;
	_boolIsSenior = false;
}

/// <summary>
/// SalariedStaff parameter constructor, allows all fields for SalariedStaff to be set at once. Uses Staff default constructor to set common fields.
/// </summary>
/// <param name="strFirstName"></param>
/// <param name="strLastName"></param>
/// <param name="strJobRole"></param>
/// <param name="strDepartment"></param>
/// <param name="dSalary"></param>
/// <param name="boolIsSenior"></param>
SalariedStaff::SalariedStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dSalary, bool boolIsSenior) : Staff(strFirstName, strLastName, strJobRole, strDepartment) {
	_dSalary = dSalary;
	_boolIsSenior = boolIsSenior;
}

/// <summary>
/// ContractStaff default constructor, initialises ContractStaff specific fields and uses Staff base constructor to initialise the rest.
/// </summary>
ContractStaff::ContractStaff() : Staff() {
	_dWage = 0;
	_dWeeklyHours = 0;
	_iWeeks = 0;
}

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
ContractStaff::ContractStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dWage, double dWeeklyHours, int iWeeks) : Staff(strFirstName, strLastName, strJobRole, strDepartment) {
	_dWage = dWage;
	_dWeeklyHours = dWeeklyHours;
	_iWeeks = iWeeks;
}

/// <summary>
/// Returns contract cost for a contract staff member.
/// </summary>
/// <returns></returns>
double ContractStaff::GetContractCost() {
	return (_dWage * _dWeeklyHours) * (double)_iWeeks;
}