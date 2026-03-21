class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>check;//size 2 rhega
        int j = 0 , n = f.size()  , maxi =INT_MIN;

        for(int i = 0 ; i<n;i++){
            check[f[i]]++;

            while(j<n && check.size()>2){
                check[f[j]]--;
                if(check[f[j]] == 0){
                    check.erase(f[j]);
                }
                j++;
            }

            maxi = max(maxi , i-j+1);
        }

        return maxi == INT_MIN? ( (check.size()>0)?n:0 ):maxi;
    }
};