class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n+1, 0);

        // Count how many papers have each citation count (capped at n)
        for(int i=0; i<n; i++){
            if(citations[i] >= n){
                count[n]++;
            }
            else{
                count[citations[i]]++;
            }
        }

        // Calculate h-index from largest to smallest
        int total = 0;
        for(int h=n; h>=0; h--){
            total += count[h];
            if(total >= h){
                return h;
            }
        }
        return 0;
    }
};