class LRUCache {
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }

        auto it = mp[key];
        int value = it->second;

        lru.erase(it);
        lru.push_front({key,value});
        mp[key] = lru.begin();

        return value;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            lru.erase(mp[key]);
        } else if (lru.size() == cap) {
            int oldKey = lru.back().first;
            lru.pop_back();
            mp.erase(oldKey);
        }

        lru.push_front({key, value});
        mp[key] = lru.begin();
    }
};
