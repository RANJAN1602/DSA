#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string currentString, int open, int close, int max) {
        if (currentString.length() == max * 2) {
            result.push_back(currentString);
            return;
        }
        
        if (open < max) {
            backtrack(result, currentString + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(result, currentString + ")", open, close + 1, max);
        }
    }
};