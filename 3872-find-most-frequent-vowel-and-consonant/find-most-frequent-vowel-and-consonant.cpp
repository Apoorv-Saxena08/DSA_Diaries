class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        
        int maxVow = 0;
        int maxCons = 0;

        //vowel 
        for(auto it:mp){
            if(it.first=='a' || it.first=='e'|| it.first=='i'|| it.first=='o'|| it.first=='u'){
                maxVow = max(maxVow,it.second);
            }
        }
        //constants
        for(auto it:mp){
            if(it.first !='a' && it.first !='e' && it.first !='i' && it.first !='o' && it.first !='u'){
                maxCons = max(maxCons,it.second);
            }
        }

        return maxVow + maxCons;
    }
};