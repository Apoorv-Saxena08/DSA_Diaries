class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        int jumbo = (t-2*c)/2;
        int small = c - jumbo;
        if( jumbo<0 || small < 0 || (2*jumbo) != (t-2*c)  ){
            return {};
        }
        return {jumbo, small}; 
    }
};