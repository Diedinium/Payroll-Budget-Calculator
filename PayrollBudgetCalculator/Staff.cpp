#include "Staff.h"

void Staff::UpdateDetails(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment) {
	_strFirstName = strFirstName;
	_strLastName = strLastName;
	_strJobRole = strJobRole;
	_strDepartment = strDepartment;
}

void Staff::UpdateDetails(std::string strJobRole, std::string strDepartment) {
	_strJobRole = strJobRole;
	_strDepartment = strDepartment;
}

Staff::Staff() {
	_strFirstName = "";
	_strLastName = "";
	_strJobRole = "";
	_strDepartment = "";
}

Staff::Staff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment) {
	_strFirstName = strFirstName;
	_strLastName = strLastName;
	_strJobRole = strJobRole;
	_strDepartment = strDepartment;
}

SalariedStaff::SalariedStaff() : Staff() {
	_dSalary = 0;
	_boolIsSenior = false;
}

SalariedStaff::SalariedStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dSalary, bool boolIsSenior) : Staff(strFirstName, strLastName, strJobRole, strDepartment) {
	_dSalary = dSalary;
	_boolIsSenior = boolIsSenior;
}

//nlohmann::json SalariedStaff::to_json() {
//	nlohmann::json json;
//	json["firstName"] = this->GetFirstName();
//	json["lastName"] = this->GetLastName();
//	json["jobRole"] = this->GetJobRole();
//	json["department"] = this->GetDepartment();
//	json["salary"] = this->GetSalary();
//	json["isSenior"] = this->GetSenior();
//	return json;
//}

ContractStaff::ContractStaff() : Staff() {
	_dWage = 0;
	_dWeeklyHours = 0;
	_iWeeks = 0;
}

ContractStaff::ContractStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dWage, double dWeeklyHours, int iWeeks) : Staff(strFirstName, strLastName, strJobRole, strDepartment) {
	_dWage = dWage;
	_dWeeklyHours = dWeeklyHours;
	_iWeeks = iWeeks;
}

//nlohmann::json ContractStaff::to_json() {
//
//}

double ContractStaff::GetContractCost() {
	return (_dWage * _dWeeklyHours) * (double)_iWeeks;
}