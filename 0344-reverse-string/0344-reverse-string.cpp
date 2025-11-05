#include <vector>
#include <algorithm> // Required for std::swap()

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Swap the characters at the left and right pointers
            std::swap(s[left], s[right]);
            
            // Move the pointers toward the center
            left++;
            right--;
        }
    }
};