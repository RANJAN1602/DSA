#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for (int i = 1; i <= n; ++i) {
            bool divBy3 = (i % 3 == 0);
            bool divBy5 = (i % 5 == 0);
            
            if (divBy3 && divBy5) {
                result[i - 1] = "FizzBuzz";
            } else if (divBy3) {
                result[i - 1] = "Fizz";
            } else if (divBy5) {
                result[i - 1] = "Buzz";
            } else {
                result[i - 1] = to_string(i);
            }
        }
        return result;
    }
};