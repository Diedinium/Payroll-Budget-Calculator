#pragma once

#include <string>

#ifndef STAFF_H
#define STAFF_H
class Staff {
protected:
	std::string _strFirstName;
	std::string _strLastName;
	std::string _strJobRole;
	std::string _strDepartment;
public:
	Staff();
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

	void UpdateDetails(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment);
	void UpdateDetails(std::string strJobRole, std::string strDepartment);
};

class SalariedStaff : public Staff {
	double _dSalary;
	bool _boolIsSenior;
public:
	SalariedStaff();
	SalariedStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dSalary, bool boolIsSenior);

	double GetSalary() { return _dSalary; }
	void SetSalary(double dSalary) { _dSalary = dSalary; }

	bool GetSenior() { return _boolIsSenior; }
	void SetSenior(bool boolIsSenior) { _boolIsSenior = boolIsSenior; }
};

class ContractStaff : public Staff {
	double _dWage;
	double _dWeeklyHours;
	int _iWeeks;
public:
	ContractStaff();
	ContractStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dWage, double dWeeklyHours, int iWeeks);

	double GetWage() { return _dWage; }
	void SetWage(double dWage) { _dWage = dWage; }
	
	double GetWeeklyHours() { return _dWeeklyHours; }
	void SetWeeklyHours(double dWeeklyHours) { _dWeeklyHours = dWeeklyHours; }

	int GetWeeks() { return _iWeeks; }
	void SetWeeks(int iWeeks) { _iWeeks = iWeeks; }

	std::string GetWeeksFormatted() { return std::to_string(_iWeeks) + " weeks"; }
	
	double GetContractCost();
};

#endif // STAFF_H