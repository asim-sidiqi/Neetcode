class MyHashSet {
public:
    vector<vector<int>> arr;
    int size = 15000;

    MyHashSet() {
        arr.resize(size);
    }
    
    void add(int key) {
        if(!contains(key)){
            int idx = key%size;
            arr[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        if(contains(key)){
            int idx = key%size;
            for(int i=0; i<arr[idx].size(); i++){
                if(arr[idx][i]==key){
                    arr[idx].erase(arr[idx].begin()+i);
                    //return;
                }
            }
        }
    }
    
    bool contains(int key) {
        int idx = key%size;
        for(int it:arr[idx]){
            if(it==key) return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */