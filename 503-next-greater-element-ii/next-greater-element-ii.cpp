class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(2*n,-1);
        stack<int>st;
        vector<int>temp(arr.begin() , arr.end());
        for(int i = 0 ; i<n;i++){
            temp.push_back(arr[i]);
        }
        for(int i =0 ; i<temp.size()-1;i++){
            if(i==0){
                st.push(i);
            }
            else{
                if((temp[st.top()] >= temp[i])){
                    st.push(i);
                }
                else{
                    int top = temp[i];
                    while(!st.empty() && temp[st.top()] < top ){
                        ans[st.top()] = top;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        vector<int>res;
        for(int i = 0 ; i<n;i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};