#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int lett_counter = 0, save_value = 0;
        for (size_t i = 0; i < s.size(); ++ i) {
            if (s[i] == ' ') {
                if (lett_counter != 0) {
                    save_value = lett_counter;
                }
                lett_counter = 0;
                continue;
            }
            ++ lett_counter;
        }
        if (lett_counter == 0) {
            if (save_value != 0) {
                return save_value;
            }
        }
        return lett_counter;
    }
};

int main()
{
    Solution solution;
    std::string test = "luffy is still joyboy";
    std::cout << std::endl << solution.lengthOfLastWord(test) << std::endl;
    return 0;
}
