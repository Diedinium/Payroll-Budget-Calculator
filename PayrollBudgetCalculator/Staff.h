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
	std::string GetLastName() { return _strLastName; }
	std::string GetJobRole() { return _strJobRole; }
	std::string GetDepartment() { return _strDepartment; }

	void UpdateDetails(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment);
	void UpdateDetails(std::string strJobRole, std::string strDepartment);
};

class SalariedStaff : public Staff {
	double _dSalary;
	bool _boolIsSenior;
public:
	SalariedStaff();
	SalariedStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dSalary, bool boolIsSenior);

	void SetSalary(double dSalary) { _dSalary = dSalary; }
	double GetSalary() { return _dSalary; }

	void SetSenior(bool boolIsSenior) { _boolIsSenior = boolIsSenior; }
	bool GetSenior() { return _boolIsSenior; }
};

class ContractStaff : public Staff {
	double _dWage;
	double _dWeeklyHours;
	int _iWeeks;
public:
	ContractStaff();
	ContractStaff(std::string strFirstName, std::string strLastName, std::string strJobRole, std::string strDepartment, double dWage, double dWeeklyHours, int iWeeks);

	void SetWage(double dWage) { _dWage = dWage; }
	double GetWage() { return _dWage; }

	void SetWeeklyHours(double dWeeklyHours) { _dWeeklyHours = dWeeklyHours; }
	double GetWeeklyHours() { return _dWeeklyHours; }

	void SetWeeks(int iWeeks) { _iWeeks = iWeeks; }
	int GetWeeks() { return _iWeeks; }
	
	double GetContractCost();
};

#endif // STAFF_H