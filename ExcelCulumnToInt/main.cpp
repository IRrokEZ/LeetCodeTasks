#include <string>
#include <iostream>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        long int result = 0, multer = 1;
        std::reverse(columnTitle.begin(), columnTitle.end());
        for (const char c : columnTitle) {
            if (c == 'A') {
                result += 1 * multer;
            } else {
                result += int(c - 'A' + 1) * multer;
            }
            multer *= 26;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    std::cout << solution.titleToNumber("ABCDE") << std::endl;
    return 0;
}
