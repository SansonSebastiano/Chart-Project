#ifndef ENUMRESOLVER_H
#define ENUMRESOLVER_H

#include<string>
#include <map>

template<class T>
class EnumParser{
private:
    std::map<std::string, T> enumMap;
public:
    EnumParser() = default;
    // DA RIVEDERE
    ~EnumParser() = default;

    // DA COMMENTARE
    T string_to_enum(const std::string& value){
        auto it = enumMap.find(value);
        if(it != enumMap.end())
            return it->second;
        else
            throw std::runtime_error("string to enum failed");

    }



    //std::string enum_to_string(const T& value) { }
};

#endif // ENUMRESOLVER_H
