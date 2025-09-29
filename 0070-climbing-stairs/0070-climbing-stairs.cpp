class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int two_steps_back = 1;
        int one_step_back = 2;
        
        for (int i = 3; i <= n; ++i) {
            int current_ways = one_step_back + two_steps_back;
            two_steps_back = one_step_back;
            one_step_back = current_ways;
        }
        
        return one_step_back;
    }
};