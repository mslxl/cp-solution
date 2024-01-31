class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        if(vector<int>(nums.size(), nums[0]) == nums){
            return 0;
        }
        map<int, int> last_pos;
        map<int, int> fst_pos;
        map<int, int> max_span;

        for(int i = 0; i < nums.size(); i++){
            if(fst_pos.count(nums[i])) {
                max_span[nums[i]] = std::max(i - last_pos[nums[i]] - 1, max_span[nums[i]]);
                last_pos[nums[i]] = i;
            }else{
                fst_pos[nums[i]] = i;
                last_pos[nums[i]] = i;
            }
        }

        for(auto v: nums){
            if(fst_pos[v] != last_pos[v]){
                max_span[v] = std::max(int(fst_pos[v] + nums.size() - last_pos[v] - 1), max_span[v]);
            }
        }

        int minmax_span = nums.size() - 1;
        for(auto [k, v]: max_span){
            minmax_span = std::min(minmax_span, v);
        }
        return (minmax_span + 1)/2;
    }
};
