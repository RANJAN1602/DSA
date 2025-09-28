#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create a hash map to store numbers we've seen and their indices.
        // Key: number, Value: index
        std::unordered_map<int, int> num_map;

        // Iterate through the vector once.
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed for the current number.
            int complement = target - nums[i];

            // Check if the complement exists in our map.
            // .count() is a fast way to check for key existence.
            if (num_map.count(complement)) {
                // If it exists, we found our pair.
                // Return the complement's index and the current index.
                return {num_map[complement], i};
            }

            // If complement is not found, add the current number and its index to the map
            // for future lookups.
            num_map[nums[i]] = i;
        }

        // The problem statement guarantees a solution exists, so this part is
        // technically not reached. It's good practice for function completeness.
        return {};
    }
};
        