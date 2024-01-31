class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        map<int, int> prefix;
        map<int, int> suffix;
        vector<int> ans(nums.size());
        for(auto v: nums){
            suffix[v]++;
        }

        for(int i = 0; i < nums.size(); i++){
            prefix[nums[i]]++;
            suffix[nums[i]]--;
            if(suffix[nums[i]] == 0) {
                suffix.erase(nums[i]);
            }
            ans[i] = prefix.size() - suffix.size();
        }
        return ans;
    }
};
