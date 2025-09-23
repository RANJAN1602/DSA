#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = 10001;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            minPrice = std::min(minPrice, prices[i]);
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};