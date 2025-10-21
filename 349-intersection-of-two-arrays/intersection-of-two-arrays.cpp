class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>a;
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        for(int i = 0  ; i <nums1.size() ; i++){
            for(int j = 0 ; j<nums2.size();j++){
                if(nums1[i]==nums2[j])a.insert(nums1[i]);
            }
        }
        vector<int>ans(a.begin(),a.end());
        return ans;
    }
};