#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Use a map to store the number and its index
        std::map<int, int> mpp;
        int n = nums.size();

        // Loop through each number in the vector
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int required_num = target - num;

            // Check if the required number to complete the pair exists in the map
            if (mpp.find(required_num) != mpp.end()) {
                // If it exists, we found the pair.
                // Return the index of the required number and the current index.
                return {mpp[required_num], i};
            }

            // If the pair is not found, add the current number and its index to the map
            // for future checks.
            mpp[num] = i;
        }

        // This line is only reached if no solution is found.
        // The problem statement guarantees a solution exists.
        return {}; 
    }
};