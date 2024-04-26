#include <iostream>
#include <string>
#include <map>
#include <set>
#include <deque>

class Solution {
public:
    bool isValid(std::string s) {
        std::deque<char> brackets;
        std::map<char, char> brackets_pairs;
        brackets_pairs['}'] = '{';
        brackets_pairs[']'] = '[';
        brackets_pairs[')'] = '(';
        std::set<char> open_brackets {'(', '[', '{'}, close_brackets {')', ']', '}'};
        for (size_t i = 0; i < s.size(); ++ i) {
            if (open_brackets.count(s[i])) {
                brackets.push_back(s[i]);
            } else if (close_brackets.count(s[i])) {
                if (brackets.empty() || (brackets.back() != brackets_pairs[s[i]])) {
                    return false;
                } else {
                    brackets.pop_back();
                }
            }
        }
        return brackets.empty();
    }
};

int main()
{
    Solution solution;
    std::string test = "(}{))([][]";
    std::cout << std::endl << "result: '" << solution.isValid(test) << "'" << std::endl;
    return 0;
}
