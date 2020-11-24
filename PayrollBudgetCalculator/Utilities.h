#pragma once

#include <algorithm>
#include <conio.h>
#include <iostream>

#ifndef H_TEMPLATES
#define H_TEMPLATES
namespace util {
    template <typename IteratorT, typename FunctionT>
    FunctionT for_each_iterator(IteratorT first, IteratorT last, typename std::iterator_traits<IteratorT>::difference_type initial, FunctionT func) {
        for (; first != last; ++first, ++initial)
            func(initial, *first);
        return func;
    }

    void Pause() {
        std::cout << "Press any key to continue...\n";
        _getch();
    }
}

#endif // !H_TEMPLATES

