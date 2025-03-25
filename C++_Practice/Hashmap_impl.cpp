#include <iostream>
#include <vector>
#include <list>

class hashmap {
    int size = 10000;
    std::vector<std::list<std::pair<int,int>>> bucket;
public:
    hashmap()
    {
        bucket.resize(size);
        std::cout << "Hashmap created" << std::endl;
    }
    
    void put(int key, int value)
    {
        int idx = key % size;
        auto &list = bucket[idx];
        
        // Check if key already exists
        for(auto it = list.begin(); it != list.end(); ++it)
        {
            if(it->first == key)
            {
                it->second = value;
                return;
            }
        }
        
        // If key doesn't exist, add new key-value pair
        list.push_back({key, value});
    }
    
    int get(int key)
    {
        int idx = key % size;
        auto &list = bucket[idx];
        
        for(auto &it : list)
        {
            if(it.first == key)
            {
                return it.second;
            }
        }
        
        return -1;
    }
    
    void remove(int key)
    {
        int idx = key % size;
        auto &list = bucket[idx];
        
        for(auto it = list.begin(); it != list.end(); ++it)
        {
            if(it->first == key)
            {
                list.erase(it);
                return;
            }
        }
    }
    
    ~hashmap()
    {
        std::cout << "Hashmap destroyed" << std::endl;
    }
};

int main()
{
    hashmap h;
    h.put(1, 2);
    h.put(2, 3);
    std::cout << h.get(1) << std::endl;
    std::cout << h.get(2) << std::endl;
    h.remove(1);
    std::cout << h.get(1) << std::endl;
    return 0;
}