#pragma once

#include <algorithm>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
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

	void Pause();
	void OutputContractStaffHeader();
	void OutputSalariedStaffHeader();
	void OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff);
	void OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff);
	std::tm GetCurrentDateTimeStruct();
}

#endif // !H_TEMPLATES

