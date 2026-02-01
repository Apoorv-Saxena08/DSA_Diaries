class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i =0 , n = words.size();
        vector<string>ans;
        while(i<n){
            int j = i , letters = 0;
            while(j<n && letters + words[j].size() +(j-i) <= maxWidth){
                letters += words[j].size();
                j++;
            }

            int spaces = maxWidth - letters;
            int gaps = j-i-1;
            string line = "";

            //if last lineo or 1 word lefy
            if(j == n || gaps==0){
                for(int k = i ; k<j ; k++){
                    line += words[k];
                    if(k<j-1){
                        line += " ";
                    }
                }
                while(line.size() < maxWidth){
                    line += " ";
                }
            }
            else{
                //full justify
                int spaceEach = spaces/gaps;
                int extra = spaces%gaps;

                for(int k = i ; k<j ; k++){
                    line += words[k];
                    if(k<j-1){
                        line += string(spaceEach + (extra-- >0) , ' ' );
                    }
                }
            }
            ans.push_back(line);
            i=j;
        }
        return ans;
    }
};