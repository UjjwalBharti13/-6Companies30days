class LRUCache {
public:
   // Appraoch
   // for get we can use a map that store the value and the value is in map then return the map of key 
   // so we can use a doubly linklist that can use like LRU like if we recently use the key then we simply pu it on front of doubly linklist
   // now for traversing the doubly linkedlist we can make a map that sotre the int and addressr of list iterator and we can directly erase that and add them to in front of doubly linkedlist
   // for PUT
   // if we find the key in map then we remove the val and decrese size
   // if we have ti inset value then simply we can add to front of the list
   // we capacity get full then we remove LRU which is at the last of doubly linked list
    
      map<int,int> mp;
      map<int,list<int>::iterator> address;
      list<int> dll; // making Doubly LinkedList
      int cap;
      int sz;

    LRUCache(int capacity) {
         
         cap =capacity;
         sz=0;

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
             return -1;
        }
          list<int>::iterator it = address[key];
          dll.erase(it);
          address.erase(key);
          dll.push_front(key);
          address[key]=dll.begin();
          return mp[key];
    }
    
    void put(int key, int value) {
          if(mp.find(key)!=mp.end()){
               dll.erase(address[key]);
               address.erase(key);
               mp.erase(key);
                sz--;
          }
          if(sz==cap){
               int k = dll.back();
               dll.pop_back();
               mp.erase(k);
               address.erase(k);
               sz--;

          }
           // if we adding 
            sz++;
            dll.push_front(key);
            address[key]=dll.begin();
            mp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
