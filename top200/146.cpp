#include <iostream>
#include <unordered_map>
using namespace std;
//可改进的地方很多
struct node{
    int key;
    int value;
    node* pre;
    node* next;
    node(): key(0), value(0), pre(nullptr), next(nullptr){}
    node(int key, int value): key(key), value(value), pre(nullptr), next(nullptr){}
    node(int key, int value, node* pre, node* next): key(key), value(value), pre(pre), next(next){}
};

class LRUCache {
public:
    int Capacity;
    unordered_map<int ,node*> map;
    node* Head;
    node* Tail;
    LRUCache(int capacity) {
        Capacity = capacity;
        Head = nullptr;
        Tail = nullptr;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }else{
            moveNode(map[key]);
            return map[key]->value;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            moveNode(map[key]);
            map[key]->value = value;
        }else{
            addNode(key, value);
            if(map.size() > Capacity){
                removeNode();
            }
        }
    }

    void moveNode(node* temp){     
        if(Tail == temp){
            return;
        }else if(Head == temp){
            if(Head->next == nullptr){
                return;
            }
            node* newHead = Head->next;
            newHead->pre = nullptr;
            Head->next = nullptr;
            Head->pre = Tail;
            Tail->next = Head;
            Tail = Head;
            Head = newHead;
        }else{
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            Tail->next = temp;
            temp->pre = Tail;
            temp->next = nullptr;
            Tail = temp;
        }
        return;
    }

    void addNode(int key, int value){
        if(Head == nullptr){
            Head = new node(key, value, nullptr, nullptr);
            Tail = Head;
        }else{
            node* newTail = new node(key, value, Tail, nullptr);
            Tail->next = newTail;
            Tail = newTail;
        }
        map[key] = Tail;
    }

    void removeNode(){
        node* newHead = Head->next;
        newHead->pre = nullptr;
        Head->next = nullptr;
        map.erase(Head->key);
        delete(Head);
        Head = newHead;
    }
};