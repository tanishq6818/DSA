// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

// Example 1:

// Input
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
// [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
// Output
// [null, null, null, 1, -1, null, 1, null, -1]

// Explanation
// MyHashMap myHashMap = new MyHashMap();
// myHashMap.put(1, 1); // The map is now [[1,1]]
// myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
// myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
// myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
// myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
// myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
// myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
// myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

// Constraints:

// 0 <= key, value <= 106
// At most 104 calls will be made to put, get, and remove.

class MyHashMap {
private:
    vector<pair<int, int>> data;
    
    // Helper function to find the index of a key in the data array.
    int findKey(int key) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i].first == key) {
                return i;
            }
        }
        return -1; // Key not found.
    }
    
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int index = findKey(key);
        if (index == -1) {
            data.push_back({key, value}); // Key not found, add a new pair.
        } else {
            data[index].second = value; // Key found, update the value.
        }
    }
    
    int get(int key) {
        int index = findKey(key);
        return (index == -1) ? -1 : data[index].second;
    }
    
    void remove(int key) {
        int index = findKey(key);
        if (index != -1) {
            data.erase(data.begin() + index);
        }
    }
};
