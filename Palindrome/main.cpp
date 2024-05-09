#include <string>

class Solution {
public:
    bool isPalindrome(std::string &s) {
        std::string to_check = "";
        for (char c : s) {
            char sym = tolower(c);
            if (((sym >= 'a') && (sym <= 'z')) || ((sym >= '0') && (sym <= '9'))) {
                to_check += sym;
                continue;
            }
        }
        size_t str_size = to_check.size();
        for (size_t i = 0; i < str_size / 2; ++ i) {
            if (to_check[i] != to_check[str_size - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
