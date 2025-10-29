class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0 ;

        for(int i = 0 ;i<n ; i++){
            unordered_set<int> odd,even;
            for(int j = i ; j<n ;j++){
                int val = nums[j];
                if(val%2)odd.insert(val);
                else
                {even.insert(val);};

                if(odd.size() == even.size()){
                    maxi = max(maxi , j-i+1);
                }
            }
        }
        return maxi;
    }
};