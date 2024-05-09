#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber > 0) {
            columnNumber--;
            char c = 'A' + columnNumber % 26;
            result = c + result;
            columnNumber /= 26;
        }
        return result;
    }
};

int main() {
    return 0;
}
