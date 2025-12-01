class Solution {
public:
    int reverseNum(int x){
        long long rev = 0;
        while(x>0){
            rev = (rev*10) + (x%10);
            x /= 10;
        }

        return (int)rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;//value , index

        int ans = INT_MAX;
        for(int i = 0 ;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        for(int i = 0 ;i<n;i++){
            int rev = reverseNum(nums[i]);

            if(mp.count(rev)){
                //mil gya 
                //find upper bound
                const vector<int>& vec = mp[rev];
                auto it = upper_bound(vec.begin(), vec.end(), i);

                if(it != vec.end()){
                    int j = *it;
                    ans = min(ans , j-i);
                }
            }
        }

        return ans == INT_MAX?-1:ans;
    }
};