#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> sol;
        for(int i = 1; i <=n ; i++){
            if(i % 3 == 0 && i % 5 == 0) sol.emplace_back("FizzBuzz");
            else if(i % 3 == 0) sol.emplace_back("Fizz");
            else if (i % 5 == 0) sol.emplace_back("Buzz");
            else sol.emplace_back(to_string(i));
        }
        return sol;
    }
};