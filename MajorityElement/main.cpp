#include <vector>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int max_id = 0, maxx = 0;
        std::map<int, int> cntr;
        for (int i : nums) {
            ++ cntr[i];
            if (cntr[i] > maxx) {
                ++ maxx;
                max_id = i;
                if (maxx > nums.size() / 2) {
                    return max_id;
                }
            }
        }
        return max_id;
    }
};

int main() {
    return 0;
}
