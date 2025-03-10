class RandomizedSet {
private:
    vector<int> list;
    unordered_map<int, int> map;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = list.size();
        list.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        int index = map[val];
        int lastElement = list.back();
        list[index] = lastElement;
        map[lastElement] = index;
        list.pop_back();
        map.erase(val);
        return true;
    }

    int getRandom() {
        return list[rand() % list.size()];
    }
};

// /**
//  * Your RandomizedSet object will be instantiated and called as such:
//  * RandomizedSet* obj = new RandomizedSet();
//  * bool param_1 = obj->insert(val);
//  * bool param_2 = obj->remove(val);
//  * int param_3 = obj->getRandom();
//  */