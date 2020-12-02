#include "Utilities.h"

void util::Pause() {
    std::cout << "Press any key to continue...\n";
    auto value = _getch();
}

void util::OutputContractStaffHeader() {
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << std::left << "Job Role" << std::setw(20) << std::left << "Department" << std::setw(8) << std::left << "Wage" << std::setw(12) << std::left << "Hours p/w" << std::setw(10) << std::left << "Contracted" << "\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
}

void util::OutputSalariedStaffHeader() {
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
    std::cout << std::setw(4) << std::left << "Num" << std::setw(15) << std::left << "First Name" << std::setw(15) << std::left << "Last Name" << std::setw(25) << "Job Role" << std::setw(20) << "Department" << std::setw(12) << "Salary" << std::setw(5) << "Senior?" << "\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------\n";
}

/// <summary>
/// Outputs a header for a table displaying list of current files in the saves directory.
/// </summary>
void util::OutputFileListHeader() {
	std::cout << "------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(4) << std::left << "Num" << std::setw(25) << std::left << "Date created" << std::setw(50) << std::left << "File name" << "\n";
	std::cout << "------------------------------------------------------------------------------------------------------\n";
}

void util::OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff) {
	util::for_each_iterator(ptrVecContractStaff->begin(), ptrVecContractStaff->end(), 0, [](int index, ContractStaff& item) {
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(4) << std::left << index
			<< std::setw(15) << std::left << item.GetFirstName()
			<< std::setw(15) << std::left << item.GetLastName()
			<< std::setw(25) << std::left << item.GetJobRole()
			<< std::setw(20) << std::left << item.GetDepartment()
			<< std::setw(8) << std::left << item.GetWage()
			<< std::setw(12) << std::left << item.GetWeeklyHours()
			<< std::setw(10) << std::left << item.GetWeeksFormatted() << "\n";
		});
}

void util::OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff) {
	util::for_each_iterator(ptrVecSalariedStaff->begin(), ptrVecSalariedStaff->end(), (long)0, [](int index, SalariedStaff& item) {
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::setw(4) << std::left << index
			<< std::setw(15) << std::left << item.GetFirstName()
			<< std::setw(15) << std::left << item.GetLastName()
			<< std::setw(25) << std::left << item.GetJobRole()
			<< std::setw(20) << std::left << item.GetDepartment()
			<< std::setw(12) << std::left << item.GetSalary()
			<< std::setw(10) << std::left << (item.GetSenior() == true ? "Yes" : "No") << "\n";
		});
}

/// <summary>
/// Outputs list of files that are in the passed Entries vector
/// </summary>
/// <param name="ptrVecEntries"></param>
void util::OutputFileList(std::vector<std::filesystem::directory_entry>* ptrVecEntries) {
	util::for_each_iterator(ptrVecEntries->begin(), ptrVecEntries->end(), 0, [](int index, std::filesystem::directory_entry& entry) {
		std::cout.precision(2);
		std::cout
			<< std::fixed << std::left << std::setw(4) << index
			<< std::setw(25) << convertFileTimeToString(entry.last_write_time())
			<< std::setw(50) << entry.path().filename() << "\n";
		});
}

/// <summary>
/// Gets the current datetime in the time struct, which can then be output using std::put_time
/// </summary>
/// <returns>struct std::tm</returns>
std::tm util::GetCurrentDateTimeStruct() {
	// Why is getting the current date in C++ such a damn pain? Seriouly, I spent half an hour figuring out how to make this work!
	std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct std::tm tm;
	localtime_s(&tm, &date);
	return tm;
}

/// <summary>
/// Takes fileTime and returns as string of ISO date and 12 hour time
/// </summary>
/// <param name="fileTime"></param>
/// <returns></returns>
std::string util::convertFileTimeToString(std::filesystem::file_time_type fileTime) {
	std::time_t tt = to_time_t(fileTime);
	std::tm time;
	localtime_s(&time, &tt);
	std::stringstream ssBuffer;
	ssBuffer << std::put_time(&time, "%F %I:%M %p");
	return ssBuffer.str();
}