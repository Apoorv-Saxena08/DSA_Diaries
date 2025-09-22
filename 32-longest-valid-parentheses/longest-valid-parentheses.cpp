class Solution {
public:
    int longestValidParentheses(string s) {
        //indexes store krenge to get longetst string 
        // agr we get ( to push index 
        //else pop kro -> agr st empty ho gya to index push agr nhi hua to calculate lentgh
        stack<int> st;
        st.push(-1);
        int maxi = 0 ;
        for(int i= 0 ; i< s.length() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxi = max(maxi , i-st.top());
                }
            }
        }
        return maxi;
    }
};