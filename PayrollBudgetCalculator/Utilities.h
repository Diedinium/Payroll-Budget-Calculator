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
namespace util {
	template <typename IteratorT, typename FunctionT>
	FunctionT for_each_iterator(IteratorT first, IteratorT last, int initial, FunctionT func) {
		for (; first != last; ++first, ++initial)
			func(initial, *first);
		return func;
	}

	template <typename T>
	bool find_substring_case_insensitive(const T& strText, const T& strFind) {
		typename T::const_iterator iterator = std::search(
			strText.begin(), strText.end(),
			strFind.begin(), strFind.end(),
			[](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); });
		return (iterator != strText.end());
	}

	template <typename T>
	bool is_less_than(T number, T compare) {
		return number < compare;
	}

	template <typename T>
	bool is_more_than(T number, T compare) {
		return number > compare;
	}

	template <typename T>
	bool is_between(T min, T max, T compare) {
		return compare > min && compare < max;
	}

	template <typename T>
	std::time_t to_time_t(T tp)
	{
		auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(tp - T::clock::now()
			+ std::chrono::system_clock::now());
		return std::chrono::system_clock::to_time_t(sctp);
	}

	void Pause();
	void OutputContractStaffHeader();
	void OutputSalariedStaffHeader();
	void OutputFileListHeader();
	void OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff);
	void OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff);
	void OutputFileList(std::vector<std::filesystem::directory_entry>* ptrVecEntries);
	std::tm GetCurrentDateTimeStruct();
	std::string ConvertFileTimeToString(std::filesystem::file_time_type fileTime);
	std::string GetCurrentDateTimeAsString();
}

#endif // !H_TEMPLATES

