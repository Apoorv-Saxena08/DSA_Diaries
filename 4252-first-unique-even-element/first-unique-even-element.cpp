class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        queue<int>q;
        unordered_map<int,int>mp;
        for(auto i : nums){
            mp[i]++;
            if(i%2==0)q.push(i);
        }

        while(!q.empty()){
            int n = q.front();q.pop();
            if(mp[n]==1)return n;
        }
        return -1;
    }
};