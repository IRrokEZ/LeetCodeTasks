#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) {
            return {1};
        }
        if (rowIndex == 1) {
            return {1, 1};
        }
        std::vector<int> prev_row = {1, 1};
        std::vector<int> curr_row;
        for (int i = 2; i <= rowIndex; ++ i) {
            curr_row.resize(i + 1);
            curr_row[0] = 1;
            curr_row[i] = 1;
            for (int j = 1; j < i; ++ j) {
                curr_row[j] = prev_row[j - 1] + prev_row[j];
            }
            prev_row = curr_row;
        }
        return curr_row;
    }
};

int main()
{
    return 0;
}
