
class LRUCache {
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;

    }
    
    int get(int key) {
        list<int>::iterator lit = find(caches.begin(),caches.end(),key);
        if(lit == caches.end())
        	return -1;
        else
        {
        	int value = pairOfkeyValue[key];
        	caches.push_front(key);
        	caches.erase(lit);
        	return value;
        }
    }
    
    void put(int key, int value) {
    	list<int>::iterator lit = find(caches.begin(),caches.end(),key);
    	if(lit == caches.end())
    	{
        	if(size == capacity)
        	{
        		caches.pop_back();
        	}
        	else
        	{
        		size++;
        	}
        	caches.push_front(key);
        	pairOfkeyValue[key] = value;
        }
        else
        {
        	caches.erase(lit);
        	pairOfkeyValue.erase(key);
        	pairOfkeyValue[key] = value;
        	caches.push_front(key);
        }
    }

private:
	int capacity;
	int size;
	unordered_map<int,int> pairOfkeyValue;
	list<int> caches;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
