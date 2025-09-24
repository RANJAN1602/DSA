#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> bracketStack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                bracketStack.push(c);
            } else {
                if (bracketStack.empty()) {
                    return false;
                }
                char top = bracketStack.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    bracketStack.pop();
                } else {
                    return false;
                }
            }
        }
        return bracketStack.empty();
    }
};