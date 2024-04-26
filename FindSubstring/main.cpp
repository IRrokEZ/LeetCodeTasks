#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) {
            return -1;
        }
        int result = -1;
        for (size_t i = 0; i < haystack.size(); ++ i) {
            if (haystack[i] == needle[0]) {
                result = i;
                for(size_t j = 0; j < needle.size(); ++ j) {
                    if (haystack[i + j] != needle[j]) {
                        result = -1;
                        break;
                    }
                }
                if (result >= 0) {
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::string str = "sadbutsad", sub = "sad";
    std::cout << std::endl << solution.strStr(str, sub) << std::endl;
    return 0;
}
