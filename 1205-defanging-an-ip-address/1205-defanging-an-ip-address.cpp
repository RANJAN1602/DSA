#include <string>

class Solution {
public:
    std::string defangIPaddr(std::string address) {
        std::string result = "";
        // Loop through each character 'c' in the 'address' string
        for (char c : address) {
            if (c == '.') {
                // If the character is a period, append "[.]"
                result += "[.]";
            } else {
                // Otherwise, append the character itself
                result += c;
            }
        }
        return result;
    }
};