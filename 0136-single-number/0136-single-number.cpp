#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }
        
        for (auto const& [key, val] : counts) {
            if (val == 1) {
                return key;
            }
        }
        return 0;
    }
};