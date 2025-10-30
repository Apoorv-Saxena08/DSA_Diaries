class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.length();
        unordered_map<char , int>mp;
        for(char c:s){
            mp[c]++;
        }
        vector<int>freq;
        int totalD = 0;
        for(auto it:mp){
            totalD++;
            freq.push_back(it.second);
        }
        if(totalD <= k)return 0;

        sort(freq.begin(),freq.end(),greater<int>());
        int ans = 0;
        for(int i = k;i<freq.size();i++){
            ans += freq[i];
        }
        return ans;
    }
};