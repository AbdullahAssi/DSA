#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(),nums.end()).size();
    }
};


//or

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool flag = false;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] ==  nums[j]){
                    return true;
                }
            }
        }
        return flag;
    }
};