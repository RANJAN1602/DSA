class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                ans = mid; // Potential answer mil gaya
                if (isFirst) {
                    high = mid - 1; // Left mein aur dhoondho
                } else {
                    low = mid + 1; // Right mein aur dhoondho
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
    }
};