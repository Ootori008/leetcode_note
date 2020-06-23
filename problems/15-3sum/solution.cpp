#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Can solve problem, but exceed time limit.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // make a hash table of two sum
        std::sort(nums.begin(), nums.end());
        unordered_map<int, vector<vector<int>>> um;
        vector<vector<int>> res;
        for (int i = 0; i < (nums.size() - 1); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                um[(nums[i] + nums[j])].push_back(vector<int> {i, j});
                // cout << (nums[i] + nums[j]) << ";" << i << ";" << j << endl;
            }
        }
        // check 3sum
        for (int i = 0; i < (nums.size() -2); i++) {
            auto um_res = um.find(0 - nums[i]);
            if (um_res != um.end()) {
                auto two_sum_array = um_res->second;
                for (int n = 0; n < two_sum_array.size(); n++) {
                    if (i < two_sum_array[n][0]) {
                        res.push_back(vector<int> {nums[i], nums[two_sum_array[n][0]], nums[two_sum_array[n][1]]});
                    }
                }
            } 
        }
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};