#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int currentSum = 0;
        unordered_map<int, int> prefixSumCount;
        
        prefixSumCount[0] = 1;
        
        for (int num : nums) {
            currentSum += num;
            int complement = currentSum - k;
            
            if (prefixSumCount.count(complement)) {
                count += prefixSumCount[complement];
            }
            
            prefixSumCount[currentSum]++;
        }
        
        return count;
    }
};