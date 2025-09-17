class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        if(n==0)return 0;

        //int mini = min(m,n);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int count = 0;
        int i=0 , j=0;
        while(i<m && j<n){
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                //check next cookie
                j++;
            }
        }
        return count;
    }
};