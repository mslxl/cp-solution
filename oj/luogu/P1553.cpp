#include <iostream>

bool is_all_zero(const std::string &num) {
    for (unsigned int i = 0; i < num.length(); ++i) {
        if (num[i] != '0') {
            return false;
        }
    }
    return true;
}

std::string reversal(const std::string num) {
    if (is_all_zero(num)) {
        // 谁想出的这个数据 mmp
        return "0";
    } else {
        std::string result = num;
        for (unsigned long left_index = 0; left_index < result.length() / 2; ++left_index)
            std::swap(result[left_index], result[result.length() - left_index - 1]);
        while (result[0] == '0')
            result.erase(0, 1);
        while (result[result.length() - 1] == '0')
            result.erase(result.length() - 1, 1);
        return result;

    }
}

int main() {
    std::string line;
    std::cin >> line;
    unsigned long symbol_index;
    if (line[line.length() - 1] == '%') {
        std::cout << reversal(line.substr(0, line.length() - 1)) << "%";
    } else if ((symbol_index = line.find('/')) != std::string::npos ||
               (symbol_index = line.find('.')) != std::string::npos) {
        std::string left = reversal(line.substr(0, symbol_index));
        std::string right = reversal(line.substr(symbol_index + 1));
        std::cout << left << line[symbol_index] << right;
    } else {
        std::cout << reversal(line);
    }
}