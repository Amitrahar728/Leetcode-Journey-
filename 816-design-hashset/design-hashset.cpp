class MyHashSet {
public:
        unordered_set<int> ust;
    MyHashSet() {
    }
    
    void add(int key) {
        ust.insert(key);
    }
    
    void remove(int key) {
        ust.erase(key);
    }
    
    bool contains(int key) {
        if(ust.find(key) == ust.end()){
            return false;
        }
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */