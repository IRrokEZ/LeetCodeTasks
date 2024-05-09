#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }
        if (numRows == 2) {
            return {{1}, {1, 1}};
        }
        std::vector<std::vector<int>> result = {{1}, {1, 1}};
        for (int i = 2; i < numRows; ++ i) {
            std::vector<int> str(i + 1);
            str[0] = 1;
            str[i] = 1;
            for (int j = 1; j < i; ++ j) {
                str[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(str);
        }
        return result;
    }
};

int main()
{
    return 0;
}
