class MyHashMap {
public:
    int size;
    vector<list<pair<int,int>>> buckets;

    MyHashMap() {
        size = 1000;
        buckets.resize(size);
    }
    
    int hash(int key){
        return key % size;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        
        for(auto &p : buckets[index]){
            if(p.first == key){
                p.second = value;
                return;
            }
        }
        
        buckets[index].push_back({key,value});
    }
    
    int get(int key) {
        int index = hash(key);
        
        for(auto &p : buckets[index]){
            if(p.first == key){
                return p.second;
            }
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        
        for(auto it = buckets[index].begin(); it != buckets[index].end(); it++){
            if(it->first == key){
                buckets[index].erase(it);
                return;
            }
        }
    }
};