#ifndef HELPER_H
#define HELPER_H

#include <iostream>

namespace helper {
    /*
     * @brief   converte un intero positivo in input nel corrispondente valore dell'enumerazione T
     * @param   unsigned int
     * @return  T
     */
    template<class T>
    T uint_to_enum(unsigned int value) { return static_cast<T>(value); }
    /*
     * @brief   converte una stringa in input in un intero positivo
     * @param   string
     * @return  unsigned int
     */
    uint str_to_uint(std::string input){ return std::stoul(input, nullptr, 0); }
}

#endif // HELPER_H
