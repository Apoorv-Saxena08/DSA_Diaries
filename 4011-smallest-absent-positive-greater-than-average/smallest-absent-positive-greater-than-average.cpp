class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int  sum = 0 ;
        double avg;
        unordered_set<int>s;
        for(int n : nums){
            sum+= n;
            s.insert(n);
        }
        avg = (double) sum/nums.size();
        int x = floor(avg)+1;
        if(x<=0) x = 1;

        while(s.count(x)){
            x++;
        }
        return x;
    }
};