class Solution {
public:
    int maxProduct(int n) {
        vector<int>d;
        int temp = n;
        while(temp){
            int rem = temp%10;
            d.push_back(rem);
            temp /= 10;
        }
        sort(d.begin() , d.end());
        int m = d.size();
        return d[m-1]*d[m-2];
    }
};