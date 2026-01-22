class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin() , folder.end());
        // for(string i : folder){
        //     cout<<i<<" ";
        // }
        vector<string>ans;
        ans.push_back(folder[0]);
        //cout<<ans.back();
        int m = 0 ,  n = 0;
        for(int i = 1 ;i<folder.size();i++ ){
            m = ans.back().length();
            n = folder[i].length();
            int idx1 = 0 ;
            int mini = min(m,n);
            while(idx1<mini && ans.back()[idx1] == folder[i][idx1] ){
                idx1++;
            }
            if(idx1==mini){
                //get check for /
                if(idx1<n && folder[i][idx1]=='/'){
                    continue;
                }
                else{
                    ans.push_back(folder[i]);
                }
                
            }
            
            else{
                ans.push_back(folder[i]);
            }
        }

        

        return ans;
    }
};