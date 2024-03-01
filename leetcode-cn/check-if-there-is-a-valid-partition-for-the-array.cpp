class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if(std::vector<int>(nums.size(), nums[0]) == nums) {
            return nums.size() % 3 == 0 || nums.size() % 2 == 0;
        }

        std::vector<std::array<int, 4>> f(nums.size());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                if(i - 2 >= 0){
                    for(int j = 1; j <= 3; j++){
                        if(f[i-2][j] == i - 1){
                            f[i][1] = std::max(f[i][1], f[i-2][j] + 2);
                        }
                    }
                } else {
                    f[1][1] = 2;
                }
            }
            if(i >= 2 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2]){
                if(i - 3 >= 0){
                    for(int j = 1; j <= 3; j++){
                        if(f[i-3][j] == i - 2){
                            f[i][2] = std::max(f[i][2], f[i-3][j] + 3);
                        }
                    }
                } else {
                    f[2][2] = 3;
                }
            }
            if(i >= 2 && nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1){
                if(i - 3 >= 0){
                    for(int j = 1; j <= 3; j++){
                        if(f[i-3][j] == i - 2){
                            f[i][3] = std::max(
                                f[i-3][j] + 3,
                                f[i][3]
                            );
                        }
                    }
                }else{
                    f[2][3] = 3;
                }
            }
        }

        for(int i = 1; i <= 3; i++){
            if(f[nums.size()-1][i] == nums.size()){
                return true;
            }
        }

        return false;
    }
};
