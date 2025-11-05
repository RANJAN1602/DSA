#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // 1. Quick length check
        if (s.length() != t.length()) {
            return false;
        }

        // 2. Create a frequency map for 26 lowercase letters
        // (Initialized to all zeros)
        std::vector<int> counts(26, 0);

        // 3. Loop through both strings at the same time
        for (int i = 0; i < s.length(); ++i) {
            // Increment count for the character in 's'
            counts[s[i] - 'a']++;
            
            // Decrement count for the character in 't'
            counts[t[i] - 'a']--;
        }

        // 4. Check if all counts are zero
        // If they are anagrams, every increment
        // should have been cancelled by a decrement.
        for (int count : counts) {
            if (count != 0) {
                // Found a mismatch
                return false;
            }
        }

        // 5. If we get here, all counts were zero
        return true;
    }
};