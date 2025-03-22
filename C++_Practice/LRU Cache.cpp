#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* oldNode) {
        Node* prevN = oldNode->prev;
        Node* nextN = oldNode->next;
        prevN->next = nextN;
        nextN->prev = prevN;
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* resN = mpp[key];
            int res = resN->val;
            mpp.erase(key);
            deleteNode(resN);
            addNode(resN);

            mpp[key] = head->next; // Update the map reference
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* existingN=mpp[key];
            mpp.erase(key);
            deleteNode(existingN);
        }
        if(mpp.size()==cap)
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key]=head->next;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        cout << "Done";
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    cout<<"LRU Cache:\n";
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << "\n"; 
    obj->put(3, 3); 
    cout << obj->get(2) << "\n"; 
    obj->put(4, 4); 
    cout << obj->get(1) << "\n"; 
    cout << obj->get(3) << "\n";
    cout << obj->get(4) << "\n";
    
    delete obj;
    return 0;
}