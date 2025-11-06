#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            if (s_to_t.count(char_s)) {
                if (s_to_t[char_s] != char_t) {
                    return false;
                }
            } else {
                if (t_to_s.count(char_t)) {
                    return false;
                }
                s_to_t[char_s] = char_t;
                t_to_s[char_t] = char_s;
            }
        }
        return true;
    }
};