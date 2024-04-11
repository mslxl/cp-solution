class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    std::stack<int> st;
    std::vector<int> ans(temperatures.size(), 0);
    st.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        ans[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return ans;
  }
};
