#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        std::string first = strs[0], pref = "";
        bool pref_fin = false;
        for (size_t i = 1; i < strs.size(); ++ i) {
            if ((pref.empty()) && !pref_fin) {
                pref_fin = true;
                for (size_t j = 0; (j < strs[i].size() && j < first.size()); ++ j) {
                    if (first[j] == strs[i][j]) {
                        pref += first[j];
                    } else {
                        break;
                    }
                }
            } else {
                if (strs[i].empty()) {
                    return "";
                }
                size_t j;
                for (j = 0; (j < strs[i].size() && j < pref.size()); ++ j) {
                    if (pref[j] != strs[i][j]) {
                        pref.erase(pref.begin() + j, pref.end());
                        if (pref.empty()) {
                            return "";
                        }
                    }
                }
                if (j < pref.size()) {
                    pref.erase(pref.begin() + j, pref.end());
                }
            }
        }
        return pref;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> task = {"baab","bacb","b","cbc"};
    std::cout << std::endl << "result: '" << solution.longestCommonPrefix(task) << "'" << std::endl;
    return 0;
}
