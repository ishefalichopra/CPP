#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure for doubly linked list
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache class
class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;  // Key to node mapping
    Node* head;  // Most recently used
    Node* tail;  // Least recently used
    
    // Function to remove a node from the doubly linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        
        if (prevNode != nullptr) {
            prevNode->next = nextNode;
        } else {
            head = nextNode;  // Update head if we are removing the first node
        }
        
        if (nextNode != nullptr) {
            nextNode->prev = prevNode;
        } else {
            tail = prevNode;  // Update tail if we are removing the last node
        }
    }
    
    // Function to insert a node at the front (most recently used)
    void insertAtFront(Node* node) {
        node->next = head;
        node->prev = nullptr;
        
        if (head != nullptr) {
            head->prev = node;
        }
        head = node;
        
        if (tail == nullptr) {
            tail = node;  // If list was empty, set both head and tail to the new node
        }
    }

public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}
    
    // Get the value of a key
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }
        
        // Move the accessed node to the front (most recently used)
        Node* node = cache[key];
        removeNode(node);  // Remove it from its current position
        insertAtFront(node);  // Insert it at the front
        
        return node->value;
    }
    
    // Put a key-value pair in the cache
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If key already exists, update the value and move it to the front
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertAtFront(node);
        } else {
            // If key does not exist, insert new key-value pair
            if (cache.size() == capacity) {
                // Cache is full, remove the least recently used (tail)
                cache.erase(tail->key);  // Remove from hash map
                removeNode(tail);  // Remove from list
            }
            
            // Insert new node at the front
            Node* newNode = new Node(key, value);
            insertAtFront(newNode);
            cache[key] = newNode;  // Insert into hash map
        }
    }
    
    // Destructor to clean up memory
    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Example usage:
int main() {
    LRUCache lruCache(2);  // Cache capacity of 2
    
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl;  // Returns 1
    lruCache.put(3, 3);  // Removes key 2 and inserts key 3
    cout << lruCache.get(2) << endl;  // Returns -1 (not found)
    lruCache.put(4, 4);  // Removes key 1 and inserts key 4
    cout << lruCache.get(1) << endl;  // Returns -1 (not found)
    cout << lruCache.get(3) << endl;  // Returns 3
    cout << lruCache.get(4) << endl;  // Returns 4
    
    return 0;
}



