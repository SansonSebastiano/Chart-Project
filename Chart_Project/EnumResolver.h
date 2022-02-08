#ifndef ENUMRESOLVER_H
#define ENUMRESOLVER_H

#include<iostream>

template<class T>
T enum_to_string(std::string input, const std::string names[], const int size){
    for (int i = 0; i < size; i++)
        if (input == names[i])
            return static_cast<T>(i);
    return static_cast<T>(size-1);  // SI DOVREBBE LANCIARE UN ECCEZIONE
}

#endif // ENUMRESOLVER_H
