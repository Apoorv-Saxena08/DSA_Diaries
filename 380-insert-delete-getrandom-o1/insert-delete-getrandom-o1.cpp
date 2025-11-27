class RandomizedSet {
public:
    unordered_set<int>s;
    RandomizedSet() {
        s.reserve(200000);
    }
    
    bool insert(int val) {
        if(s.count(val))return false;

        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)){
            s.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx = rand()%s.size();
        for(int x : s){
            if(idx-- == 0){
                return x;
            }
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */