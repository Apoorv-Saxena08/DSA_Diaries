// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        int n = arr.size();
        stack<int>st;
                for (int x : arr) {
            if (!st.empty()) {
                int top = st.top();
                if ((top >= 0 && x < 0) || (top < 0 && x >= 0)) {
                    st.pop();
                    continue;
                }
            }
            st.push(x);
        }

        while(!st.empty()){
            int top = st.top();
            ans.push_back(top);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};