class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }

        priority_queue< pair<int,char> > pq;
        for(auto it : mp){
            pq.push({it.second , it.first}); //{freq , char}
        } 

        string str = "";

        while(pq.size()>=2){
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            
            if(t1.first>0){
                str += t1.second;
                t1.first--;
                if(t1.first != 0){
                    pq.push(t1);
                }
            }

            if(t2.first>0){
                str += t2.second;
                t2.first--;
                if(t2.first != 0){
                    pq.push(t2);
                }
            }

        }

        if(!pq.empty()){
            if(pq.top().first >1){
                return "";
            }else{
                str += pq.top().second;
            }
        }

        return str;
    }
};