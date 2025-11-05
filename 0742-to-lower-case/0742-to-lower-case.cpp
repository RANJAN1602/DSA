#include <string>
#include <cctype> // Required for tolower()

class Solution {
public:
    std::string toLowerCase(std::string s) {
        // Loop by reference (char& c) to modify the string in-place
        for (char& c : s) {
            c = std::tolower(c);
        }
        return s;
    }
};