#pragma once

#include <algorithm>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <vector>
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

    void Pause();
    void OutputContractStaffHeader();
    void OutputSalariedStaffHeader();
    void OutputContractStaff(std::vector<ContractStaff>* ptrVecContractStaff);
    void OutputSalariedStaff(std::vector<SalariedStaff>* ptrVecSalariedStaff);
}

#endif // !H_TEMPLATES

