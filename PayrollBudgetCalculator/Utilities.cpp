#include "Utilities.h"

void util::Pause() {
    std::cout << "Press any key to continue...\n";
    auto value = _getch();
}

void util::OutputContractStaffHeader() {
    std::cout << "----------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << std::left << "Job Role" << std::setw(20) << std::left << "Department" << std::setw(8) << std::left << "Wage" << std::setw(12) << std::left << "Hours p/w" << std::setw(10) << std::left << "Contracted" << "\n";
    std::cout << "----------------------------------------------------------------------------------------------------------\n";
}

void util::OutputSalariedStaffHeader() {
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << "Job Role" << std::setw(20) << "Department" << std::setw(12) << "Salary" << std::setw(5) << "Senior?" << "\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
}

void util::OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff) {
	util::for_each_iterator(ptrVecContractStaff->begin(), ptrVecContractStaff->end(), 0, [](int index, ContractStaff& item) {
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(4) << std::left << index
			<< std::fixed << std::setw(15) << std::left << item.GetFirstName()
			<< std::fixed << std::setw(15) << std::left << item.GetLastName()
			<< std::fixed << std::setw(25) << std::left << item.GetJobRole()
			<< std::fixed << std::setw(20) << std::left << item.GetDepartment()
			<< std::fixed << std::setw(8) << std::left << item.GetWage()
			<< std::fixed << std::setw(12) << std::left << item.GetWeeklyHours()
			<< std::fixed << std::setw(10) << std::left << item.GetWeeksFormatted() << "\n";
		});
}

void util::OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff) {
	util::for_each_iterator(ptrVecSalariedStaff->begin(), ptrVecSalariedStaff->end(), (long)0, [](int index, SalariedStaff& item) {
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(4) << std::left << index
			<< std::fixed << std::setw(15) << std::left << item.GetFirstName()
			<< std::fixed << std::setw(15) << std::left << item.GetLastName()
			<< std::fixed << std::setw(25) << std::left << item.GetJobRole()
			<< std::fixed << std::setw(20) << std::left << item.GetDepartment()
			<< std::fixed << std::setw(12) << std::left << item.GetSalary()
			<< std::fixed << std::setw(10) << std::left << (item.GetSenior() == true ? "Yes" : "No") << "\n";
		});
}