// Author: Carsten Link
//  println.hpp
//  printline



#ifndef println_hpp
#define println_hpp

/*
 based on: http://stackoverflow.com/questions/16084379/system-out-println-function-syntax-in-c/16085135#16085135
 initial Author: http://stackoverflow.com/users/264338/mkaes
 */

#include <iostream>
#include <iomanip>
#include <sstream>
//using namespace std;




//namespace {

// from: https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
template<typename T>
//std::string to_string_with_precision(const T a_value, const int n = 18)
std::string to_string_with_precision(const T a_value) {
    std::ostringstream out;
    out
            // << std::setprecision(n)
            // << std::setprecision(std::numeric_limits< double >::max_digits10 + 1)
            //<< std::setw(24)
            //<< std::defaultfloat
            //<< std::scientific
            //<< std::fixed
            << a_value;
    return out.str();
}

template<typename T>
std::string as_string(T t) {
    using namespace std;
    return to_string_with_precision(t);
    //return to_string(t);
}


template<>
inline std::string as_string<const char *>(const char *s) {
    return std::string(s);
}

template<>
inline std::string as_string<std::string>(std::string s) {
    return s;
}
//}


inline void println() {
    std::cout << std::endl;
}

template<typename T>
void println(T t) {
    std::cout << as_string(t) << std::endl;
}

template<typename T, typename ...U>
void println(T t, U ...u) {
    std::cout << as_string(t);
    println(u...);
}

template<typename T>
void print(T t) {
    std::cout << as_string(t);
}

template<typename T, typename ...U>
void print(T t, U ...u) {
    std::cout << as_string(t);
    print(u...);
}


#endif /* println_hpp */
