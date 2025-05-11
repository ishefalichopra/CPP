#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    struct Node
    {
        Node *next;
        Node *prev;
        int val;
        int key;
        Node(int key, int val)
        {
            this->val = val;
            this->key = key;
            next = nullptr;
            prev = nullptr;
        }
    };
    int capacity;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;

    void deleteNode(Node *node)
    {
        Node *beforeNode = node->prev;
        Node *afterNode = node->next;
        beforeNode->next = afterNode;
        afterNode->prev = beforeNode;
    }

    void insertAfterHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *node = tail->prev;
                deleteNode(node);
                mp.erase(node->key);
                delete node;
            }
            Node *newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }
    int main()
    {
        int n;
        cin >> n;
        LRUCache *lru = new LRUCache(n);
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int key, value;
                cin >> key >> value;
                lru->put(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << lru->get(key) << endl;
            }
        }
        delete lru;
        lru = nullptr;
    }
    // Destructor to clean up the linked list
    ~LRUCache()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        current = tail;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        mp.clear();
    }
    
    