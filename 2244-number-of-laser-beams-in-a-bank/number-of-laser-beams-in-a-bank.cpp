class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int>count1;
        for(int i = 0 ; i<n ; i++){
            int count = 0;
            for(char ch:bank[i]){
                if(ch == '1'){
                    count++;
                }
            }
            count1.push_back(count);
        }
        int ans = 0 ;
        for(int i =0 ; i<n; i++){
            if(count1[i]!=0){
                int j = i+1 ;
                while(j<n && count1[j]==0)j++;

                if(j<n){
                    ans += count1[i]*count1[j];
                }
            }
        }
        return ans;
    }
};