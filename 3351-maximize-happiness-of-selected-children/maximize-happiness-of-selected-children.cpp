class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        sort(happiness.begin(),happiness.end());

        long long ans=0;
        int idx=happiness.size()-1;
        long long diff=0;

        while(k--){
            if((happiness[idx]-diff)>0){
                ans+=happiness[idx]-diff;
                idx--;
                diff++;
            }else{
                break;
            }
        }
        return ans;
    }
};