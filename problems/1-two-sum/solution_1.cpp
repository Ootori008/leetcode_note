#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res {0, 0};
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            auto j = um.find(nums[i]);
            if (j != um.end()) {
                res[0] = j->second;
                res[1] = i;
                break;
            }
            um[target - nums[i]] = i;
        }
        return res;
    }
};
