class RandomizedSet {
public:
    unordered_set <int> set;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) == set.end()){
            set.insert(val);
            return true;
	    }
	    return false;
    }
    
    bool remove(int val) {
        if(set.find(val) != set.end()){
            set.erase(val);
            return true;
        }
	    return false;
    }
    
    int getRandom() {
        int random = rand();
        int sizeOfSet = set.size();
        random %= sizeOfSet;
        int returnNumber = -1;
        for(auto& num:set){
            returnNumber = num;
            if(random-- == 0) break;
        }
        return returnNumber;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */