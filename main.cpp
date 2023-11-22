#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // 1. Two Sum
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numMap;
        int n = nums.size();

        // Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        for(size_t i; i != numMap.size(); ++i){
            cout<< numMap[nums[i]] << " ";
        }
    }
};

int main(){
    Solution S;
    vector<int> nums;

    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    S.twoSum(nums, 9);
}