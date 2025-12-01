class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        sort(b.begin(),b.end());
        long long total = accumulate(b.begin(),b.end(),0LL);
        for(int i = b.size()-1;i>=0;i--){
            if(b[i] <= total/n)break;
            total -= b[i];
            n--;
        }
        return total/n;
    }
};