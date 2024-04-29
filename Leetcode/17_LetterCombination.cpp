#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mappings {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> combinations = {""};

        for (char digit : digits) {
            vector<string> temp;
            for (char c : mappings[digit]) {
                for (string& combination : combinations) {
                    temp.push_back(combination + c);
                }
            }
            combinations = temp;
        }

        return combinations;
    }
};
