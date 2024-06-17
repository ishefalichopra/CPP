#include<bits/stdc++.h>
using namespace std;

//Valid Number
 bool isNumber(string s) {
      const std::regex pattern(R"(^[+-]?((\d+(\.\d*)?)|(\.\d+))([eE][+-]?\d+)?$)");

    // Return whether the string matches the regular expression
    return std::regex_match(s, pattern);  
    }


int main() {
    // Test cases
    std::string validNumbers[] = {"0", "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
    std::string invalidNumbers[] = {"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "e", ".", "1e"};

    std::cout << "Valid numbers:" << std::endl;
    for (const auto& num : validNumbers) {
        std::cout << "\"" << num << "\" -> " << (isNumber(num) ? "true" : "false") << std::endl;
    }

    std::cout << "\nInvalid numbers:" << std::endl;
    for (const auto& num : invalidNumbers) {
        std::cout << "\"" << num << "\" -> " << (isNumber(num) ? "true" : "false") << std::endl;
    }

    return 0;
}