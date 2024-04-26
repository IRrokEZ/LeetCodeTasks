#include <iostream>
#include <string>

class Solution {
public:
    int convertSymbToInt(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    int romanToInt(std::string s) {
        int rez = 0;
        for (size_t i = 0; i < s.size(); ++ i) {
            int a = convertSymbToInt(s[i]), b;
            if(i + 1 >= s.size()) {
                b = -1;
            } else {
                b = convertSymbToInt(s[i + 1]);
            }
            if (a < b) {
                rez += b - a;
                ++ i;
            } else {
                rez += a;
            }
        }
        return rez;
    }
};

int main () {
    Solution solution;
    std::cout << std::endl << solution.romanToInt("MCMXCIV") << std::endl;
    return 0;
}
