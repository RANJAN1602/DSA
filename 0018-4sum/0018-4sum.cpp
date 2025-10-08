#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        int last_left = nums[left];
                        while (left < right && nums[left] == last_left) {
                            left++;
                        }
                        
                        int last_right = nums[right];
                        while (left < right && nums[right] == last_right) {
                            right--;
                        }
                    } else if (current_sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
};