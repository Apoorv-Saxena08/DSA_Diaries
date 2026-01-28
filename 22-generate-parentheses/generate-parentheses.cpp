class Solution {
public:
    void solve(vector<string>&ans,int n ,string &temp, int left , int right){
        if(left + right == 2*n){
            ans.push_back(temp);//string daldo
            return;
        }

        //starting hmesha ( se hogi yani left
        if(left<n){
            temp.push_back('(');
            solve(ans,n,temp,left+1,right);
            temp.pop_back();
        }

        //end hmesha ( se hogi yani left
        if(right<left){
            temp.push_back(')');
            solve(ans,n,temp,left,right+1);
            temp.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(ans,n,temp,0,0);
        return ans;
    }
};