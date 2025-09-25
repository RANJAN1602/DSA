#include <vector>
#include <numeric>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        long long expected_sum = (long long)n * (n + 1) / 2;

        long long actual_sum = 0;
        for (int num : nums) {
            actual_sum += num;
        }

        return expected_sum - actual_sum;
    }
};