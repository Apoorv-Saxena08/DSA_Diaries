class Solution {
public:
    vector<string>ans ;

    void solve(int&n , int&k , string&temp , int cost , int idx){
        //base case 

        if(temp.size() == n){
            if(cost <= k){
                ans.push_back(temp);
            }
            return;
        }

        //include 0 
        temp.push_back('0');
        solve(n , k , temp  , cost , idx+1);
        temp.pop_back(); 

        //include 1
        if(temp.empty() || temp.back() != '1'){
            temp.push_back('1');
            solve(n, k , temp , cost + idx , idx+1);
            temp.pop_back(); 
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        string temp= "";
        solve(n , k ,temp, 0 , 0);
        return ans;    
    }
};