//
//  main.cpp
//  Lintcode-134
//
//  Created by Jing LUO on 14/7/19.
//  Copyright © 2019 Jing LUO. All rights reserved.
//

#include <iostream>
#include <map>

class DoubleLinkedList {
public:
    int key;
    int val;
    DoubleLinkedList *prev;
    DoubleLinkedList *next;
    DoubleLinkedList(int key, int val) {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

std::map<int, DoubleLinkedList*> hashTable;
DoubleLinkedList *head;
DoubleLinkedList *tail;
int capa = 0;
int currentNodes = 0;

void removeFromHead() {
    DoubleLinkedList *first = head->next;
    DoubleLinkedList *secod = first->next;
    head->next = secod;
    secod->prev = head;
    hashTable.erase(first->key);  // don't forget to remove from HashTable
    hashTable[secod->key] = secod;
}

void removeNode(DoubleLinkedList *node) {
    DoubleLinkedList *prev = node->prev;
    DoubleLinkedList *next = node->next;
    prev->next = next;
    next->prev = prev;
}

void insertToTail(int key, int value) {
    DoubleLinkedList *newLast = new DoubleLinkedList(key, value);
    if (currentNodes == 1) { // if only one node, deal with head and tail
        head->next = newLast;
        tail->prev = newLast;
        newLast->prev = head;
        newLast->next = tail;
        hashTable[key] = newLast;
        return;
    }
    DoubleLinkedList *last = tail->prev;
    last->next = newLast;
    tail->prev = newLast;
    newLast->prev = last;
    newLast->next = tail;
    hashTable[key] = newLast;
}

/*
 * @param capacity: An integer
 */
void LRUCache(int capacity) {
     // do intialization if necessary
    head = new DoubleLinkedList(-1, -1);  // create dummy head
    tail = new DoubleLinkedList(-1, -1);  // create dummy tail
    head->next = tail;
    tail->prev = head;
    capa = capacity;
    currentNodes = 0;
    hashTable.clear();
 }

/*
 * @param key: An integer
 * @return: An integer
 */
int get(int key) {
    if (hashTable.find(key) == hashTable.end()) { // if not found, return -1
        return -1;
    }
    // otherwise, move to tail and return the value
    DoubleLinkedList *curr = hashTable[key];
    removeNode(curr);
    insertToTail(curr->key, curr->val);
    return curr->val;
}

/*
 * @param key: An integer
 * @param value: An integer
 * @return: nothing
 */
void set(int key, int value) {
    if (hashTable.find(key) == hashTable.end()) {  // if not found
        currentNodes ++;
        insertToTail(key, value);  // insert to tail
        if (currentNodes > capa) {  // if over the capacity, move the head->next one, which is least recent use
            currentNodes --;
            removeFromHead();
        }
        return;
    }
    // if found, move to tail
    hashTable[key]->val = value;
    removeNode(hashTable[key]);
    insertToTail(key, value);
}

int main(int argc, const char * argv[]) {
    LRUCache(4);
    set(2, 1);
    set(1, 1);
    set(3, 1);
    std::cout << get(2) << "\n";
    set(4, 1);
    std::cout << get(1) << "\n";
    set(5, 1);
    set(4, 1);
    std::cout << get(3) << "\n";
    std::cout << get(1) << "\n";
    std::cout << get(5) << "\n";
    return 0;
}
