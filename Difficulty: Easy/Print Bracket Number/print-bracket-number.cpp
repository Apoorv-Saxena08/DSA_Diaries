// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        vector<int>ans;
        int count = 0 ;
        stack<int>st;
        int n = str.length();
        for(int i =0 ; i<n ; i++){
            if(str[i] == '('){
                count++;
                st.push(count);
                ans.push_back(count);
            }
            else if(str[i] == ')'){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};