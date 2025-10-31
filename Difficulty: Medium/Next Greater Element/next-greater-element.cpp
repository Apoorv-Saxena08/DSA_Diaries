class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,-1);
        
        stack<int>st;
        for(int i =0 ; i<n;i++){
            if(i==0){
                st.push(i);
            }
            else{
                if(arr[i] <= arr[st.top()]){
                    st.push(i);
                }
                else{
                    int top = arr[i];
                    while(!st.empty() && (arr[st.top()] < top )){
                        ans[st.top()] = top;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return ans;
    }
};