#include <limits>

class Solution {
public:
    int reverse(int x) {
        long long reversed_num = 0;
        
        while (x != 0) {
            int digit = x % 10;
            reversed_num = reversed_num * 10 + digit;
            x /= 10;
        }
        
        if (reversed_num > std::numeric_limits<int>::max() || reversed_num < std::numeric_limits<int>::min()) {
            return 0;
        }
        
        return static_cast<int>(reversed_num);
    }
};