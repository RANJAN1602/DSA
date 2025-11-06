#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            
            if (charIndexMap.count(c) && charIndexMap[c] >= left) {
                left = charIndexMap[c] + 1;
            }
            
            charIndexMap[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};