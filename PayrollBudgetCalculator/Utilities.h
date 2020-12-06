#pragma once

#include <iostream>
#include <algorithm>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <filesystem>
#include <sstream>
#include "Staff.h"

#ifndef H_TEMPLATES
#define H_TEMPLATES
/// <summary>
/// Namespace to store various utility functions/templates.
/// </summary>
namespace util {
	/// <summary>
	/// Template that performs a foreach operation on the provided iterable type (vectors), and provides an index.
	/// </summary>
	/// <typeparam name="IteratorT"></typeparam>
	/// <typeparam name="FunctionT"></typeparam>
	/// <param name="first"></param>
	/// <param name="last"></param>
	/// <param name="initial"></param>
	/// <param name="func"></param>
	/// <returns>FunctionT</returns>
	template <typename IteratorT, typename FunctionT>
	FunctionT for_each_iterator(IteratorT first, IteratorT last, int initial, FunctionT func) {
		for (; first != last; ++first, ++initial)
			func(initial, *first);
		return func;
	}

	/// <summary>
	/// Returns true/false on if a substring was found in provided strText. Evaulates in a case insensitive way.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="strText"></param>
	/// <param name="strFind"></param>
	/// <returns>bool</returns>
	template <typename T>
	bool find_substring_case_insensitive(const T& strText, const T& strFind) {
		typename T::const_iterator iterator = std::search(
			strText.begin(), strText.end(),
			strFind.begin(), strFind.end(),
			[](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); });
		return (iterator != strText.end());
	}

	/// <summary>
	/// Returns true/false on if number is less than compare.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="number"></param>
	/// <param name="compare"></param>
	/// <returns>bool</returns>
	template <typename T>
	bool is_less_than(T number, T compare) {
		return number < compare;
	}

	/// <summary>
	/// Returns true/false on if number is more than compare.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="number"></param>
	/// <param name="compare"></param>
	/// <returns>bool</returns>
	template <typename T>
	bool is_more_than(T number, T compare) {
		return number > compare;
	}

	/// <summary>
	/// Returns true/false on if compare is between min and max.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="min"></param>
	/// <param name="max"></param>
	/// <param name="compare"></param>
	/// <returns></returns>
	template <typename T>
	bool is_between(T min, T max, T compare) {
		return compare > min && compare < max;
	}

	/// <summary>
	/// Converts _File_System_Clock current time to time_t.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="tp"></param>
	/// <returns>std::time_t</returns>
	template <typename T>
	std::time_t to_time_t(T tp)
	{
		auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(tp - T::clock::now()
			+ std::chrono::system_clock::now());
		return std::chrono::system_clock::to_time_t(sctp);
	}

	/// <summary>
	/// Call to pause execution of program.
	/// </summary>
	void Pause();

	/// <summary>
	/// Outputs table format header for contract staff members.
	/// </summary>
	void OutputContractStaffHeader();

	/// <summary>
	/// Outputs table format header for salaried staff members
	/// </summary>
	void OutputSalariedStaffHeader();

	/// <summary>
	/// Outputs a header for a table displaying list of current files in the saves directory.
	/// </summary>
	void OutputFileListHeader();

	/// <summary>
	/// Outputs table format list of contract staff members
	/// </summary>
	/// <param name="ptrVecContractStaff"></param>
	void OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff);

	/// <summary>
	/// Outputs table format list of salaried staff members.
	/// </summary>
	/// <param name="ptrVecSalariedStaff"></param>
	void OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff);

	/// <summary>
	/// Outputs list of files that are in the passed Entries vector
	/// </summary>
	/// <param name="ptrVecEntries"></param>
	void OutputFileList(std::vector<std::filesystem::directory_entry>* ptrVecEntries);

	/// <summary>
	/// Gets the current datetime in the time struct, which can then be output using std::put_time
	/// </summary>
	/// <returns>struct std::tm</returns>
	std::tm GetCurrentDateTimeStruct();

	/// <summary>
	/// Returns the current date and time in a file safe string format.
	/// </summary>
	/// <returns>std::string</returns>
	std::string ConvertFileTimeToString(std::filesystem::file_time_type fileTime);

	/// <summary>
	/// Takes fileTime and returns as string of ISO date and 12 hour time
	/// </summary>
	/// <param name="fileTime"></param>
	/// <returns></returns>
	std::string GetCurrentDateTimeAsString();
}

#endif // !H_TEMPLATES

