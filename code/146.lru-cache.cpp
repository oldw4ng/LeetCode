/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (26.48%)
 * Likes:    3351
 * Dislikes: 124
 * Total Accepted:    331.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 * 
 * 
 */
struct Node {
    int key;
    int val;
    Node* pre;
    Node* next;
    Node():key(0), val(0), pre(this), next(this){}
    Node(int k, int v):key(k), val(v), pre(nullptr), next(nullptr){}
};


class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;

    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node();
    }

    void headInsert(Node* node) {
        node -> next = head -> next;
        node -> pre = head;
        node -> next -> pre = node;
        head -> next = node;
    }

    void removeNode(Node* node) {
        node -> pre -> next = node -> next;
        node -> next -> pre = node -> pre;
    }

    int get(int key) {
        if (cache.count(key)) {
            auto node = cache[key];
            if (node -> pre != head) {
                removeNode(node);
                headInsert(node);
            }
            return node -> val;
        } else
            return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            auto node = cache[key];
            node->val = value;
            if (node->pre != head) {
                removeNode(node);
                headInsert(node);
            }
            return;
        }
        if (cache.size() == capacity) {
            auto k = head -> pre -> key;
            removeNode(head -> pre);
            cache.erase(k);
        }
        auto node = new Node(key, value);
        cache[key] = node;
        headInsert(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

