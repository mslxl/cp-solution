class Solution {
public:
    std::vector<std::set<int>> mutal_pri;
    std::vector<std::vector<int>> g;

    void dfs(std::vector<int>& nums, std::vector<int>& fa, int x,
             std::vector<int>& ans, int dfs_fa) {
        int cur_num = nums[x];

        ans[x] = fa[cur_num];

        std::vector<int> fa_rt(fa.begin(), fa.end());

        for(auto pri: mutal_pri[cur_num]){
            fa_rt[pri] = x;
        }

        for (auto child : g[x]) {
            if(child == dfs_fa) continue;
            dfs(nums, fa_rt, child, ans, x);
        }
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {

        g.resize(nums.size());
        mutal_pri.resize(51);
        for (auto v : edges){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }

        std::vector<int> uniq_nums = nums;
        std::sort(uniq_nums.begin(), uniq_nums.end());
        auto uniq_size =
            std::unique(uniq_nums.begin(), uniq_nums.end()) - uniq_nums.begin();

        for (int i = 0; i < uniq_size; i++) {
            for (int j = 0; j <= i; j++) {
                if (std::gcd(uniq_nums[i], uniq_nums[j]) == 1) {
                    mutal_pri[uniq_nums[i]].insert(uniq_nums[j]);
                    mutal_pri[uniq_nums[j]].insert(uniq_nums[i]);
                }
            }
        }

        std::vector<int> fa(51, -1);
        std::vector<int> ans(nums.size(), -1);
        dfs(nums, fa, 0, ans, -1);
        return ans;
    }
};
