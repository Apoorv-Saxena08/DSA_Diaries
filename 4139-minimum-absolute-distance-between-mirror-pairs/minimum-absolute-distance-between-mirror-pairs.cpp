class Solution {
public:
    int reverse(int x){
        long long rev = 0;
        while(x>0){
            rev = rev*10 + x%10;
            x /= 10;
        }
        return (int)rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = INT_MAX;
        
        for(int i = 0 ; i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans , i - mp[nums[i]]);
            }
            mp[reverse(nums[i])] = i;
        }
        return ans == INT_MAX?-1:ans;
    }
};