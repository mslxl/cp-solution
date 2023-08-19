#include <iostream>
#include <vector>
#include <string>

std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> numerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    std::string result = "";
    for (const auto& numeral : numerals) {
        while (num >= numeral.first) {
            result += numeral.second;
            num -= numeral.first;
        }
    }
    
    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    std::string romanNumeral = intToRoman(n);
    std::cout << romanNumeral << std::endl;
    
    return 0;
}