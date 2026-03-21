class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int>cost(n,0);
        for(int i = 0 ; i<n;i++){
            cost[i] = abs(s[i] - t[i]);
        }
        int sum = 0 , l=0;
        int temp = maxCost;
        int len = INT_MIN;
        for(int r = 0 ; r<n;r++){
            sum += cost[r];

            while(l<n && sum > temp){
                sum -= cost[l];
                l++;
            }

            len = max(len, r-l+1);
        }

        return len==INT_MIN? 0:len;
    }
};