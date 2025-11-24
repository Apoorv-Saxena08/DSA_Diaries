class Solution {
public:
    string simplifyPath(string path) {
        vector<string>words;
        int i = 0, n = path.length();
        while(i < n) {

            if(path[i] == '/') {
                i++;
                continue;
            }

            string temp = "";
            while(i < n && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if(temp.size() > 0)
                words.push_back(temp);
        }
        // for(int i = 0 ; i<words.size();i++){
        //     cout<<words[i]<<" ";
        // }
        stack<string>st;
        for(string &w : words){
            if(w == "." )
                continue;

            else if(w == ".."){
                if(!st.empty())
                    st.pop();
            }

            else{
                st.push(w);
            }
        }

        if(st.empty()) return "/";

        vector<string>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());

        string ans = "";
        for(auto& x : res){
            ans += "/" + x;
        }

        return ans;
    }
};