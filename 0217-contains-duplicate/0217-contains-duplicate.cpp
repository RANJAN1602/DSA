#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seenNumbers;
        for (int num : nums) {
            if (seenNumbers.count(num)) {
                return true;
            }
            seenNumbers.insert(num);
        }
        return false;
    }
};