#ifndef CASTHELPER_H
#define CASTHELPER_H

#include <iostream>

template<class T>
T string_to_enum(std::string input, const std::string names[], const int size) {
    for (int i = 0; i < size; i++)
        if (input == names[i])
            return static_cast<T>(i);
    return static_cast<T>(size-1);  // SI DOVREBBE LANCIARE UN ECCEZIONE
}

std::string enum_to_string(const std::string names[], int value){ return names[value]; }

uint str_to_uint(std::string input){ return std::stoul(input, nullptr, 0); }

#endif // CASTHELPER_H
